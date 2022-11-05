#include "Arduino.h"
#include "Wheels.h"
#include "ObsAvoiding.h"

int ObsAvoiding::objectPos(int disFL, int disFR, int disBL, int disBR, bool line_detect) {
    /**
     * getPosition: based on distance of 4 ultrasonic sensor, determine the position of car and object
     * return:
     * -2 -> when all dis infinity, out line detect, used to move left -> move right to comeback line
     * -1 -> when disFR <=10    , disFL infinity -> object before + right side -> move left to avoid object
     * 0  -> when disFR infinity, disFL infinity, disBR or disBL <= 10 -> go forward
     * 1  -> when disFR infinity, disFL <=10     -> object before + left side  -> move right to avoid object
     * 2  -> when all dis infinity, out line detect, used to move right -> move left to comeback line
     * */

    int min_front = 10;

    if(disFL < min_front and disFR < min_front){
        _last_pos = 1;
        return 1;
    }
    else if(disFL < min_front and disFR > min_front){
        _last_pos = 1;
        return 1;
    }
    else if(disFL > min_front and disFR < min_front){
        // object before + right side -> move left to avoid object
        _last_pos = -1;
        return -1;
    }
    else if(disFL > min_front and disFR > min_front){
        if (_last_pos != 0)
        {
            if (disBL < min_front/2 or disBR < min_front/2)
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

int ObsAvoiding::nextAction(int position, int speed) {
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
            Wheels::movingForward(speed,speed,speed,speed);
            break;
        case 1:
            // move right
            Wheels::movingRight(speed,speed,speed,speed);
            break;
        case 2:
            // move left
            Wheels::movingLeft(speed,speed,speed,speed);
            break;
        case -1:
            // move left
            Wheels::movingLeft(speed,speed,speed,speed);
            break;
        case -2:
            // move right
            Wheels::movingRight(speed,speed,speed,speed);
            break;
    }
}
