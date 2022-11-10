#include "Arduino.h"
#include "Motor.h" 
Motor::Motor(int forwardPin, int backwardPin){
    this -> _forwardPin = forwardPin;
    this -> _backwardPin = backwardPin;
}

void Motor::setPin(int forwardPin, int backwardPin){
    this -> _forwardPin = forwardPin;
    this -> _backwardPin = backwardPin;
}
void Motor::control(int value,bool dir){
    _dir = dir;
    _speed = value;
    analogWrite(255*dir,_forwardPin);
    analogWrite(255*(1-dir),_backwardPin);
}


void Motor::updateSpeed(int alpha) {
    _speed += alpha;
    analogWrite(255*_dir,_forwardPin);
    analogWrite(255*(1-_dir),_backwardPin);
}