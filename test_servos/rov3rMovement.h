#include <Servo.h>

class rov3rMovement{
	private:
		Servo leftWheel;
		Servo rightWheel;
		Servo head;
		
	public:
		//Wheels
		void forward();
		void reverse();
		void turnLeft();
		void turnRight();
		
		//Head
		void lookLeft();
		void lookRight();
		void lookCenter();
		
		//Setup
		void servoSetup();
}