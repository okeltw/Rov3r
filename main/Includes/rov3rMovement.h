#ifndef rov3rMovment_h
#define rov3rMovment_h

#include <Servo.h>

class rov3rMovement{
	private:
		Servo leftWheel;
		Servo rightWheel;
		Servo head;
		int leftPin;
		int rightPin;
		int headPin;
		
	public:
		//Initialize
		rov3rMovement(int, int, int);
		
		//Wheels
		void forward();
		void reverse();
		void turnLeft();
		void turnRight();
    	void fullStop();
		
		//Head
		void lookLeft();
		void lookRight();
		void lookForward();
		
		//Setup
		void servoSetup();
};

#endif
