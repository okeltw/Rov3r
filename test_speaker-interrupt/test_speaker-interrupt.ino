#include "pitches.h"
#include "rov3rSpeaker.h"

rov3rSpeaker *Speaker = new rov3rSpeaker(49); // Assign new speaker to pin 7;

void setup() {
  
}

void loop() {
  Speaker->play();
  if(Speaker->getIndex() >= Speaker->getLength()){
    Speaker->restart();
    delay(1000);
  }
  delay(10);
}
