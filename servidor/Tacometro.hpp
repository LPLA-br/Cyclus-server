#ifndef TACOMETRO_HPP_INCLUDED
#define TACOMETRO_HPP_INCLUDED

#define LEITOR 4
#define MINUTO 60000


int medirTempoEntreDoisPulsos();
float obterRpm( int duracaoRotacao );
float quilometroPorHora( const int PERIMETRO_CIRCULAR_PNEU, int rpm );

#endif // TACOMETRO_HPP_INCLUDED
