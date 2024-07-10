#include <cstdint>
#include "Odometro.h"

Odometro::Odometro(): metros(0)
{}

void Odometro::atualizar( float distanciaNaRotacao )
{
  this->metros += distanciaNaRotacao;
}

