#include "Arduino.h"
#include "DisSensors.h"

DisSensors::DisSensors(){
    _FL = Ultrasonic();
    _FR = Ultrasonic();
    _BL = Ultrasonic();
    _BR = Ultrasonic();
}

int DisSensors::setFL(int trigPin, int echoPin) {
    _FL = Ultrasonic(trigPin, echoPin);
}

int DisSensors::setFR(int trigPin, int echoPin) {
    _FR = Ultrasonic(trigPin, echoPin);
}

int DisSensors::setBL(int trigPin, int echoPin) {
    _BL = Ultrasonic(trigPin, echoPin);
}

int DisSensors::setBR(int trigPin, int echoPin) {
    _BR = Ultrasonic(trigPin, echoPin);
}

int* DisSensors::getAllDis() {
    unsigned long now = millis();
    int disFR = _FR.distance();
    int disFL = _FL.distance();
    int disBR = _BR.distance();
    int disBL = _BL.distance();
    if (disFL != -1){
        _allDis[0] = disFL;
    }
    if (disFR != -1) {
        _allDis[1] = disFR;
    }
    if (disBL != -1) {
        _allDis[2] = disBL;
    }
    if (disBR != -1){
        _allDis[3] = disBR;
    }

    return _allDis;
}




