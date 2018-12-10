#include <Motorscontrol.h>

#include <IRremote.h>
#include <Ultrasonic.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

Motorscontrol motorA(9,2,3,200,120);
Motorscontrol motorB(10,4,5,200,120);

Ultrasonic ultrasonic(A0,A1);

int distance;

void setup(){
   Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){

    distance = ultrasonic.read();
  if (distance<15){
   motorA.stoping();
   motorB.stoping();
  }

  Serial.println(distance);
  if (irrecv.decode(&results)){
    switch (results.value){
      case 0xFF18E7: //Up
      Serial.println("up");

       if (distance>10){
        motorA.up();
        motorB.down();
       } else {
        Serial.println("too close");
       }
       break;
      case 0xFF4AB5: //down
      Serial.println("down");
       motorA.down();
       motorB.up();
 
       break;
       case 0xFF5AA5: //right
       Serial.println("right");
        motorA.right();
        motorB.right();

       break;
       case 0xFF10EF: //left
       Serial.println("left");
        motorA.left();
        motorB.left();

       break;
       case 0xFF38C7: //Ok
        motorA.stoping();
        motorB.stoping();

       break;
       default:
        motorA.stoping();
        motorB.stoping();
    }
    delay(100);
        irrecv.resume(); 


  }
    
}
