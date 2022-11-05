#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin, int echoPin)
{

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT 
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  _start = millis();
  _trigPin = trigPin;
  _echoPin = echoPin;

}

int Ultrasonic::getEcho() {
    return _echoPin;
}

int Ultrasonic::getTrig() {
    return _trigPin;
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

  if (now - _start >= 50){
      // trigPin off
      digitalWrite(_trigPin, LOW);

      // calculate distance
      distance = pulseIn(_echoPin, HIGH) * 0.034 /2;

      // update start
      _start = millis();
      return int(distance);
  }
  else return -1;
}

void Ultrasonic::print_distance()
{
  int distance = Ultrasonic::distance(millis());
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
