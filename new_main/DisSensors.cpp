#include "Arduino.h"
#include "DisSensors.h"

DisSensors::DisSensors() {
    objFL = false;
    objFR = false;
    objBL = false;
    objBR = false;
    temp = 0;
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
