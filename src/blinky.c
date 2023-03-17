#include <delay.h>

#define BLINK_DELAY 100000
// dereferencing the pointer of the register pointer for port b
// note: uint8_t is equivalent to the arduino "byte" type
// also equivalent to unsigned char
#define PORT_B *((volatile unsigned char*) 0x25) 
// dereferencing the pointer of the data direction register for port b
#define DDR_B *((volatile unsigned char*) 0x24)

#define PIN_5 0b00100000

int main()
{
	DDR_B |= PIN_5; // sets pin 5 as an output pin
	// where the built-in LED on the arduino uno is!

	while(1)
	{
		// drive up
		PORT_B |= PIN_5;
  		delay(BLINK_DELAY);
  		// reset
  		PORT_B &= ~(PIN_5);
  		delay(BLINK_DELAY);
	}
}