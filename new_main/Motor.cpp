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
    if (IsAnalogForward){
        analogWrite(analogPin,dir?value:MAX_SPEED-value);
        digitalWrite(digitalPin,!dir);
    }
    else{
        analogWrite(analogPin,dir?MAX_SPEED-value:value);
        digitalWrite(digitalPin,dir);
    }
}
