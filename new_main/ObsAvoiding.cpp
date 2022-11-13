#include "Arduino.h"
#include "ObsAvoiding.h"
ObsAvoiding::ObsAvoiding(){
    _position = 0;
    _last_pos = 0;
    _finish = true;
}
ObsAvoiding::ObsAvoiding(DisSensors myDisSensors){
    this -> _myDisSensors = myDisSensors;
    _position = 0;
    _last_pos = 0;
    _finish = true;
}


void ObsAvoiding::getDistance() {
    _myDisSensors.getAllDis();
    _disFL = _myDisSensors._disFL;
    _disFR = _myDisSensors._disFR;
    _disBL = _myDisSensors._disBL;
    _disBR = _myDisSensors._disBR;
}

bool ObsAvoiding::objAhead() {
    // if object ahead the car return true
    _myDisSensors.detect_obj();
    if(_myDisSensors.objFR or _myDisSensors.objFL){
        this -> _finish = false;
        return true;
    } else{
        return false;
    }
}

bool ObsAvoiding::objSide() {
    _myDisSensors.detect_obj();
    if(_myDisSensors.objBR or _myDisSensors.objBL){
        return true;
    } else{
        return false;
    }
}


int ObsAvoiding::getPos(bool line_detect) {
    /**
     * getPosition: based on distance of 4 ultrasonic sensor, determine the position of car and object
     * return:
     * -2 -> when all dis infinity, out line detect, used to move left -> move right to comeback line
     * -1 -> when disFR <=10    , disFL infinity -> object before + right side -> move left to avoid object
     * 0  -> when disFR infinity, disFL infinity, disBR or disBL <= 10 -> go forward
     * 1  -> when disFR infinity, disFL <=10     -> object before + left side  -> move right to avoid object
     * 2  -> when all dis infinity, out line detect, used to move right -> move left to comeback line
     * */

     //set min dis to start avoid obj
     int min_front = 10;

     if(line_detect and ObsAvoiding::objAhead()){
         //if in line and object ahead
         if(_disFL < min_front){
             _last_pos = 1;
             return 1;
         } else{
             _last_pos = -1;
             return -1;
         }
     }

     if(!line_detect and ObsAvoiding::objAhead() and _last_pos != 0){
         //if object still ahead and out line
         return _last_pos;
     }

     if (!line_detect and _last_pos != 0 and !ObsAvoiding::objAhead() and ObsAvoiding::objSide()){
         //if detected last position + object not ahead +
         return 0;
     }

    if (!line_detect and _last_pos != 0 and !ObsAvoiding::objAhead() and !ObsAvoiding::objSide()){
        return _last_pos*2;
    }

    if (line_detect and _last_pos != 0 and !ObsAvoiding::objAhead() and ! ObsAvoiding::objSide()){
        _finish = true;
        return 0;
    }
    return 0;

}

bool ObsAvoiding::obsFinish(bool line_detect) {
    if(line_detect and !objAhead() and _finish){
        return true;
    }else return false;
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

