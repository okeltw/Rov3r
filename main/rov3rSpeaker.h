#ifndef rov3rSpeaker_h
#define rov3rSpeaker_h

#include "Arduino.h"
#include "pitches.h"

class rov3rSpeaker{
	private:
    const static int len = 50; //Total of notes.  Used for looping.
  
		//Melody.  Change to desired tune & associated note duration.
		int melody[len] = {
			NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5,                                      //5
			NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4,                    //7
      NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,                    //7
      NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5,                    //7
      NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5,                    //7
      NOTE_G4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4,  //9                
      NOTE_C5, NOTE_D5, NOTE_E5, 0, NOTE_D5, 0, NOTE_C5, 0                              //8 +
		};                                                                                  //= 50
	
		int noteDurations[len] = {
			8, 8, 4, 4, 4,            //5
			8, 8, 8, 8, 8, 8, 4,      //7
      8, 8, 8, 8, 8, 8, 4,      //7
      8, 8, 8, 8, 8, 8, 4,      //7
      8, 8, 8, 8, 8, 8, 8,      //7
      8, 8, 8, 8, 8, 8, 8, 8, 8,//9
      8, 8, 4, 4, 4, 4, 4, 4    //8
		};
		
		
		int thisNote = 0; //Cursor
    int noteDuration = 1000/noteDurations[thisNote];
		int pin; // Pin Speaker is attached to
	public:
		void play();
		void reset();
		rov3rSpeaker(int); // Initialize thisNote, set pin.
		
		int currentNote();
		int getIndex();
		int getLength();
    int getDuration();

    int pauseBetweenNotes;
};

#endif
