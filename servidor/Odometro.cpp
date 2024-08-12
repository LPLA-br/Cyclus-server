#include "Odometro.hpp"

Odometro::Odometro(): metros(0)
{}

void Odometro::atualizar( float distanciaNaRotacao )
{
  this->metros += distanciaNaRotacao;
}

