#include "Arduino.h"
#include "DisSensors.h"
#include "Wheels.h"

class ObsAvoiding{
private:

public:
    /**
     * getPosition: based on distance of 4 ultrasonic sensor, determine the position of car and object
     * return:
     * -2 -> when all dis infinity, out line detect, used to move left -> move right to comeback line
     * -1 -> when disFR <=10    , disFL infinity ->  move left to avoid object
     * 0  -> when disFR infinity, disFL infinity, disBR or disBL <= 10 -> go forward
     * 1  -> when disFR infinity, disFL <=10     ->  move right to avoid object
     * 2  -> when all dis infinity, out line detect, used to move right -> move left to comeback line
     * */

    int _position = 0;
    int objectPos(int disFL, int disFR, int disBL, int disBR, bool line_detect);
    int nextAction(int position);
    void avoidObject();

};

