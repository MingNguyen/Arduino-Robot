#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"


class Ultrasonic
{
  public:
    Ultrasonic(int trigPin, int echoPin);
    int getEcho();
    int getTrig();
    int getStartTime();
    void setStartTime(int start);
    int distance(int start);
    void print_distance() ;
  private:
    int _echoPin, _trigPin, _start;
};

#endif
