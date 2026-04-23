#include <Arduino.h>
#include "Led.h"

Led::Led(int pin, float interval) {
  this->pin = pin;
  this->interval = interval;
}

void Led::setup(int currentTime){
  pinMode(pin, OUTPUT);

  lastChangeOfState = currentTime;
  digitalWrite(pin, HIGH);
}

void Led::update(int currentTime, float dist_t) {
  float actualInterval = interval * map(dist_t,560,1,1,5);
  if(currentTime - lastChangeOfState > actualInterval) {
    lastChangeOfState = currentTime;
    bool currentState = digitalRead(pin);
    digitalWrite(pin, !currentState);
  }
}