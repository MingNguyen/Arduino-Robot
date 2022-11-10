#include "Wheels.h"
#include "Arduino.h"

Wheels::Wheels(){
}
Wheels::Wheels(Motor FR,Motor FL,Motor BR,Motor BL){
    this -> FR = FR;
    this -> FL = FL;
    this -> BR = BR;
    this -> BL = BL;
}

void Wheels::setFR(int forwardPin, int backwardPin) {
    this -> FR = Motor(forwardPin, backwardPin);
}
void Wheels::setFL(int forwardPin, int backwardPin) {
    FL = Motor(forwardPin, backwardPin);
}
void Wheels::setBR(int forwardPin, int backwardPin) {
    BR = Motor(forwardPin, backwardPin);
}
void Wheels::setBL(int forwardPin, int backwardPin) {
    BL = Motor(forwardPin, backwardPin);
}


void Wheels::controlFR(int value,bool dir){
    FR.control(value, dir);
}
void Wheels::controlFL(int value,bool dir){
    FL.control(value,dir);
}
void Wheels::controlBR(int value,bool dir){
    BR.control(value,dir);
}
void Wheels::controlBL(int value,bool dir){
    BL.control(value,dir);
}


void Wheels::movingForward(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.control(valueFR, true);
    FL.control(valueFL,true);
    BR.control(valueBR,true);
    BL.control(valueBL,true);
}
void Wheels::movingBackward(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.control(valueFR, false);
    FL.control(valueFL,false);
    BR.control(valueBR,false);
    BL.control(valueBL,false);
}
void Wheels::movingLeft(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.control(valueFR, true);
    FL.control(valueFL,false);
    BR.control(valueBR,false);
    BL.control(valueBL,true);
}
void Wheels::movingRight(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.control(valueFR, false);
    FL.control(valueFL,true);
    BR.control(valueBR,true);
    BL.control(valueBL,false);
}
void Wheels::turnLeft(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.control(valueFR, true);
    FL.control(valueFL, false);
    BR.control(valueBR, true);
    BL.control(valueBL,false);
}
void Wheels::turnRight(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.control(valueFR, false);
    FL.control(valueFL, true);
    BR.control(valueBR, false);
    BL.control(valueBL,true);
}