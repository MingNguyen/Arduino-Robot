#include "Arduino.h"
#include "DisSensors.h"

DisSensors::DisSensors() {}

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
    int now = millis();
    disFR = _FR.distance(now);
    disFL = _FL.distance(now);
    disBR = _BR.distance(now);
    disBL = _BL.distance(now);
}

void DisSensors::printDis(){
    DisSensors::getAllDis();
    Serial.print("FL: ");
    Serial.println(disFL);
    Serial.print("FR: ");
    Serial.println(disFR);
    Serial.print("BL: ");
    Serial.println(disBL);
    Serial.print("BR: ");
    Serial.println(disBR);
}




