#include <stdio.h>
#include <stdint.h>

/* teste da biblioteca de manipulação de bits */

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

int main(int argc, char *argv[])
{
  uint8_t a, b;
  a = 0b00000001;
  b = 0b01000001;
  printf("mantenha o código fonte ao lado para teste caixa branca.\n");
  printf( "Bit avaliado é um. Retorna zero! %i\n", lerBit( &a, 0b00000001 ));//1
  printf( "Bit avaliado é zero. Retorna zero!%i\n", lerBit( &a, 0b00000010 ));//0
  printf( "Bit avaliado é um. Descarta-se outros bits!%i\n", lerBit( &b, 0b00000001 ));//1
	return 0;
}
