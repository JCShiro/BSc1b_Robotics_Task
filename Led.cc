#include <Arduino.h>
#include "Led.h"

Led::Led(int pin, int interval) {
  this->pin = pin;
  this->interval = interval;
}

void Led::setup(int currentTime){
  pinMode(pin, OUTPUT);

  lastChangeOfState = currentTime;
  digitalWrite(pin, HIGH);
}

void Led::update(int currentTime) {
  if(currentTime - lastChangeOfState > interval) {
    lastChangeOfState = currentTime;
    bool currentState = digitalRead(pin);
    digitalWrite(pin, !currentState);
  }
}