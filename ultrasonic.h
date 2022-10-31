#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"


class Ultrasonic
{
  public:
    Ultrasonic(int echoPin, int trigPin);
    int distance();
    void print_l() ;
  private:
    int _echoPin, _trigPin;
};

#endif
