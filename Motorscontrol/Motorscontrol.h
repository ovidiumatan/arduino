#ifndef Motorscontrol_h
#define Motorscontrol_h

#include "Arduino.h"

class Motorscontrol
{
  public:
    Motorscontrol(int motorPin, int in1, int in2, int directSpeed, int turnSpeed);
    void up();
    void down();
    void left();
    void right();
    void stoping();

   private:
    int _motorPin;
    int _in1;
    int _in2; 
	int _directSpeed;
	int _turnSpeed;
};

#endif
