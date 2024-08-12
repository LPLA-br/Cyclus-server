#ifndef ODOMETRO_HPP_INCLUDED
#define ODOMETRO_HPP_INCLUDED

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
