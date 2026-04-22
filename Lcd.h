class Lcd{
  public:
    void setup(int currentTime);
    void update(int currentTime);
    int initialTime;

  private:
    int speed = 500;
};