#include "Arduino.h"
#include "Motor.h" 
Motor::Motor(int analogPin, int digitalPin, int forwardPin){
    this -> analogPin = analogPin;
    this -> digitalPin = digitalPin;
    this -> IsAnalogForward = forwardPin;
}
Motor::Motor(){
    this -> analogPin = NULL;
    this -> digitalPin = NULL;
    this -> IsAnalogForward = NULL;
}
void Motor::speedControl(int value,bool dir){
    if (IsAnalogForward){
        analogWrite(analogPin,dir?value:MAX_SPEED-value);
        digitalWrite(digitalPin,!dir);
    }
    else{
        analogWrite(analogPin,dir?MAX_SPEED-value:value);
        digitalWrite(digitalPin,dir);
    }
}
