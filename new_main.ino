 #include "Wheels.h"
 #include "Motor.h"
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
 
 //int MAX_SPEED = 255;
 //int MIN_SPEED = 0;
 int s1;

  Wheels myWheels = Wheels();
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

  myWheels.setFR(IN1_A,IN2_A,IN2_A);
  myWheels.setFL(IN4_A,IN3_A,IN4_A);
  myWheels.setBL(IN2_B,IN1_B,IN2_B);
  myWheels.setBR(IN3_B,IN4_B,IN4_B);

}

void read_encoder(){
  envalue1++;
}

void loop() {
  myWheels.movingBackward(200,200,200,200);
}
