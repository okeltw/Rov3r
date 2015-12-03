//Authors:      Brandon Poplstein and Taylor Okel
//Created on:   Tuesday December 1, 2015
//Subject:      Rov3r Project - Embedded Systems
//Description:  This code uses the digital pin to send out a digital pulse to measure the distance of an object.  
//              Make sure to use a digital pin!!!


const int pwPin = 7; 
int output; 

long pulse;
long inches; 
long cm; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //Initiates serial connection so results can be returned to PC
  
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(pwPin, INPUT); 
  
  pulse = pulseIn(pwPin, HIGH); 
  inches = pulse/147; //apparently there is a scale factor of 147 uS per Inch
  cm = inches *2.54; 

  Serial.print(cm); 
  Serial.print("cm"); 


  delay(1); 
  


}
