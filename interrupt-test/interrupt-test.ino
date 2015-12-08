#include <TimerThree.h>
#include <Servo.h>

#include "pitches.h"
#include "rov3rSpeaker.h"

Servo myservo;
rov3rSpeaker *Speaker = new rov3rSpeaker(46);
long pause;

void setup() {
  // put your setup code here, to run once:

  noInterrupts();
  Timer3.initialize(500000); //Initialized w half second period

  //I don't know what this does
  //Timer3.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle

  Timer3.attachInterrupt(blinker);
  
  myservo.attach(26);
  myservo.write(90);
  interrupts();
}

//Gets called at period, half second
//Use setPeriod(<period>) to set new period
//For our purposes, this should work:
//  setPeriod(500000) == 1/2 s == quarter note, 120 bpm
//  setPeriod(250000) == 1/4 s == eighth note, 120 bpm
void blinker()
{
  //Test Interrupt:
  //digitalWrite(13, digitalRead(13) ^ 1); //Complement current state of the LED

  //Test Interrupt w Speaker:
  Speaker->play();
  if(Speaker->getIndex() >= Speaker->getLength()){
    Speaker->reset();
  }

  if(Speaker->getDuration() == 4)
    pause = 250000;
  else
    pause = 125000;

  Timer3.setPeriod(pause*1.5);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo.write(180);
}
