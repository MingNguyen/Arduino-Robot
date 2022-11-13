#include "Arduino.h"
#include "DisSensors.h"

DisSensors::DisSensors() {
    _objFL = false;
    _objFR = false;
    _objBL = false;
    _objBR = false;
}

int DisSensors::setFL(int trigPin, int echoPin) {
    echoPin_FL = echoPin;
    _FL = Ultrasonic(trigPin, echoPin);
}

int DisSensors::setFR(int trigPin, int echoPin) {
    echoPin_FR = echoPin;
    _FR = Ultrasonic(trigPin, echoPin);
}

int DisSensors::setBL(int trigPin, int echoPin) {
    echoPin_BL = echoPin;
    _BL = Ultrasonic(trigPin, echoPin);
}

int DisSensors::setBR(int trigPin, int echoPin) {
    echoPin_BR = echoPin;
    _BR = Ultrasonic(trigPin, echoPin);
}

void DisSensors::getAllDis() {
    _disFR = _FR.average_dis();
    _disFL = _FL.average_dis();
    _disBR = _BR.average_dis();
    _disBL = _BL.average_dis();
}

void DisSensors::detect_obj() {
    DisSensors::getAllDis();
    if(_FR.detect_obj()){
        _objFL = true;
    } else _objFL = false;

    if(_FL.detect_obj()){
        _objFR = true;
    } else _objFR = false;

    if(_BR.detect_obj()){
        _objBL = true;
    } else _objBL = false;

    if(_BL.detect_obj()){
        _objBR = true;
    } else _objBR = false;
}

void DisSensors::printDis(){
    DisSensors::getAllDis();
    Serial.print("FL: ");
    Serial.println(_disFL);
    Serial.print("FR: ");
    Serial.println(_disFR);
    Serial.print("BL: ");
    Serial.println(_disBL);
    Serial.print("BR: ");
    Serial.println(_disBR);
}




