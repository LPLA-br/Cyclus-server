#ifndef TACOMETRO_HPP_INCLUDED
#define TACOMETRO_HPP_INCLUDED

#include <cstdint>
#include <Ultrasonic.h>

class Tacometro
{
  private:

  protected:
    Ultrasonic ultrasonico;
   
    float diametroPneu;
    float distanciaPulso;

    uint16_t tempoInicial;
    uint16_t tempoFinal;

    void ler();
    void lerFinal();
    void obterTimestampsEntreDuasLeituras();

  public:
    Tacometro( uint16_t diametroPneu, int16_t distanciaPulso );
    uint16_t obterRpm();
};

#endif // TACOMETRO_HPP_INCLUDED
