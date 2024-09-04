#include <cstdio>
#include <chrono>

#define MINUTO 600000
#define PERIMETRO 2

#define HIGH 1
#define LOW  0

/* teste unitário caixa preta:
 *    medirTempoEntreDoisPulsos();
 *
 * teste integracao caixa preta:
 * quilometroPorHora(2,obterRpm());
 * */


//#################MOCKS
//
auto inicio = std::chrono::high_resolution_clock::now();

clock_t millisegundoInicial = clock(); //inicio da execução do programa.

bool fakePin = false;

int8_t millis()
{
  auto tempoCorrente = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(tempoCorrente - inicio);
  return (elapsed.count());
}

bool digitalRead( bool* fakePin )
{
  if ( *(fakePin) == true )
    return true;
  else
    return false;
}
//#################MOCKS

//########## TRANSCRIÇÃO 3/9/2024 ##############
// Tacometro.hpp

float quilometroPorHora( const int PERIMETRO_CIRCULAR_PNEU, int rpm )
{
  if ( rpm == 0.1 )
    return 0.0;
  else
    return (((PERIMETRO_CIRCULAR_PNEU * rpm) * 60) / 1000);
}

float obterRpm( int duracaoRotacao )
{
  if ( duracaoRotacao > 10 )
  {
    return (MINUTO / duracaoRotacao);
  }
  else return 0.1;
}

/* deve ser executada em thread paralela*/
int medirTempoEntreDoisPulsos()
{
  int inicio = millis();
  while ( true )
  {
    if ( digitalRead( &fakePin ) == HIGH )
    {
      return (millis() - inicio);
    }
    else continue;
  }
}

//########## TRANSCRIÇÃO ##############


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
  printf("rpm de %i e perimetroPneu de %i. retorno deve ser proximo de: %fm/m. resultou em: %fm/m\n",
      rpm, perimetroPneu, 120.0, quilometroPorHora( perimetroPneu, rpm ));

  printf("\n\n");
}

void medirTempoEntreDoisPulsosTEST()
{

}

int main(int argc, char *argv[])
{
  obterRpmTEST();
  quilometroPorHoraTEST();
  medirTempoEntreDoisPulsosTEST();
	return 0;
}
