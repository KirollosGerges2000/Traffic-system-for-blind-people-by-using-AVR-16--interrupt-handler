/*
 * 7 segment.c
 *
 * Created: 6/9/2023 7:38:06 PM
 * Author : Kirollos Gerges
 */ 
typedef unsigned char u8; //unsigned char[8_bits] "u8"
/*TRAFFIC_ON_FOR_PEOPLE function to implement the process of counting
7 segment "99 sec"*/
int TRAFFIC_ON_FOR_CARS( ) 
{
  /*
  activating interrupt
  ;Implement TRAFFIC_OFF_FOR_PEOPLE function*/
   /* volatile counter_1 , counter_2 for preserving the 
   last value during interrupt*/
volatile u8 counter_1=9;  
 volatile u8 counter_2=10; 
// declaration 7 segments as an output module
 DDRC |=(1<<0);  
 DDRC |=(1<<1);
 DDRC |=(1<<2);
    DDRC |=(1<<3);
   DDRA |=(1<<0);
   DDRA |=(1<<1);
   DDRA |=(1<<2);
   DDRA |=(1<<3); 
 PORTC = 0x09;
  //initialize value of PORTS,Flags
 PORTA = 0x09;
// begin process
while(counter_1!=0 && counter_2!=0)
	{ 
		counter_2--;
		PORTA=counter_2;
			_delay_ms(810); //delay time for counting
	
	if( PORTA == 0x00)
	{
		counter_2=10;
		counter_1--;
		PORTC=counter_1;
		
		}
	}
	counter_2=10;
	while(counter_2!=0)
	{
		PORTC = 0x00;
counter_2--;
PORTA=counter_2;
if(counter_2<=4)
{
	disablegreenLED();
	operatingyellowLED();
BUZZER();
	
}
_delay_ms(810); //delay time for counting
	}
disableyellowLED();
operatingredLED();

}
