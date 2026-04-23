class Led {
  public:
  //constructor
  Led(int pin, float interval);

  //setup & loop should be called in the setup & loop sections of the main .ino file
  void setup(int currentTime);
  void update(int currentTime, float dist_t);

  private:
  //generic properties
  int pin;
  float interval;

  //state storage
  int lastChangeOfState;
};