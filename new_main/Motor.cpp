#include "Arduino.h"
#include "Motor.h" 
Motor::Motor(int analogPin, int digitalPin, int forwardPin){
    this -> analogPin = analogPin;
    this -> digitalPin = digitalPin;
    this -> IsAnalogForward = forwardPin == analogPin;
}
Motor::Motor(){
    this -> analogPin = -1;
    this -> digitalPin = -1;
    this -> IsAnalogForward = -1;
}
void Motor::speedControl(int value,bool dir){
    _speed = value;
    _dir = dir;
    if (IsAnalogForward){
        analogWrite(analogPin,dir?value:MAX_SPEED-value);
        analogWrite(digitalPin,dir?value:MAX_SPEED-value);
    }
    else{
        analogWrite(analogPin,dir?MAX_SPEED-value:value);
        analogWrite(digitalPin,dir);
    }
}


void Motor::updateSpeed(int alpha) {
    _speed += alpha;
    if (IsAnalogForward){
        analogWrite(analogPin,_dir?_speed:MAX_SPEED-_speed);
        digitalWrite(digitalPin,!_dir);
    }
    else{
        analogWrite(analogPin,_dir?MAX_SPEED-_speed:_speed);
        digitalWrite(digitalPin,_dir);
    }
}