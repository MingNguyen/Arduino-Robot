#include "Wheels.h"
#include "Arduino.h"

Wheels::Wheels(){
    FR = Motor();
    FL = Motor();
    BR = Motor();
    BL = Motor();
}


void Wheels::setFR(int analogPin, int digitalPin, int forward) {
    FR = Motor(analogPin, digitalPin, forward);
}
void Wheels::setFL(int analogPin, int digitalPin, int forward) {
    FL = Motor(analogPin, digitalPin, forward);
}
void Wheels::setBR(int analogPin, int digitalPin, int forward) {
    BR = Motor(analogPin, digitalPin, forward);
}
void Wheels::setBL(int analogPin, int digitalPin, int forward) {
    BL = Motor(analogPin, digitalPin, forward);
}


void Wheels::controlFR(int value,bool dir){
    FR.speedControl(value, dir);
}
void Wheels::controlFL(int value,bool dir){
    FL.speedControl(value,dir);
}
void Wheels::controlBR(int value,bool dir){
    BR.speedControl(value,dir);
}
void Wheels::controlBL(int value,bool dir){
    BL.speedControl(value,dir);
}


void Wheels::movingForward(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.speedControl(valueFR, true);
    FL.speedControl(valueFL,true);
    BR.speedControl(valueBR,true);
    BL.speedControl(valueBL,true);
}
void Wheels::movingBackward(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.speedControl(valueFR, false);
    FL.speedControl(valueFL,false);
    BR.speedControl(valueBR,false);
    BL.speedControl(valueBL,false);
}
void Wheels::movingLeft(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.speedControl(valueFR, true);
    FL.speedControl(valueFL,false);
    BR.speedControl(valueBR,false);
    BL.speedControl(valueBL,true);
}
void Wheels::movingRight(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.speedControl(valueFR, false);
    FL.speedControl(valueFL,true);
    BR.speedControl(valueBR,true);
    BL.speedControl(valueBL,false);
}
void Wheels::turnLeft(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.speedControl(valueFR, true);
    FL.speedControl(valueFL,true);
    BR.speedControl(valueBR,false);
    BL.speedControl(valueBL,false);
}
void Wheels::turnRight(int valueFR, int valueFL, int valueBR, int valueBL){
    FR.speedControl(valueFR, false);
    FL.speedControl(valueFL,false);
    BR.speedControl(valueBR,true);
    BL.speedControl(valueBL,true);
}