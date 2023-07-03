/*
 * TRAFFIC_OFF_FOR_PEOPLE.c
 *
 * Created: 6/9/2023 7:38:06 PM
 * Author : Kirollos Gerges
 */ 
#include "BUZZER.c"  //Buzzer control library
typedef unsigned char u8; //unsigned char[8_bits] "u8"
/*TRAFFIC_OFF_FOR_PEOPLE function to implement the process of counting
7 segment "24 sec"*/
int TRAFFIC_OFF_FOR_PEOPLE()
{
	 u8 counter_11=2; //initialize first counter with 2
  u8 counter_22=5;  //initialize second counter with 5
// declaration 7 segments as an output module
 DDRC |=(1<<0);  
 DDRC |=(1<<1);
 DDRC|=(1<<2);
    DDRC |=(1<<3);
   DDRA |=(1<<0);
   DDRA |=(1<<1);
   DDRA |=(1<<2);
   DDRA |=(1<<3); 
   //initialize value of PORTS
 PORTC = 0x02;
 PORTA = 0x05;
 // begin process
{
while(counter_22!=0)
	{
	PORTA=0X02;
	counter_22--;
	PORTA=counter_22;
	_delay_ms(810);
	 }
}
counter_22=10;
counter_11--;
PORTC=counter_11;
while(counter_22!=0)
{
PORTC=0X01;
counter_22--;
PORTA=counter_22;
_delay_ms(810);	
}
counter_22=10;
counter_11=0;
while(counter_22!=0)
{
	PORTC=0X00;
	counter_22--;
	PORTA=counter_22;
	_delay_ms(810);
	if(counter_22<=4)
	{
		operatingyellowLED();
		disableredLED();
BUZZER();
	}
}
PORTC=0X00;
PORTA=0x00;
disableyellowLED();



}