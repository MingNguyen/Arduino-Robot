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

    void setFR(int analogPin, int digitalPin, int forward);
    void setFL(int analogPin, int digitalPin, int forward);
    void setBR(int analogPin, int digitalPin, int forward);
    void setBL(int analogPin, int digitalPin, int forward);

    void controlFR(int value,bool dir);
    void controlFL(int value,bool dir);
    void controlBR(int value,bool dir);
    void controlBL(int value,bool dir);


    void movingForward(int valueFR, int valueFL, int valueBR, int valueBL);
    void movingBackward(int valueFR, int valueFL, int valueBR, int valueBL);
    void movingLeft(int valueFR, int valueFL, int valueBR, int valueBL);
    void movingRight(int valueFR, int valueFL, int valueBR, int valueBL);
    void turnLeft(int valueFR, int valueFL, int valueBR, int valueBL);
    void turnRight(int valueFR, int valueFL, int valueBR, int valueBL);
};

#endif