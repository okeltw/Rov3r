#include "Arduino.h"
#include "./rov3rEyes.h"

rov3rEyes::rov3rEyes(int pin, long inThresh){
	sensorPin = pin;
	threshold = inThresh;
}

long rov3rEyes::sense(){
	rawDistance = analogRead(sensorPin);
	return rawDistance;
}

bool rov3rEyes::seeObject(){
	rawDistance = analogRead(sensorPin);
	return rawDistance > threshold;
}