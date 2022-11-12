#include "Arduino.h"
#include "Wheels.h"
#include "Motor.h"
#include "Ultrasonic.h"
#include "DisSensors.h"
#include "ObsAvoiding.h"
#include "Speed.h"
#include "LineFollow.h"

int IN1_A = 7;
int IN2_A = 6;
int IN3_A = 5;
int IN4_A = 4;

int IN1_B = 8;
int IN2_B = 9;
int IN3_B = 10;
int IN4_B = 11;

int IR1 = 25;
int IR2 = 27;
int IR3 = 29;
int IR4 = 31;
int IR5 = 33;

int encoder1 = 2;
bool state1 = true;
int en_value1 = 0;
int triPin = -1;
int echoFR = -2, echoFL =-3, echoBR = -4, echoBL = -5;
int s1;

Wheels myWheels;
DisSensors myDisSensors;
ObsAvoiding myObsAvoiding;
LineFollow myLineFollow;


void setup() {
  Serial.begin(9600);
  pinMode(IN2_A, OUTPUT); // digital right front
  pinMode(IN4_A, OUTPUT); // analog left front
  pinMode(IN2_B, OUTPUT); // digital left back
  pinMode(IN4_B, OUTPUT); // analog right back

  pinMode(IN1_A, OUTPUT); // analog right front
  pinMode(IN3_A, OUTPUT); // digital left front
  pinMode(IN1_B, OUTPUT); // analog left back
  pinMode(IN3_B, OUTPUT); // digital right back

  pinMode(IR1, INPUT); //line detect
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);

  myWheels = Wheels();
<<<<<<< HEAD
  myWheels.setFR(IN1_A,IN2_A);
  myWheels.setFL(IN4_A,IN3_A);
  myWheels.setBL(IN2_B,IN1_B);
  myWheels.setBR(IN3_B,IN4_B);
=======
  myWheels.setFR(IN1_A,IN2_A,IN2_A);
  myWheels.setFL(IN4_A,IN3_A,IN4_A);
  myWheels.setBL(IN2_B,IN1_B,IN2_B);
  myWheels.setBR(IN3_B,IN4_B,IN4_B);
>>>>>>> parent of 58b14f2 (line_follow)


  myDisSensors = DisSensors();
  myDisSensors.setFR(triPin,echoFR);
  myDisSensors.setFL(triPin,echoFL);
  myDisSensors.setBR(triPin,echoBR);
  myDisSensors.setBL(triPin,echoBL);


<<<<<<< HEAD
=======

  myLineFollow = LineFollow(IR1, IR2, IR3, IR4, IR5);
  bool inLine = myLineFollow.inLine();
  myLineFollow.follow(myWheels, 50, 200);

  myObsAvoiding = ObsAvoiding(myDisSensors);
  int obsPosition = myObsAvoiding.getPos(inLine);
  myObsAvoiding.nextAction(myWheels, obsPosition, 255);




>>>>>>> parent of 58b14f2 (line_follow)
}


void loop() {
<<<<<<< HEAD
    myWheels.movingForward(130,130,130,130);
    inLine = myLineFollow.inLine();
    myLineFollow.follow(myWheels, 50, 200);

    myObsAvoiding = ObsAvoiding(myDisSensors);
    obsPosition = myObsAvoiding.getPos(inLine);
    myObsAvoiding.nextAction(myWheels, obsPosition, 200);


=======
  myWheels.movingBackward(200,200,200,200);
>>>>>>> parent of 58b14f2 (line_follow)
}
