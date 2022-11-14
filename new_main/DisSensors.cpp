#include "Arduino.h"
#include "DisSensors.h"

DisSensors::DisSensors() {
    objFL = false;
    objFR = false;
    objBL = false;
    objBR = false;
    _start = millis();
    temp = 1;
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

void DisSensors::getAllDis4() {
    int timer = 10;
    switch (temp){
        // front left
        case 1:
            digitalWrite(trigPin, HIGH);
            temp=2;
            break;
        case 2:

            if (millis()-_start >= timer){
                digitalWrite(trigPin, LOW);
                _start = millis();
                _disFL = pulseIn(echoPin_FL, HIGH) * 0.034 /2;
                temp = 3;
            }
            break;

        // front right
        case 3:
            digitalWrite(trigPin, HIGH);
            temp=4;
            break;
        case 4:
            if (millis()-_start >= timer){
                digitalWrite(trigPin, LOW);
                _start = millis();
                _disFR = pulseIn(echoPin_FR, HIGH) * 0.034 /2;
                temp = 5;
            }
            break;

        // back left
        case 5:
            digitalWrite(trigPin, HIGH);
            temp=6;
            break;
        case 6:
            if (millis()-_start >= timer){
                digitalWrite(trigPin, LOW);
                _start = millis();
                _disBL = pulseIn(echoPin_BL, HIGH) * 0.034 /2;
                temp = 7;
            }
            break;

        // back right
        case 7:
            digitalWrite(trigPin, HIGH);
            temp = 8;
            break;
        case 8:
            if (millis()-_start >= timer){
                digitalWrite(trigPin, LOW);
                _start = millis();
                _disBR = pulseIn(echoPin_BR, HIGH) * 0.034 /2;
                temp = 1;
            }
            break;
    }
}


void DisSensors::detect_obj() {
    objFL = _FL.detect_obj();
    _disFL = _FL._average_dis;
    
    objFR = _FR.detect_obj();
    _disFR = _FR._average_dis;

    objBL = _BL.detect_obj();
    _disBL = _BL._average_dis;

    objBR = _BR.detect_obj();
    _disBR = _BR._average_dis;

    
    DisSensors::printDis();
}

void DisSensors::printDis(){
    Serial.print("FL: ");
    Serial.println(_FL._average_dis);
    Serial.print("FR: ");
    Serial.println(_FR._average_dis);
    Serial.print("BL: ");
    Serial.println(_BL._average_dis);
    Serial.print("BR: ");
    Serial.println(_BR._average_dis);
}
