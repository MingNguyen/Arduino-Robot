

#ifndef ROBOT_FINISHLINE_H
#define ROBOT_FINISHLINE_H
#include "Wheels.h"
#include "Speed.h"

class FinishLine
{
private:
    Wheels  myWheels;
    Speed speedControl;
public:
    FinishLine();
    FinishLine(Wheels &myWheels, Speed &speedControl);
    void run1();
    void run2();    
};


#endif //ROBOT_FINISHLINE_H
