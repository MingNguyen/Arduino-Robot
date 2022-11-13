#include "Arduino.h"
#include "DisSensors.h"

DisSensors::DisSensors() {
    objFL = false;
    objFR = false;
    objBL = false;
    objBR = false;
    start = millis();
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

            if (millis()-start >= timer){
                digitalWrite(trigPin, LOW);
                start = millis();
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
            if (millis()-start >= timer){
                digitalWrite(trigPin, LOW);
                start = millis();
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
            if (millis()-start >= timer){
                digitalWrite(trigPin, LOW);
                start = millis();
                _disBL = pulseIn(echoPin_BL, HIGH) * 0.034 /2;
                temp = 7;
            }
            break;

        // back right
        case 7:
            digitalWrite(trigPin, HIGH);
            temp=8;
            break;
        case 8:
            if (millis()-start >= timer){
                digitalWrite(trigPin, LOW);
                start = millis();
                _disBR = pulseIn(echoPin_BR, HIGH) * 0.034 /2;
                temp = 1;
            }
            break;
    }
}

void DisSensors::getAllDis() {
  switch (temp){
    case 0:
      if(_FR.average_dis() != -1){
        _disFR = _FR.average_dis();
        temp = 1;
      }
      else{
        break;
      }

    case 1:
      if(_FL.average_dis() != -1){
        _disFL = _FL.average_dis();
        temp = 2;
      }
      else{
        break;
      }

    case 2:
      if(_BL.average_dis() != -1){
        _disBL = _BL.average_dis();
        temp = 3;
      }
      else{
        break;
      }

    case 3:
      if(_BR.average_dis() != -1){
        _disBR = _BR.average_dis();
        temp = 0;
      }
      else{
        break;
      }
  }
}

void DisSensors::detect_obj() {
    DisSensors::getAllDis();
    if(_FR.detect_obj()){
        objFL = true;
    } else objFL = false;

    if(_FL.detect_obj()){
        objFR = true;
    } else objFR = false;

    if(_BR.detect_obj()){
        objBL = true;
    } else objBL = false;

    if(_BL.detect_obj()){
        objBR = true;
    } else objBR = false;
}

void DisSensors::printDis(){
    DisSensors::getAllDis4();
    Serial.print("FL: ");
    Serial.println(_disFL);
    Serial.print("FR: ");
    Serial.println(_disFR);
    Serial.print("BL: ");
    Serial.println(_disBL);
    Serial.print("BR: ");
    Serial.println(_disBR);
}
