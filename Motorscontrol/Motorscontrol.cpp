#include "Motorscontrol.h"
#include "Arduino.h"

Motorscontrol::Motorscontrol(int motorPin, int in1, int in2, int directSpeed, int turnSpeed)
{
  _motorPin=motorPin;
  _in1=in1;
  _in2=in2;
  _directSpeed=directSpeed;
  _turnSpeed=turnSpeed;
  
  pinMode(_motorPin, OUTPUT);
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
}

void Motorscontrol::stoping(){
   analogWrite(_motorPin,0);
   digitalWrite(_in1, LOW);
   digitalWrite(_in2, LOW);
}

void Motorscontrol::up()
{
   analogWrite(_motorPin,_directSpeed);
   digitalWrite(_in1, LOW);
   digitalWrite(_in2, HIGH);
}

void Motorscontrol::down()
{
   analogWrite(_motorPin,_directSpeed);
   digitalWrite(_in1, HIGH);
   digitalWrite(_in2, LOW);
}

void Motorscontrol::left()
{
   analogWrite(_motorPin,_turnSpeed);
   digitalWrite(_in1, HIGH);
   digitalWrite(_in2, LOW);
}

void Motorscontrol::right()
{
   analogWrite(_motorPin,_turnSpeed);
   digitalWrite(_in1, LOW);
   digitalWrite(_in2, HIGH);
}
