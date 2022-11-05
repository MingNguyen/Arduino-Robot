#include "Wheels.h"
#include "Motor.h"
#include "Ultrasonic.h"
#include "DisSensors.h"
#include "ObsAvoiding.h"

int IN1_A = 4;
int IN2_A = 5;
int IN3_A = 6;
int IN4_A = 7;

int IN1_B = 8;
int IN2_B = 9;
int IN3_B = 10;
int IN4_B = 11;
int encoder1 = 2;
bool state1 = true;
int envalue1 = 0;
int triPin = -1;
int echoFR = -2, echoFL =-3, echoBR = -4, echoBL = -5;
int s1;

Wheels myWheels;
DisSensors myDisSensors;
ObsAvoiding myObsAvoiding;

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

  pinMode(encoder1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), read_encoder, RISING);

  myWheels = Wheels();
  myWheels.setFR(IN1_A,IN2_A,IN2_A);
  myWheels.setFL(IN4_A,IN3_A,IN4_A);
  myWheels.setBL(IN2_B,IN1_B,IN2_B);
  myWheels.setBR(IN3_B,IN4_B,IN4_B);

  myDisSensors = DisSensors();
  myDisSensors.setFR(triPin,echoFR);
  myDisSensors.setFL(triPin,echoFL);
  myDisSensors.setBR(triPin,echoBR);
  myDisSensors.setBL(triPin,echoBL);

  myObsAvoiding = ObsAvoiding();
  myObsAvoiding.setDisSenSors(myDisSensors);


}

void read_encoder(){
  envalue1++;
}

void loop() {
  myWheels.movingBackward(200,200,200,200);
}
