#include <Servo.h>

Servo leftWheel;
Servo rightWheel;
Servo head;

void setup() {
  // put your setup code here, to run once:
  leftWheel.attach(10);
  rightWheel.attach(9);
  head.attach(8);
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

/*
 * Servo Directions:
 * Stop: 90
 * Clockwise: 0
 * C.Clockwise: 180
 */

void fullStop(){
  leftWheel.write(90);
  rightWheel.write(90);
  return;
}

void forward(){
  leftWheel.write(0);
  rightWheel.write(180);
}

void reverse(){
  leftWheel.write(180);
  rightWheel.write(0);
}

void turnLeft(){
  leftWheel.write(180); //Back        |  ^   <-
  rightWheel.write(180); //Forward    v  |    
}

void turnRight(){
  leftWheel.write(0); //Forward       ^  |   ->
  rightWheel.write(0); //Back         |  v
}

void headLeft(){
  head.write(0);
}

void headCenter(){
  head.write(90);
}

void headRight(){
  head.write(180);
}

