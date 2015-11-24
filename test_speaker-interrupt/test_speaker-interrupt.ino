#include "pitches.h"
#include "rov3rSpeaker.h"

rov3rSpeaker Speaker;

void setup() {
  Speaker = new rov3rSpeaker(7); // Assign new speaker to pin 7
}

void loop() {
  play();
  if(Speaker.getIndex() >= Speaker.getLength()){
    restart();
  }
}
