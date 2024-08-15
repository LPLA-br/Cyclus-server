
#ifndef Ultrasonic_hpp
#define Ultrasonic_hpp

class Ultrasonic
{
  protected:
    int trigPin;
    int echoPin;
    float duration;
    float distance;
  public:
    Ultrasonic();
    float obterDistanciaCM();
};

#endif // Ultrasonic_hpp
