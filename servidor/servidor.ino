/* 
  Servidor derivado dos exemplos presentes em:
  https://github.com/nkolban/ESP32_BLE_Arduino/blob/master/examples/

  Compilado na IDE arduino 1.8.19

  Lista de Sensores #####################################################
   HC-SR04 Sensor de distância ultra sônica (analógico) velocidade/odômetro
   LDR 5mm Sensor de Luminosidade (analógico) velocidade/odômetro
   HMC5883L Bússola Eletrônica sem fio (Comunicação serial I2C) rumo
  BMP 280 pressão e temperatura (I2C ou SPI) Altitude e condições ambientais
  MPU-6050 Acelerometro e Giroscópio (I2C) Atitude(aclives e declives)

*/

// DEPENDÊNCIAS EXTERNAS
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// DEPENDÊNCIAS NATIVAS
#include "Tacometro.hpp"
#include "Odometro.hpp"
#include "Bits.hpp"
#include "Disponibilidade.hpp"

//BLUETOOTH LE
BLEServer* servidor = NULL;
BLECharacteristic* caracteristica = NULL;

bool deviceConnected = false;
bool oldDeviceConnected = false;

//VARIÁVEIS ESPECIFICAS DO PROTOCOLO CYCLE
uint8_t status = 0b00000000; //recursos
uint16_t intervalo = 0;
uint32_t contagemRotacoes = 0;
uint16_t rumo = 0; // 0 até 360

const uint8_t TAMANHO_MAX_MSG =37;

/*Gere UUID's em: https://www.uuidgenerator.net */
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyServerCallbacks: public BLEServerCallbacks 
{
    void onConnect(BLEServer* servidor) 
    {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* servidor) 
    {
      deviceConnected = false;
    }
};

void setup() 
{
  Serial.begin(115200);
  pinMode(LEITOR,INPUT); //reservado para aferição de RPM

  BLEDevice::init("ESP32");

  servidor = BLEDevice::createServer();
  servidor->setCallbacks(new MyServerCallbacks());

  BLEService* pService = servidor->createService(SERVICE_UUID);

  caracteristica = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  caracteristica->addDescriptor(new BLE2902());

  pService->start();

  BLEAdvertising* anunciando = BLEDevice::getAdvertising(); 
  anunciando->addServiceUUID(SERVICE_UUID);
  anunciando->setScanResponse(false);
  anunciando->setMinPreferred(0x0);
  BLEDevice::startAdvertising();
  Serial.println("Aguardando cliente para notifica-lo periodicamente...");

  /*EXECUÇÃO DE FUNÇÕES DE TESTE PARA DEFINIÇÃO DA
    FLAGS DE DISPONIBILIDADE DE RECURSOS MODULARES*/
  status = 0b00000001; //temporário
}

void loop() 
{
    if (deviceConnected) 
    {
        Serial.println("device connected loop");
        String resposta( "{" );

        // Construção da resposta BLE
        if ( millis() > 5000 )
        {
          /*gambiarra: aguardar 5 segundos
          para que o BLE tenha
          tempo de anunciar suas
          características ao conectante*/

          //condicional de disponibilidade do recurso.
          if ( true )
          {
            int interval = medirTempoEntreDoisPulsos();
            if ( interval > 10 )
            {
              contagemRotacoes++;
              intervalo = interval;
            }
            resposta.concat( "i:" );
            resposta.concat( intervalo );
            resposta.concat( ",c:" ); 
            resposta.concat( contagemRotacoes );
            resposta.concat( "," );
          }
        }

        resposta.concat("s:2}");
        
        if ( resposta.length() <= TAMANHO_MAX_MSG )
        {
          caracteristica->setValue( (uint8_t*)resposta.c_str(), TAMANHO_MAX_MSG );
          caracteristica->notify();
        }
        else
        {
          caracteristica->setValue( (uint8_t*)"{s:120}", TAMANHO_MAX_MSG );
          Serial.println("erro: mensagem maior que valor definido por macro TAMANHO_MAX_MSG !");
          caracteristica->notify();
        }
    }

    if (!deviceConnected && oldDeviceConnected) 
    {
        delay(500);
        servidor->startAdvertising();
        Serial.println("desconectado. iniciando estado anunciante advertising");
        oldDeviceConnected = deviceConnected;
    }

    if (deviceConnected && !oldDeviceConnected) 
    {
        oldDeviceConnected = deviceConnected;
    }
}
