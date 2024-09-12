#include <cstdio>
#include "./Odometro.hpp"

int distancia = 0;

int main()
{
  for ( int i = 0; i<=100; i++ )
  {
    incrementarDistancia( i, 2, &distancia );
  }
  printf( "deve retornar 200 recebeu: %i", distancia );
  return 0;
}
