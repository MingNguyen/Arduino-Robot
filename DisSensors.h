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
    int[4] _allDis = {0,0,0,0}; // FL, FR, BL, BR

    int setFR(int trigPin, int echoPin);
    int setFL(int trigPin, int echoPin);
    int setBR(int trigPin, int echoPin);
    int setBL(int trigPin, int echoPin);

    int getAllDis(Ultrasonic FR, Ultrasonic FL, Ultrasonic BR, Ultrasonic BL);


};