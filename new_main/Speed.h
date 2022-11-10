//
// Created by Asus on 11/5/2022.
//

#ifndef ROBOT_SPEED_H
#define ROBOT_SPEED_H
#include "Encoder.h"
#include "Wheels.h"

class Speed{
private:
    int _pulseFL, _pulseFR, _pulseBL, _pulseBR;
public:
    Encoder _FL;
    Encoder _FR;
    Encoder _BL;
    Encoder _BR;

    Speed();

    void setFL(int enPin);
    void setFR(int enPin);
    void setBL(int enPin);
    void setBR(int enPin);

    void updateFL(Wheels myWheels, int set_speed, int alpha);


};

#endif //ROBOT_SPEED_H
