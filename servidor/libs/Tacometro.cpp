/******************************************************
 * Tacometro
 * LPLA-br 
 * Dependências:
 * https://github.com/ErickSimoes/Ultrasonic
 ******************************************************/

#include <cstdint>
#include "Tacometro.hpp"

//DEPENDÊNCIAS EXTERNAS:
#include "./externo/Ultrasonic.h"

#define MINUTO 60000 //ms

Tacometro::Tacometro(
    uint16_t diametroPneu, int16_t distanciaPulso,
    const uint8_t GATILHO, uint8_t ECO
): tempoInicial(0), tempoFinal(1)
{
  this->ultrasonico = new Ultrasonic( GATILHO, ECO );
  this->diametroPneu = diametroPneu;
  this->distanciaPulso = distanciaPulso;
}

/* inicia leitura de tempo bloqueante */
void Tacometro::ler( uint16_t* variavelAlvo )
{
  while( true )
  {
    if( this->ultrasonico->read( CM ) <= this->distanciaPulso )
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
  while( this->ultrasonico->read( CM ) > this->distanciaPulso )
  {
    continue;
  }
  this->ler( &this->tempoFinal );
}

void Tacometro::obterTimestampsEntreDuasLeituras()
{
  if( this->ultrasonico->read( CM ) <= this->distanciaPulso )
  {
    this->ler( &this->tempoInicial );
    this->lerFinal();
  }
}

uint16_t Tacometro::obterRpm()
{
  uint16_t duracaoRotacao = this->tempoFinal - this->tempoInicial;
  return ( MINUTO / duracaoRotacao );
}

/* Considera que há distância x > 0 cm para teste.
 * Determina acessibilidade do recurso.
 * */
bool Tacometro::testarSensor()
{
  if ( this->ultrasonico->read( CM ) == 0 )
    return false;
  else return true;
}

