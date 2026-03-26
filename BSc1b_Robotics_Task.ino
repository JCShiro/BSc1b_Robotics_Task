int LED_pin = 2;
//LED period
int LED_period = 1000;
int last_LED_toggle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_pin,OUTPUT);
}

void loop() {
  //get current time and compare with last toggle
    int current_time = millis();
    int time_since_last_toggle = current_time - last_LED_toggle;

    //if it's time to toggle -> toggle and update variables
    if(time_since_last_toggle > LED_period){
      int current_LED_state = digitalRead(LED_pin);
      digitalWrite(LED_pin, !current_LED_state);
      last_LED_toggle = current_time;
    }
}
