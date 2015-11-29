#include "Arduino.h"
#include "rov3rTimer.h"

rov3rTimer::Setup(){
	noInterrupts();
	TCCR1A = 0;
	TCCR1B = 0;
	
	TCNT1 = 0;	              // preload timer @ 0-16MHz/256/2Hz
	TCCR1B |= (1 << CS12);    // 256 prescaler 
	TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
	interrupts(); 
}