/**
 * Daniel Yu
 * Basic blinky for the Atmega328p
 * Last modified: 3/21/23
 **/

#include "delay.h"

#define BLINK_DELAY 1000000

// note: unsigned char is equivalent to the arduino "byte" type

#define PORTB *((volatile unsigned char*) 0x25) 	// dereferencing the register for port b 
#define DDRB *((volatile unsigned char*) 0x24) 		// dereferencing the data direction register for port b
#define PIN5 (1 << 5) 								// 0b00100000

int main()
{
	// Note: project done on an Arduino Uno development board

	DDRB |= PIN5; 									// sets pin 5 as an output pin

	while(1)
	{
		PORTB |= PIN5;
  		delay(BLINK_DELAY);
  		PORTB &= ~(PIN5);
  		delay(BLINK_DELAY);
	}
}