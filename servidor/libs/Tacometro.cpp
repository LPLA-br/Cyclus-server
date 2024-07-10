/******************************************************
 * Tacometro
 * Contém código não testado para módulo responsável
 * pela obtenção de velocidade.
 * LPLA-br 
 * Dependências:
 * https://github.com/ErickSimoes/Ultrasonic
 * Injeção: Ondometro
 ******************************************************/

#include <cstdint>

#include "Tacometro.hpp"
#include <Ultrasonic.h>

#define MINUTO 60000 //ms

Tacometro::Tacometro(
    uint16_t diametroPneu, int16_t distanciaPulso,
    const uint8_t GATILHO, uint8_t ECO
): tempoInicial(1), tempoFinal(1)
{
  this->ultrasonico = new Ultrasonic( GATILHO, ECO );
  this->diametroPneu = diametroPneu;
  this->distanciaPulso = distanciaPulso;
}

void Tacometro::ler( uint16_t* variavelAlvo )
{
  while( true )
  {
    if( this->ultrasonico.read(CM) <= this->distanciaPulso )
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

void  Tacometro::lerFinal()
{
  while( this->ultrasonico->read(CM) > this->distanciaPulso )
  {
    continue;
  }
  this->ler( this->tempoFinal );
}

void Tacometro::obterTimestampsEntreDuasLeituras()
{
  if( this->ultrasonico->read(CM) <= this->distanciaPulso )
  {
    this->ler( this->tempoInicial );
    this->lerFinal();
  }
}

uint16_t Tacometro::obterRpm()
{
  uint16_t duracaoRotacao = this->tempoFinal - this->tempoInicial;
  return ( MINUTO / duracaoRotacao );
}

