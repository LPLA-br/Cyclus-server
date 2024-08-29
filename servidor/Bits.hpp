#ifndef BITS_HPP_INCLUDED
#define BITS_HPP_INCLUDED

#include <cstdint>

void definirBit( uint8_t* alvo, uint8_t mascaraNegativa );
void desdefinirBit( uint8_t* alvo, uint8_t mascaraPositiva );
bool lerBit( uint8_t* alvo, uint8_t mascaraUmBitPositivo );

#endif // BITS_HPP_INCLUDED