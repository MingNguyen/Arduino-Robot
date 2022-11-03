#include "Arduino.h"
#include "DisSensors.h"

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

int* DisSensors::getAllDis(Ultrasonic FR, Ultrasonic FL, Ultrasonic BR, Ultrasonic BL) {
    int now = millis();
    int disFR = FR.distance(now);
    int disFL = FL.distance(now);
    int disBR = BR.distance(now);
    int disBL = BL.distance(now);
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




