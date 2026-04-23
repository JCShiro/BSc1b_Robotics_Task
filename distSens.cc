#include <Arduino.h>
#include "DistSens.h"

#define MAX_RANG (520)

#define ADC_SOLUTION (16383.0)

DistSens::DistSens(int pin) {
  this->pin = pin;
}

void DistSens::setup(int currentTime){
  Serial.begin(9600);
  pinMode(pin,INPUT);
  analogReadResolution(14);
  timeSinceLastRead = currentTime;
}

float DistSens::getDistance(int currentTime){
  //read value from sensor
  sensity_t = analogRead(pin);
  timeSinceLastRead = currentTime;
  if(timeSinceLastRead + 500 > currentTime){
  dist_t = sensity_t * MAX_RANG / ADC_SOLUTION;
  Serial.print(dist_t,0);
  Serial.println("cm");
  return dist_t;

  }
}