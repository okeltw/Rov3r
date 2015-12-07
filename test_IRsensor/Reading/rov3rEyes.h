#ifndef rov3rEyes_h
#define rov3rEyes_h

class rov3rEyes{
	private:
		int sensorPin;
		long rawDistance;
		long threshold;
		
	public:
		rov3rEyes(int, long);		//Initialize.  Set sensorPin to int, threshold to long
		long sense();		//Grab value from distance
		bool seeObject();	//Grab distance value, compare to threshold, and determine if there is an object.
};

#endif