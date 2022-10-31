 #include "Wheels.h"
 #include "Motor.h"
 int IN1_A = 4; // digital right front
 int IN2_A = 5; // analog left front
 int IN3_A = 6; // digital left back
 int IN4_A = 7; // analog right back

 int IN1_B = 8; // analog right front
 int IN2_B = 9; // digital left front
 int IN3_B = 10;// analog left back
 int IN4_B = 11;// digital left back
 int encoder1 = 2;
 bool state1 = true; 
 int envalue1 = 0; 
 
 //int MAX_SPEED = 255;
 //int MIN_SPEED = 0;
 int FR = 1100, FL=1101, BR=1110, BL=1111;
 int s1;
 


void setup() {
  Serial.begin(9600);
  pinMode(IN2_A, OUTPUT);
  pinMode(IN4_A, OUTPUT);
  pinMode(IN2_B, OUTPUT);
  pinMode(IN4_B, OUTPUT);

  pinMode(IN1_A, OUTPUT);
  pinMode(IN3_A, OUTPUT);
  pinMode(IN1_B, OUTPUT);
  pinMode(IN3_B, OUTPUT);

  pinMode(encoder1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), read_encoder, RISING);

}

void read_encoder(){
  envalue1++;
}
/**
 * 
 * 
 * @para wheel: wheel name
 * @para value: the analog signal assigned into the driver
 * @para huong: true = forward, false = backward
 */
void speedControl(int wheel, int value, bool dir){
  if (wheel == FR){
    // 1 leg only has a value high and low. and the other can has analog value
    digitalWrite(IN1_A, !dir);
    analogWrite(IN2_A,dir?value:MAX_SPEED-value);
    }
  else if (wheel == FL){
    analogWrite(IN3_A, dir?MAX_SPEED-value:value);
    digitalWrite(IN4_A,dir);
    }
  else if (wheel == BL){
    digitalWrite(IN1_B, !dir);
    analogWrite(IN2_B, dir?value:MAX_SPEED-value);
    }
  else if (wheel == BR){
    analogWrite(IN3_B, dir?MAX_SPEED-value:value);
    digitalWrite(IN4_B,dir);
    }
  }

void loop() {
  Wheels myWheels = Wheels();
  myWheels.FR = Motor(IN2_A,IN1_A,IN2_A);
  

}
