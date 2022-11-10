#include "Arduino.h"
#include "ObsAvoiding.h"
<<<<<<< HEAD
ObsAvoiding::ObsAvoiding(){
}
ObsAvoiding::ObsAvoiding(DisSensors myDisSensors){
    this -> _myDisSensors = myDisSensors;
}
void ObsAvoiding::setDisSenSors(DisSensors myDisSensors){
    this -> _myDisSensors = myDisSensors;
}
int ObsAvoiding::objectPos( bool line_detect) {
=======

ObsAvoiding::ObsAvoiding() {}

ObsAvoiding::ObsAvoiding(DisSensors myDisSensors){
    this -> _myDisSensors = myDisSensors;
}
int ObsAvoiding::getPos( bool line_detect) {
>>>>>>> 3441fe24f9dea611b79800b4e2a66f74c9f079c3
    /**
     * getPosition: based on distance of 4 ultrasonic sensor, determine the position of car and object
     * return:
     * -2 -> when all dis infinity, out line detect, used to move left -> move right to comeback line
     * -1 -> when disFR <=10    , disFL infinity -> object before + right side -> move left to avoid object
     * 0  -> when disFR infinity, disFL infinity, disBR or disBL <= 10 -> go forward
     * 1  -> when disFR infinity, disFL <=10     -> object before + left side  -> move right to avoid object
     * 2  -> when all dis infinity, out line detect, used to move right -> move left to comeback line
     * */
     int now = millis();
    _myDisSensors.getAllDis();

    int min_front = 10;
    int disList[4] = {0};

    if(_myDisSensors.disFL < min_front and _myDisSensors.disFR < min_front){
        _last_pos = 1;
        return 1;
    }
    else if(_myDisSensors.disFL < min_front and _myDisSensors.disFR > min_front){
        _last_pos = 1;
        return 1;
    }
    else if(_myDisSensors.disFL > min_front and _myDisSensors.disFR < min_front){
        // object before + right side -> move left to avoid object
        _last_pos = -1;
        return -1;
    }
    else if(_myDisSensors.disFL > min_front and _myDisSensors.disFR > min_front){
        if (_last_pos != 0)
        {
            if (_myDisSensors.disBL < min_front/2 or _myDisSensors.disBR < min_front/2)
            {
                return 0;
            }
            else{
                return _last_pos*2;
            }
        }
        if (line_detect == true) {
            _last_pos = 0;
            return 0;
        }
    }
}

void ObsAvoiding::nextAction(Wheels myWheels, int position, int speed) {
    /**
     * getPosition: based on distance of 4 ultrasonic sensor, determine the position of car and object
     * return:
     * -2 -> when all dis infinity, out line detect, used to move left -> move right to comeback line
     * -1 -> when disFR <=10    , disFL infinity -> object before + right side -> move left to avoid object
     * 0  -> when disFR infinity, disFL infinity, disBR or disBL <= 10 -> go forward
     * 1  -> when disFR infinity, disFL <=10     -> object before + left side  -> move right to avoid object
     * 2  -> when all dis infinity, out line detect, used to move right -> move left to comeback line
     * */

    switch (position) {
        case 0:
            // go forward
            myWheels.movingForward(speed,speed,speed,speed);
            break;
        case 1:
            // move right
            myWheels.movingRight(speed,speed,speed,speed);
            break;
        case 2:
            // move left
            myWheels.movingLeft(speed,speed,speed,speed);
            break;
        case -1:
            // move left
            myWheels.movingLeft(speed,speed,speed,speed);
            break;
        case -2:
            // move right
            myWheels.movingRight(speed,speed,speed,speed);
            break;
    }
}

