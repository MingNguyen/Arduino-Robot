#ifndef ROBOT_SPEED_H
#define ROBOT_SPEED_H
#include "Encoder.h"
#include "Wheels.h"
#include "Arduino.h"

class Speed{
private:
    int _pulseFL, _pulseFR, _pulseBL, _pulseBR;
    Wheels myWheels;
public:
    Encoder _FL;
    Encoder _FR;
    Encoder _BL;
    Encoder _BR;
    Speed();
    Speed(Wheels myWheels);

    void setFL(int enPin);
    void setFR(int enPin);
    void setBL(int enPin);
    void setBR(int enPin);

    void updateFL(Wheels myWheels, int set_speed, int alpha);


};

#endif //ROBOT_SPEED_H
