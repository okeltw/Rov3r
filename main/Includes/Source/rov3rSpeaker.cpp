#include "pitches.h"
#include "rov3rSpeaker.h"

rov3rSpeaker::rov3rSpeaker(int assignment){
	thisNote = 0;
    pin = assignment;
}

void rov3rSpeaker::play(){
	// to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(pin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pin);
    thisNote++;
    if(thisNote >= len)
        restart();
        
    
    return;
}

void rov3rSpeaker::restart(){
    thisNote = 0;
    return;
}

//Access methods
int rov3rSpeaker::currentNote(){
    return melody[thisNote];
}

int rov3rSpeaker::getIndex(){
    return thisNote;
}

int rov3rSpeaker::getLength(){
    return len;
}
