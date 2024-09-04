#include <stdio.h>
#include <stdint.h>

/* teste unitário caixa preta da biblioteca de manipulação de bits */
#include "../servidor/Bits.hpp"


void lerBitTEST()
{
  uint8_t a;
  a = 0b00000001;

  printf("uint8_t lerBit( uint8_t* alvo, uint8_t mascaraUmBitPositivo );\n");

  printf("Avaliar bit 1 de %x. deve retornar: 1. retorno: %x \n", a, lerBit( &a, 0b00000001 ));
  printf("Avaliar bit 2 de %x. deve retornar: 0. retorno:%x \n",  a,lerBit( &a, 0b00000010 ));

  printf("\n\n");
}


void manipulacaoBitsTEST()
{
  uint8_t a;
  a = 0b00000000;

  printf("void definirBit( uint8_t* alvo, uint8_t mascaraNegativa );\n");
  printf("void desdefinirBit( uint8_t* alvo, uint8_t mascaraPositiva );\n");

  definirBit( &a, 0b10000000 );
  printf("Avaliar bit MSB. deve resultar em: %x. resultado: %x \n", 0b10000000, a);

  desdefinirBit( &a, 0b01111111 );
  printf("Avaliar bit MSB. deve resultar em: %x. resultado: %x \n", 0b00000000, a);

  printf("\n\n");
}


int main(int argc, char *argv[])
{
  lerBitTEST();
  manipulacaoBitsTEST();
	return 0;
}
