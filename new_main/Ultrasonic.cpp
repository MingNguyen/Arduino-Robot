#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic() {
    this ->_start = millis();
    this -> _trigPin = -1;
    this -> _echoPin = -1;
    this -> _average_dis = -1;
}

Ultrasonic::Ultrasonic(int trigPin, int echoPin)
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT 
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  _start = millis();
  _trigPin = trigPin;
  _echoPin = echoPin;
  _average_dis = -1;
}

int Ultrasonic::getStartTime() {
    return _start;
}

void Ultrasonic::setStartTime(int start) {
    _start = start;
}

int Ultrasonic::distance(int now)
{
  // defines variables
  int distance; // variable for the distance measurement

  // trigPin on
  digitalWrite(_trigPin, HIGH);

  if (now - _start >= 5){
      // trigPin off
      digitalWrite(_trigPin, LOW);

      // calculate distance
      distance = (pulseIn(_echoPin, HIGH) /2) /29.1;

      // update start
      _start = millis();
      _distance = distance;
      return int(distance);
  }
  else return -1;
}
int Ultrasonic::distance_delay() {
    digitalWrite(_trigPin,0);   // off trig
    delayMicroseconds(2);
    digitalWrite(_trigPin,1);   // on trig
    delayMicroseconds(5);   // delay microsecond
    digitalWrite(_trigPin,0);   // off trig

    _distance = int(pulseIn(_echoPin,HIGH)/2/29.412);
    return _distance;
}

int Ultrasonic::average_dis() {
    int alpha = 0.1;
    //int now_dis = Ultrasonic::distance(millis());
    int now_dis = Ultrasonic::distance_delay();

    if(now_dis != -1){
      if(now_dis > 20 or now_dis < 3){
          //if out range or infinity
          now_dis = 40;
          this -> _average_dis += alpha*(now_dis - this -> _average_dis);
          return this->_average_dis;
      }
      else{
          if(this->_average_dis == -1){
              this -> _average_dis = now_dis;
              return this -> _average_dis;
          }else{
              this -> _average_dis += alpha*(now_dis - this -> _average_dis);
              return this -> _average_dis;
          }
      }
   }
   return  this -> _average_dis;
}

bool Ultrasonic::detect_obj() {
    int average = Ultrasonic::average_dis();
    // detect object, distance from[3:10]
    if(average < 15 and average > 1){
        return true;
    } else{
        return false;
    }
}


void Ultrasonic::print_distance()
{
  Ultrasonic::distance(millis());
  Serial.print("Distance: ");
  Serial.print(_distance);
  Serial.println(" cm");
}
