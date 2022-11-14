#include "FinishLine.h"
FinishLine::FinishLine(){}
FinishLine::FinishLine(Wheels &myWheels, Speed &speedControl){
    myWheels = myWheels;
    //speedControl = speedControl;
}

void FinishLine::run1(){
    myWheels.setBL(200,true);
    speedControl.updateSpeedBR(10,0.5);
}