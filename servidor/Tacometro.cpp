/******************************************************
 * Tacometro
 * Biblioteca com funções associadas a aferição de
 * velocidade.
 ******************************************************/

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Tacometro.hpp"

/*Função bloqueante de medição de intervalo
  entre dois pontos. retorna intervalo em
  milisegundos.
*/
int medirTempoEntreDoisPulsos()
{
  int inicio = millis();
  while ( true )
  {
    if ( digitalRead(LEITOR) == HIGH )
    {
      return (millis() - inicio);
    }
    else continue;
  }
}

/*Função para obteção de rotações por minuto.
  Contém mecanismo para impedir divisão por zero.
  Servidor.ino deve impedir execução desta função
  para duracaoRotacao < 10 evitando retorno 0.1
*/
int obterRpm( int duracaoRotacao )
{
  if ( duracaoRotacao > 10 )
  {
    return (MINUTO / duracaoRotacao);
  }
  else return 0.1;
}

/* Obtém velocidade em quilometros por hora a partir do:
  perímetro externo do pneu e do rpm computado.
  DESCARTADO: Aplicação front-end terá esta responsabilidade!
 */
float quilometroPorHora( const int PERIMETRO_CIRCULAR_PNEU, int rpm )
{
  if ( rpm == 0.1 )
    return 0.0;
  else
    return (((PERIMETRO_CIRCULAR_PNEU * rpm) * 60) / 1000);
}
