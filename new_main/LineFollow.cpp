#include "Arduino.h"
#include "LineFollow.h"
#include "Wheels.h"

LineFollow::LineFollow() {
    IR1 = -1;
    IR2 = -1;
    IR3 = -1;
    IR4 = -1;
    IR5 = -1;
}

LineFollow::LineFollow(int IR1, int IR2, int IR3, int IR4, int IR5) {
    this -> IR1 = IR1;
    this -> IR2 = IR2;
    this -> IR3 = IR3;
    this -> IR4 = IR4;
    this -> IR5 = IR5;

    _s1 = digitalRead(IR1);  //Left Most Sensor
    _s2 = digitalRead(IR2);  //Left Sensor
    _s3 = digitalRead(IR3);  //Middle Sensor
    _s4 = digitalRead(IR4);  //Right Sensor
    _s5 = digitalRead(IR5);  //Right Most Sensor
}

int LineFollow::linePos() {
    _s1 = digitalRead(IR1);  //Left Most Sensor
    _s2 = digitalRead(IR2);  //Left Sensor
    _s3 = digitalRead(IR3);  //Middle Sensor
    _s4 = digitalRead(IR4);  //Right Sensor
    _s5 = digitalRead(IR5);  //Right Most Sensor

    if ((_s1 == 1) & (_s2 == 1) & (_s3 == 1) & (_s4 == 1) & (_s5 == 1)){
        return 10;
    }
    else if ((_s1 == 1)& (_s2 == 0) & (_s3 == 0) & (_s4 == 0) & (_s5 == 0)) {
        return 2;
    }
    else if ((_s2 == 1) & (_s3 == 0) & (_s4 == 0) & (_s5 == 0)){
        return 1;
    }
    else if ((_s1 == 0 )& (_s2 == 0) & (_s3 == 0) & (_s4 == 0)&(_s5 == 1)){
        return -2;
    }
    else if ((_s1 == 0) & (_s2 == 0) & (_s3 == 0) & (_s4 == 1)){
        return -1;
    }
    else if ((_s1 == 0) & (_s2 == 1) & (_s3 == 1) & (_s4 == 1) & (_s5 == 0)){
        return 0;
    }
    else if ((_s1 == 0) & (_s2 == 0) & (_s3 == 0) & (_s4 == 0) & (_s5 == 0)){
        return 5;
    }
}

int LineFollow::PID() {

}

void LineFollow::follow(Wheels myWheels, int kp, int speed) {
    int error = linePos();
    int delta = error * kp ;
    int speed_r = speed + delta;
    int speed_l = speed - delta;

    if (speed_r>255) speed_r = 255;
    if (speed_l>255) speed_l =255;
    if (speed_r<0) speed_r = 0;
    if (speed_l<0) speed_l = 0;

    if(error == 0){
        myWheels.movingForward(speed, speed, speed, speed);
    }else if (error == 1){
        myWheels.turnLeft(speed_r, speed_l, speed_r, speed_l);
    }else if (error == 2){
        myWheels.turnLeft(speed_r, speed_l, speed_r, speed_l);
    }else if (error == -1){
        myWheels.turnRight(speed_r, speed_l, speed_r, speed_l);
    }else if (error == -2){
        myWheels.turnRight(speed_r, speed_l, speed_r, speed_l);
    }
    else{}
}

bool LineFollow::inLine() {
    int error = linePos();
    if (error == 5){
        return false;
    }
    else
        return true;
}
