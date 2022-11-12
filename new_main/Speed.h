#ifndef ROBOT_SPEED_H
#define ROBOT_SPEED_H
#include "Encoder.h"
#include "Wheels.h"
#include "Arduino.h"

class Speed{
private:
    int _pulseFL, _pulseFR, _pulseBL, _pulseBR;
    static int _previousMicros[4]; //FL FR BL BR

    static int _newMicros[4];

    unsigned long deltaList[4];
    double speedList[4];

    Wheels myWheels;

    static void countPulseFR();
    static void countPulseFL();
    static void countPulseBR();
    static void countPulseBL();

    void updateDeltaSpeed();

public:
    Encoder _enFL;
    Encoder _enFR;
    Encoder _enBL;
    Encoder _enBR;
    Speed();
    Speed(Wheels myWheels);

    void setFL(int enPin);
    void setFR(int enPin);
    void setBL(int enPin);
    void setBR(int enPin);


    void updateMotorSpeed(Wheels myWheels, double set_speed, int alpha);


};

#endif
