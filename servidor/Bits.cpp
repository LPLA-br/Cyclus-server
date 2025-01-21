/*
biblioteca simples para manipulação
de bits em variáveis de oito bits.
Útil para sistema de flags de um bit
em variáveis de oito bits.
*/
#include "Bits.hpp"

/* usa máscara negativa (0) cujo bit alvo é marcado como um */
void definirBit( uint8_t* alvo, uint8_t mascaraNegativa )
{
  *alvo |= mascaraNegativa;
}

/* usa máscara positiva (1) cujo o bit alvo é marcado como zero */
void desdefinirBit( uint8_t* alvo, uint8_t mascaraPositiva )
{
  *alvo &= mascaraPositiva;
}

/*usa máscara com um bit positivo para ler valor daquele bit
naquela posição.*/
uint8_t lerBit( uint8_t* alvo, uint8_t mascaraUmBitPositivo )
{
  if ( (*(alvo) & mascaraUmBitPositivo) == mascaraUmBitPositivo )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
