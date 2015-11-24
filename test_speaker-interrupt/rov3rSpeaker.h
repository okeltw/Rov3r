#ifndef rov3rSpeaker_h
#define rov3rSpeaker_h

#include "Arduino.h"
#include "pitches.h"

class rov3rSpeaker{
	private:
		//Melody.  Change to desired tune & associated note duration.
		int melody[] = {
			NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
		};
	
		int noteDurations[] = {
			4, 8, 8, 4, 4, 4, 4, 4
		};
		
		
		int thisNote; //Cursor
		const int length = sizeof(melody); //Total of notes.  Used for looping.
		int pin; // Pin Speaker is attached to
	public:
		void play();
		void restart();
		rov3rSpeaker(int); // Initialize thisNote, set pin.
		
		int currentNote();
		int getIndex();
		int getLength();
};

#endif