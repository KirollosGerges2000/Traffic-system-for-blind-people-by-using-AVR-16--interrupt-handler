#include <avr/io.h>
#include "MACROS.h"
void ACTIVE_BUZZER()
{
	DDRB |=(1<<4);
	PORTB &=(~(1<<4)); //initially led is closed
	SET_BIT(PORTB,4);
}
void DISABLE_BUZZER()
{
	DDRB |=(1<<4);
	PORTB &=(~(1<<4)); //initially led is closed
	CLR_BIT(PORTB,4);
}
void BUZZER()   
{
		ACTIVE_BUZZER();
		_delay_ms(300);
		DISABLE_BUZZER();
	
}