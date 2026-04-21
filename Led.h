class Led {
  public:
  //constructor
  Led(int pin, int interval);

  //setup & loop should be called in the setup & loop sections of the main .ino file
  void setup(int currentTime);
  void update(int currentTime);

  private:
  //generic properties
  int pin;
  int interval;

  //state storage
  int lastChangeOfState;
};