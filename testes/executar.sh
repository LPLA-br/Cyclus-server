#!/bin/sh

#COMPILAÇÃO DOS TESTES
/bin/g++ ./bits-test.cpp ./Bits.cpp -o bits-test;
/bin/g++ ./millis-test.cpp -o millis-test;
/bin/g++ ./odometro-test.cpp ./Odometro.cpp -o odometro-test;
/bin/g++ ./tacometro-test.cpp -o tacometro-test;
#EXECUÇÃO DOS TESTES
echo -e "\n###################BITS.HPP###################\n"
./bits-test;
echo -e "\n#####################MILLIS.HPP#################\n"
./millis-test;
echo -e "\n##################ODOMETRO.HPP####################\n"
./odometro-test
echo -e "\n##################TACOMETRO.HPP####################\n"
./tacometro-test
#REMOÇÃO DOS TESTES
rm bits-test millis-test odometro-test tacometro-test;
