// int LED_pin = 2;
// //LED period
// int LED_period = 1000;
// int last_LED_toggle = 0;

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(LED_pin,OUTPUT);
// }

// void loop() {
//   //get current time and compare with last toggle
//     int current_time = millis();
//     int time_since_last_toggle = current_time - last_LED_toggle;

//     //if it's time to toggle -> toggle and update variables
//     if(time_since_last_toggle > LED_period){
//       int current_LED_state = digitalRead(LED_pin);
//       digitalWrite(LED_pin, !current_LED_state);
//       last_LED_toggle = current_time;
//     }
// }


//<-----------------------New Version using classes---------------------->

#include "Led.h"
#include "piezoPlayer.h"
#include "Lcd.h"
#include "DistSens.h"

Led ledSlow = Led(2, 705.88);
Led ledFast = Led(4, (705.88/2));

PiezoPlayer piezoPlayer = PiezoPlayer(9);

Lcd lcdScreen = Lcd();

DistSens distSens = DistSens(A0);

void setup(){
  int currentTime = millis();
  ledSlow.setup(currentTime);
  ledFast.setup(currentTime);

  piezoPlayer.setup(currentTime);

  lcdScreen.setup(currentTime);

  distSens.setup(currentTime);
}

void loop(){
  int currentTime = millis();
  float dist_t = distSens.getDistance(currentTime);

  ledSlow.update(currentTime, dist_t);
  ledFast.update(currentTime, dist_t);

  piezoPlayer.update(currentTime, dist_t);

  lcdScreen.update(currentTime);

}