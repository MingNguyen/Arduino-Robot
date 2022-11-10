#ifndef DisSensors_h
#define DisSensors_h

#include "Arduino.h"
#include "Ultrasonic.h"

class DisSensors{
private:
    int trigPin;
    int echoPin_FR, echoPin_FL, echoPin_BR, echoPin_BL;

public:
    Ultrasonic _FR;
    Ultrasonic _FL;
    Ultrasonic _BR;
    Ultrasonic _BL;

    int disFL, disFR, disBL, disBR;

    DisSensors();
    int setFR(int trigPin, int echoPin);
    int setFL(int trigPin, int echoPin);
    int setBR(int trigPin, int echoPin);
    int setBL(int trigPin, int echoPin);

    void getAllDis();
};

#endif

