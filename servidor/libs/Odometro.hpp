#ifndef ODOMETRO_HPP_INCLUDED
#define ODOMETRO_HPP_INCLUDED

#include <cstdint>

class Odometro
{
  private:
    unsigned long int metros;
  protected:
  public:
    Odometro();
    void atualizar( float distanciaNaRotacao );
};

#endif // ODOMETRO_HPP_INCLUDED
