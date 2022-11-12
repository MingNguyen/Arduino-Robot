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
<<<<<<< HEAD
    _speed = value;
    analogWrite(255*dir,_forwardPin);
    analogWrite(255*(1-dir),_backwardPin);
=======
    if (IsAnalogForward){
        analogWrite(analogPin,dir?value:MAX_SPEED-value);
        digitalWrite(digitalPin,!dir);
    }
    else{
        analogWrite(analogPin,dir?MAX_SPEED-value:value);
        digitalWrite(digitalPin,dir);
    }
>>>>>>> parent of 58b14f2 (line_follow)
}


void Motor::updateSpeed(int alpha) {
    _speed += alpha;
    analogWrite(255*_dir,_forwardPin);
    analogWrite(255*(1-_dir),_backwardPin);
}