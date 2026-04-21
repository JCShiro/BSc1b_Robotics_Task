#include "pitches.h"

class PiezoPlayer {

  public:
  PiezoPlayer(int pin);

  //setup &update call in setup & loop of .ino
  void setup (int currentTime);
  void update(int currentTime);

  private:

  //basic properties
  int pin;

  //melody and durations
  int melody[22] = {
  NOTE_F4,NOTE_G4,NOTE_AS4,NOTE_G4,NOTE_F4,NOTE_G4,NOTE_AS4,NOTE_DS4,NOTE_F5,NOTE_DS4,NOTE_C4,NOTE_D5,NOTE_AS4,NOTE_C4,NOTE_D4,NOTE_C4,0,NOTE_C4,NOTE_D5,NOTE_C4,NOTE_D5,NOTE_G4
  };
  float note_lengths[22]= {
  0.25,0.25,0.25,0.75,0.25,0.25,0.25,0.0625,0.25,0.25,0.0625,0.5,0.25,0.25,0.25,0.5,0.0625,0.25,0.25,0.25,0.25,0.5
};

float delay_per_beat = 705.88;

//state storage
int currentNote = 0;
int lastChangeOfNote;
};