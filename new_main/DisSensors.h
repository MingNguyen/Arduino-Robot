#ifndef DisSensors_h
#define DisSensors_h

#include "Arduino.h"
#include "Ultrasonic.h"

class DisSensors{
private:
    int trigPin;
    int echoPin_FR, echoPin_FL, echoPin_BR, echoPin_BL;
    Ultrasonic _FR;
    Ultrasonic _FL;
    Ultrasonic _BR;
    Ultrasonic _BL;
    

public:
    
    int disFR, disFL, disBR, disBL;
    int _allDis[4] = {0, 0, 0, 0}; // FL, FR, BL, BR

    DisSensors();

    int setFR(int trigPin, int echoPin);
    int setFL(int trigPin, int echoPin);
    int setBR(int trigPin, int echoPin);
    int setBL(int trigPin, int echoPin);

    int* getAllDis();


};
#endif