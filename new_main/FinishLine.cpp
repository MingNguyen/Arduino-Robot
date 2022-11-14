#include "FinishLine.h"
FinishLine::FinishLine(){
    status = true;
}
//for the right move
bool FinishLine::endRun(){
    return status;
}
void FinishLine::run1(Wheels &myWheels, Speed &speedControl){
    unsigned long time = millis();
    myWheels.movingForward(90,90,90,90);
    speedControl.updateSpeedFL(myWheels,40,1);
    speedControl.updateSpeedFR(myWheels,40,1);
    speedControl.updateSpeedBL(myWheels,40,1);
    speedControl.updateSpeedBR(myWheels,40,1);
    if(time >= millis() - 3000){
        time = millis();
        myWheels.turnRight(90,90,90,90);
        delay(200);
        myWheels.movingForward(90,90,90,90);
        speedControl.updateSpeedFL(myWheels,40,1);
        speedControl.updateSpeedFR(myWheels,40,1);
        speedControl.updateSpeedBL(myWheels,40,1);
        speedControl.updateSpeedBR(myWheels,40,1);
        if (time >= millis() - 4000) status = false;

    }
}
// case turn left
void FinishLine::run2(Wheels &myWheels, Speed &speedControl){
    unsigned long time = millis();
    myWheels.movingForward(90,90,90,90);
    speedControl.updateSpeedFL(myWheels,40,1);
    speedControl.updateSpeedFR(myWheels,40,1);
    speedControl.updateSpeedBL(myWheels,40,1);
    speedControl.updateSpeedBR(myWheels,40,1);
    if(time >= millis() - 3000){
        time = millis();
        myWheels.turnLeft(90,90,90,90);
        delay(200);
        myWheels.movingForward(90,90,90,90);
        speedControl.updateSpeedFL(myWheels,40,1);
        speedControl.updateSpeedFR(myWheels,40,1);
        speedControl.updateSpeedBL(myWheels,40,1);
        speedControl.updateSpeedBR(myWheels,40,1);
        if (time >= millis() - 4000) status = false;

    }
}