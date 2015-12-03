#include "Includes/rov3rMovement.h"
#include "Includes/rov3rSpeaker.h"

rov3rMovement *movement;


void setup() {
  // put your setup code here, to run once:
  //myservo.attach(52);  - - Taken care of in constructor
  movement = new rov3rMovement(52, 53, 54);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bool seeWall = false; //= brandonsIRfunction();
  
  //Wall Ahead?
  if(seeWall){
    movement->lookLeft();
    seeWall = false; //=brandonsIRfunction();
    
    //wall left?
    if(seeWall){
      movement->lookRight();
      seeWall = false; //=brandonsIRfunction();
      
      //Wall right?
      //This portion needs thought out.  How to get out of cramped alley? Enough room to turn around?
      while(seeWall){
        movement->reverse();
        seeWall = false; //=brandonsIRfunction();
      }//endwhile
      
      movement->turnRight();
      movement->lookForward();
    }//endLEFTwall
    else{
      movement->turnLeft();
      movement->lookForward();
    }
  }//endFWDwall
  else{
    movement->forward();
  }
}//endloop
