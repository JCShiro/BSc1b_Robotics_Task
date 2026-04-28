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

//----------------Object instantiation----------------

//Creates the LED objects and sets pin and base speed
Led ledSlow = Led(2, 705.88);
Led ledFast = Led(4, (705.88/2));

//Creates Piezo buzzer object and sets the pin
PiezoPlayer piezoPlayer = PiezoPlayer(9);

//Creates the LCD Screen object
Lcd lcdScreen = Lcd();

//Creates the distance sensor object and sets the pin
DistSens distSens = DistSens(A0);

//Only happens once
void setup(){
  //time syncing across classes
  int currentTime = millis();

  //calls the LED setup and passes the variable "currentTime"
  ledSlow.setup(currentTime);
  ledFast.setup(currentTime);

  //calls the piezo player setup and passes the variable "currentTime"
  piezoPlayer.setup(currentTime);

  //calls the lcd screen setup and passes the variable "currentTime"
  lcdScreen.setup(currentTime);

  //calls the distance sensor setup and passes the variable "currentTime"
  distSens.setup(currentTime);
}

//Repeats until arduino is turned off
void loop(){
  //updates the time sync variable
  int currentTime = millis();

  //runs the loop for the distance sensor
  float dist_t = distSens.getDistance(currentTime);

  // Runs the loop for the LED's
  ledSlow.update(currentTime, dist_t);
  ledFast.update(currentTime, dist_t);

  // Runs the loop for the piezo buzzer
  piezoPlayer.update(currentTime, dist_t);

  // Runs the loop for the LCD screen
  lcdScreen.update(currentTime);

}