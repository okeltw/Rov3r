//Authors:      Brandon Poplstein and Taylor Okel
//Created on:   Tuesday December 1, 2015
//Subject:      Rov3r Project - Embedded Systems
//Description:  This code uses the digital pin to send out a digital pulse to measure the distance of an object.  
//              Make sure to use a digital pin!!!

#include "rov3rEyes.h"
#include "rov3rMovement.h"

rov3rEyes *sensor = new rov3rEyes(0, 200); //New sensor at pin 0 with a threshold of 200
rov3rMovement rov3r;
long val=0;

//Testing
const int leftLED = 50;
const int rightLED = 51;

void setup() {
  // put your setup code here, to run once: 
  
  //Serial.begin(9600);   //Initiates serial connection so results can be returned to PC
  rov3r.servoSetup(22,31,26); //Don't care's on left and right wheel, set the head pin to whereever its at.
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  
  rov3r.lookForward();
}

void loop() {
  // put your main code here, to run repeatedly:

  rov3r.lookForward();
  if(sensor->seeObject()){
    rov3r.fullStop();
    rov3r.lookLeft();
    delay(500);
    if(sensor->seeObject()){
      rov3r.lookRight();
      delay(600);
      if(sensor->seeObject()){
        //reverse
      }
      else{
        rov3r.turnRight();
        delay(1000);
        rov3r.fullStop();
      }
    }
    else{
      rov3r.turnLeft();
      delay(1000);
      rov3r.fullStop();
    }
  }
  else{
    rov3r.forward();
  }
  delay(500); 
  rov3r.lookForward();
}
