#include <Servo.h>
#include <rov3rMovement.h>

Servo leftWheel;
Servo rightWheel;
Servo head;

rov3rMovement rov3r;

void setup() {
  // put your setup code here, to run once:
  rov3r.Setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Test wheels
  forward();
  delay(2000); //ms
  fullStop();
  delay(2000);
  reverse();
  delay(2000);
  fullStop();
  delay(2000);
  turnLeft();
  delay(2000);
  turnRight();
  delay(2000);
  fullStop();
  delay(2000);
  
  //Test Head
  headLeft();
  delay(2000);
  headCenter();
  delay(2000);
  headRight();
  delay(2000);
  headCenter();
  delay(2000);
}


