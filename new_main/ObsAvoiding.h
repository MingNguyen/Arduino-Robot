#include "Arduino.h"
#include "DisSensors.h"
#include "Wheels.h"

class ObsAvoiding{
private:
    /**
     * @param _last_pos: last position of car and object
     * */
    int _last_pos = 0;
    int disFL, disFR, disBL, disBR;
    DisSensors _myDisSensors;
public:
    /**
     * getPosition: based on distance of 4 ultrasonic sensor, determine the position of car and object
     * return:
     * -2 -> when all dis infinity, out line detect, used to move left -> move right to comeback line
     * -1 -> when disFR <=10    , disFL infinity ->  move left to avoid object
     * 0  -> when disFR infinity, disFL infinity, disBR or disBL <= 10 -> go forward
     * 1  -> when disFR infinity, disFL <=10     ->  move right to avoid object
     * 2  -> when all dis infinity, out line detect, used to move right -> move left to comeback line
     *
     * @param dis: distance
     * @param line_detect: check car in line or not
     * */
<<<<<<< HEAD
=======

>>>>>>> 3441fe24f9dea611b79800b4e2a66f74c9f079c3
    ObsAvoiding();
    ObsAvoiding(DisSensors myDisSensors);
    void setDisSenSors(DisSensors myDisSensors);
    int _position = 0;
    int getPos(bool line_detect);
    void nextAction(Wheels myWheels, int position, int speed);

};

