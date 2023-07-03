#include <avr/io.h>
#include "MACROS.h"
void operatingredLED()
{
	DDRB |=(1<<7); 
	 PORTB &=(~(1<<7)); //initially led is closed
	SET_BIT(PORTB,7);
		
}
void disableredLED()
{
	DDRB |=(1<<7); 
	PORTB &=(~(1<<7)); //initially led is closed
CLR_BIT(PORTB,7); 
	
}

void operatingyellowLED()
{
	DDRB |=(1<<6);
	PORTB &=(~(1<<6)); //initially led is closed
	SET_BIT(PORTB,6);
	
}
void disableyellowLED()
{
	DDRB |=(1<<6);
	PORTB &=(~(1<6)); //initially led is closed
	CLR_BIT(PORTB,6);
	
}
void operatinggreenLED()
{
	DDRB |=(1<<5);
	PORTB &=(~(1<<5)); //initially led is closed
	SET_BIT(PORTB,5);
	
}
void disablegreenLED()
{
	DDRB |=(1<<5);
	PORTB &=(~(1<5)); //initially led is closed
	CLR_BIT(PORTB,5);
	
}