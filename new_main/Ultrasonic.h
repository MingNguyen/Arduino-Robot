#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"


class Ultrasonic
{
  public:
    Ultrasonic();
    Ultrasonic(int trigPin, int echoPin);
    int getStartTime();
    void setStartTime(int start);
    int distance(int now);
    int average_dis();
    bool detect_obj();
    void print_distance();
  private:
    int _echoPin, _trigPin, _start, _distance;
    int _average_dis;
};

#endif
