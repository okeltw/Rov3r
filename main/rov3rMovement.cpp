#include <Servo.h>
#include "Arduino.h"
#include "rov3rMovement.h"

/*
 * Servo Directions:
 * Stop: 90
 * Clockwise: 0
 * C.Clockwise: 180
 */

void rov3rMovement::fullStop(){
  leftWheel.write(95);
  rightWheel.write(94);
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
  head.write(10);
}

void rov3rMovement::lookForward(){
  head.write(90);
}

void rov3rMovement::lookRight(){
  head.write(170);
}

void rov3rMovement::servoSetup(int left, int right, int headPin){
  leftWheel.attach(left);
  rightWheel.attach(right);
  head.attach(headPin);
}
