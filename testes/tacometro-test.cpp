#include <cstdio>
#include <chrono>
//#include "./Tacometro.hpp" depende de: WProgram.h or Arduino.h

#define MINUTO 60000
#define PERIMETRO 2

#define HIGH 1
#define LOW  0

//#################MOCKS
auto inicio = std::chrono::high_resolution_clock::now();

bool fakePin = false;

int millis()
{
  auto agora = std::chrono::high_resolution_clock::now();
  auto intervalo = std::chrono::duration_cast<std::chrono::milliseconds>(agora - inicio);
  return (intervalo.count());
}

bool digitalRead( bool* fakePin )
{
  if ( *(fakePin) == true )
    return true;
  else
    return false;
}
//#################MOCKS
// TRANSCRIÇÃO 10/9/2024

float obterRpm( int duracaoRotacao )
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
//

void obterRpmTEST()
{
  printf("float obterRpm( int duracaoRotacao );\n");

  int millisegundos = 1000;
  printf("%i milliseconds deve retornar rpm aproximado de %f. resultou em %f\n",
      millisegundos, 60.0, obterRpm( millisegundos ) );

  printf("\n\n");
}

void quilometroPorHoraTEST()
{
  printf("float quilometroPorHora( const int PERIMETRO_CIRCULAR_PNEU, int rpm );\n");

  int rpm = 60; //retorno fake de obterRpm();
  int perimetroPneu = 2; //metros
  printf("rpm de %i e perimetroPneu de %i. velocidade deve ser proximo de: %fkm/h. resultou em: %fk/m\n",
      rpm, perimetroPneu, 7.0, quilometroPorHora( perimetroPneu, rpm ));

  printf("\n\n");
}

void medirTempoEntreDoisPulsosTEST()
{
  /*C++ -> threads são bloqueantes (wtf)
    ¯\_(o_o)_/¯ automatizado -> manual
  */
}

int main(int argc, char *argv[])
{
  obterRpmTEST();
  quilometroPorHoraTEST();
  medirTempoEntreDoisPulsosTEST();
	return 0;
}
