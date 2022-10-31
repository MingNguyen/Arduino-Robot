#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int echoPin, int trigPin)
{
  delayStart = millis();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT 
  pinMode(echoPinR, INPUT); // Sets the echoPin as an INPUT 
  _echoPin = echoPin;
  _trigPin = trigPin
}

int Ultrasonic::distance()
{
  // defines variables
  long duration; // variable for the duration of sound wave travel
  int distance; // variable for the distance measurement
    
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  return distance;
}

void Ultrasonic::print_distance()
{
  distance = Ultrasonic::distance();
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
