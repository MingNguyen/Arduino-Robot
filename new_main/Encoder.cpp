#include "Encoder.h"
#include "Arduino.h"


Encoder::Encoder(int enPin) {
    this ->_enPin= enPin;
    this -> _previousMillis = millis();
    pinMode(enPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_enPin),countPulse,HIGH);
    
}

void Encoder::countPulse() {
    _counter++;
}

int Encoder::getSpeed() {
    if (millis() - _previousMillis >= 1000) {
        rpm = (_counter/20)*60;
        _counter = 0;
        _previousMillis += 1000;
    }
}
