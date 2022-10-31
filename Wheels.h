#ifndef Wheels_h
#define Wheels_h
#include "Motor.h"
class Wheels
{
private:

public:
    Motor FR;
    Motor FL;
    Motor BR;
    Motor BL;
    Wheels();
    void updateFR(int analogPin, int digitalPin, int forward);
    void updateFL(int analogPin, int digitalPin, int forward);
    void updateBR(int analogPin, int digitalPin, int forward);
    void updateBR(int analogPin, int digitalPin, int forward);
};


#endif