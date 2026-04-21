#include <Arduino.h>
#include "piezoPlayer.h"

PiezoPlayer::PiezoPlayer(int pin){
  this->pin = pin;
}

void PiezoPlayer::setup(int currentTime) {
  lastChangeOfNote = currentTime;
  tone(pin, melody[currentNote], note_lengths[currentNote]*delay_per_beat);
}

void PiezoPlayer::update(int currentTime) {
  if(currentTime - lastChangeOfNote >= note_lengths[currentNote]*delay_per_beat) {
    currentNote++;
    lastChangeOfNote = currentTime;
    if (currentNote >= sizeof(melody) / sizeof(melody[0])) {
      currentNote = 0;
    }if(melody[currentNote] == 0){
      noTone(pin);
    }else{
    tone(pin, melody[currentNote], note_lengths[currentNote]*delay_per_beat);
    }
  }
}