#include <TimerThree.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //Onboard LED
  Timer3.initialize(500000); //Initialized w half second period

  //I don't know what this does
  Timer3.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle

  Timer3.attachInterrupt(blinker);
}

//Gets called at period, half second
//Use setPeriod(<period>) to set new period
//For our purposes, this should work:
//  setPeriod(500000) == 1/2 s == quarter note, 120 bpm
//  setPeriod(250000) == 1/4 s == eighth note, 120 bpm
void blinker()
{
  digitalWrite(13, digitalRead(13) ^ 1); //Complement current state of the LED
}

void loop() {
  // put your main code here, to run repeatedly:

}
