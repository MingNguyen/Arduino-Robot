#include "Speed.h"
#include "Encoder.h"
#include "Arduino.h"
#include "Wheels.h"

Speed::Speed(){
}
Speed::Speed(Wheels myWheels) {
    _enFR = Encoder();
    _enFL = Encoder();
    _enBR = Encoder();
    _enBL = Encoder();
    myWheels = myWheels;
}
int Speed::_previousMicros[4];
int Speed::_newMicros[4];
void Speed::setFL(int enPin) {
    _enFL = Encoder(enPin);

    attachInterrupt(digitalPinToInterrupt(enPin), Speed::countPulseFL, RISING);
}

void Speed::setFR(int enPin) {
    _enFR = Encoder(enPin);
    attachInterrupt(digitalPinToInterrupt(enPin), Speed::countPulseFR, RISING);
}

void Speed::setBL(int enPin) {
    _enBL = Encoder(enPin);
    attachInterrupt(digitalPinToInterrupt(enPin), Speed::countPulseBL, RISING);
}

void Speed::setBR(int enPin) {
    _enBR = Encoder(enPin);
    attachInterrupt(digitalPinToInterrupt(enPin), Speed::countPulseBR, RISING);
}


void Speed::countPulseFL(){
    _previousMicros[0] = _newMicros[0];
    _newMicros[0] = micros();
}
void Speed::countPulseFR(){
    _previousMicros[1] = _newMicros[1];
    _newMicros[1] = micros();
}
void Speed::countPulseBL(){
    _previousMicros[2] = _newMicros[2];
    _newMicros[2] = micros();
}
void Speed::countPulseBR(){
    _previousMicros[3] = _newMicros[3];
    _newMicros[3] = micros();
}

void Speed::updateDeltaSpeed(){
    unsigned long deltaList[4];
    deltaList[0] = (_newMicros[0] - _previousMicros[0])*1.0e6;
    deltaList[1] = (_newMicros[0] - _previousMicros[0])*1.0e6;
    deltaList[2] = (_newMicros[0] - _previousMicros[0])*1.0e6;
    deltaList[3] = (_newMicros[0] - _previousMicros[0])*1.0e6;

    speedList[0] = 1/deltaList[0];
    speedList[1] = 1/deltaList[1];
    speedList[2] = 1/deltaList[2];
    speedList[3] = 1/deltaList[3];

}

void Speed::updateMotorSpeed(Wheels myWheels, double set_speed, int alpha) {
    updateDeltaSpeed();
    double eIntegral = 0;
    double e = set_speed - speedList[0];
    eIntegral = eIntegral + e*deltaList[0];
    myWheels.FL.updateSpeed(e*10+eIntegral*5);

    eIntegral = 0;
    e = set_speed - speedList[1];
    eIntegral = eIntegral + e*deltaList[1];
    myWheels.FL.updateSpeed(e*10+eIntegral*5);

    eIntegral = 0;
    e = set_speed - speedList[2];
    eIntegral = eIntegral + e*deltaList[2];
    myWheels.FL.updateSpeed(e*10+eIntegral*5);

    eIntegral = 0;
    e = set_speed - speedList[3];
    eIntegral = eIntegral + e*deltaList[3];
    myWheels.FL.updateSpeed(e*10+eIntegral*5);
}

