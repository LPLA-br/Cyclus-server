/******************************************************
 * Tacometro
 * LPLA-br 
 * Dependências:
 * https://github.com/ErickSimoes/Ultrasonic
 ******************************************************/

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include <cstdint>
#include "Tacometro.hpp"

//DEPENDÊNCIAS EXTERNAS:
#include "Ultrasonic.h"

#define MINUTO 60000 //ms

Tacometro::Tacometro(
    uint16_t diametroPneu, int16_t distanciaPulso,
    const uint8_t gatilho, const uint8_t eco
): tempoInicial(0), tempoFinal(1)
{
  this->ultrasonico = new Ultrasonic();
  this->diametroPneu = diametroPneu;
  this->distanciaPulso = distanciaPulso;
}

/* inicia leitura de tempo bloqueante */
void Tacometro::ler( uint16_t* variavelAlvo )
{
  while( true )
  {
    if( this->ultrasonico->obterDistanciaCM() <= this->distanciaPulso )
    {
      continue;
    }
    else
    {
      *variavelAlvo = millis();
      break;
    }
  }
}

/* encerra leitura de tempo bloqueante */
void  Tacometro::lerFinal()
{
  while( this->ultrasonico->obterDistanciaCM() > this->distanciaPulso )
  {
    continue;
  }
  this->ler( &this->tempoFinal );
}

void Tacometro::obterTimestampsEntreDuasLeituras()
{
  if( this->ultrasonico->obterDistanciaCM() <= this->distanciaPulso )
  {
    this->ler( &this->tempoInicial );
    this->lerFinal();
  }
}

uint16_t Tacometro::obterRpm()
{
  this->obterTimestampsEntreDuasLeituras();
  uint16_t duracaoRotacao = (this->tempoFinal - this->tempoInicial);
  if ( duracaoRotacao != 0 )
    return ( MINUTO / duracaoRotacao );
  else
    return 0;
}

uint16_t Tacometro::getLeituraMilisegundos()
{
  this->obterTimestampsEntreDuasLeituras();
  return (this->tempoFinal - this->tempoInicial);
}

