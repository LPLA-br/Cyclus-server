#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Ultrasonic.hpp"

Ultrasonic::Ultrasonic(): duration(0), distance(0), trigPin(4), echoPin(5)
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float Ultrasonic::obterDistanciaCM()
{
  digitalWrite( this->trigPin, LOW );
  delayMicroseconds(2);
  digitalWrite( this->trigPin, HIGH );
  delayMicroseconds(10);
  digitalWrite( this->trigPin, LOW );

  this->duration = pulseIn( this->echoPin, HIGH );
  this->distance = (this->duration*.0343)/2;
  delay(100);
  return this->distance;
}

