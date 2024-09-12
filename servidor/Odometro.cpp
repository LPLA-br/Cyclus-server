/*
  Biblioteca para aferição de odometria.
*/
#include "Odometro.hpp"

void incrementarDistancia( int numeroRotacoes, const int PERIMETRO_CIRCULAR, int* distancia )
{
  *(distancia) = numeroRotacoes * PERIMETRO_CIRCULAR;
}

