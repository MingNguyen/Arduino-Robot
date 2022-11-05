#include "Encoder.h"
#include "Arduino.h"

Encoder::Encoder() {
    this -> _enPin = -1;
    this -> _previousMillis = millis();
}

Encoder::Encoder(int enPin) {
    this ->_enPin= enPin;
    this -> _previousMillis = millis();
    pinMode(enPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(enPin), Encoder::countPulse(), RISING);
}

void Encoder::countPulse() {
    this -> _counter++;
}

int Encoder::getSpeed() {
    if (millis() - _previousMillis >= 1000) {
        rpm = (_counter/20)*60;
        _counter = 0;
        _previousMillis += 1000;
    }
}