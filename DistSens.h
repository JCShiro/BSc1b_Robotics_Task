class DistSens{
  public:

  DistSens(int pin);

  void setup(int currentTime);
  float getDistance(int currentTime);
  int timeSinceLastRead;

  private:

  int pin;
  float dist_t, sensity_t;

};