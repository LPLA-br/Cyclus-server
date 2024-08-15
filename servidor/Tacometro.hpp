#ifndef TACOMETRO_HPP_INCLUDED
#define TACOMETRO_HPP_INCLUDED

#include <cstdint>
#include "Ultrasonic.hpp"

class Tacometro
{
  private:

  protected:
    Ultrasonic* ultrasonico;
   
    float diametroPneu;
    float distanciaPulso; // gatilho de leitura

    uint16_t tempoInicial;
    uint16_t tempoFinal;

    void ler( uint16_t* variavelAlvo );
    void lerFinal();
    void obterTimestampsEntreDuasLeituras();

  public:
    Tacometro( uint16_t diametroPneu, int16_t distanciaPulso, uint8_t GATILHO, uint8_t ECO );

    uint16_t obterRpm();
    uint16_t getLeituraMilisegundos();
};

#endif // TACOMETRO_HPP_INCLUDED
