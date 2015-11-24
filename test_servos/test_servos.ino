#include <Servo.h>
#include "rov3rMovement.h"

Servo leftWheel;
Servo rightWheel;
Servo head;

rov3rMovement rov3r;

void setup() {
  // put your setup code here, to run once:
  rov3r.servoSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Test wheels
  rov3r.forward();
  delay(2000); //ms
  rov3r.fullStop();
  delay(2000);
  rov3r.reverse();
  delay(2000);
  rov3r.fullStop();
  delay(2000);
  rov3r.turnLeft();
  delay(2000);
  rov3r.turnRight();
  delay(2000);
  rov3r.fullStop();
  delay(2000);
  
  //Test Head
  rov3r.lookLeft();
  delay(2000);
  rov3r.lookForward();
  delay(2000);
  rov3r.lookRight();
  delay(2000);
  rov3r.lookForward();
  delay(2000);
}


