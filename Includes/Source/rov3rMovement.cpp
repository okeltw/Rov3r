#include <Servo.h>
#include "Arduino.h"
#include "./rov3rMovement.h"

/*
 * Servo Directions:
 * Stop: 90
 * Clockwise: 0
 * C.Clockwise: 180
 */

rov3rMovement::rov3rMovement(int assignL, int assignR, int assignH ){
  leftPin = assignL;
  rightPin = assignR;
  headPin = assignH;
  leftWheel.attach(leftPin);
  rightWheel.attach(rightPin);
  head.attach(head);
}

void rov3rMovement::fullStop(){
  leftWheel.write(90);
  rightWheel.write(90);
  return;
}

void rov3rMovement::forward(){
  leftWheel.write(0);
  rightWheel.write(180);
}

void rov3rMovement::reverse(){
  leftWheel.write(180);
  rightWheel.write(0);
}

void rov3rMovement::turnLeft(){
  leftWheel.write(180); //Back        |  ^   <-
  rightWheel.write(180); //Forward    v  |    
}

void rov3rMovement::turnRight(){
  leftWheel.write(0); //Forward       ^  |   ->
  rightWheel.write(0); //Back         |  v
}

void rov3rMovement::lookLeft(){
  head.write(0);
}

void rov3rMovement::lookForward(){
  head.write(90);
}

void rov3rMovement::lookRight(){
  head.write(180);
}

void rov3rMovement::servoSetup(){
  leftWheel.attach(10);
  rightWheel.attach(9);
  head.attach(8);
}
