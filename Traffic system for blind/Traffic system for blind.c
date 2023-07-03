/*
 * Traffic system for blind.c
 *
 * Created: 6/10/2023 4:08:49 PM
 * Author : Kirollos Gerges
 */ 
#include <avr/io.h>     //input/output for avr
#include <util/delay.h>  // delay library    
#include "TRAFFIC_ON_FOR_CARS.c"  //traffic on for cars library
#include "TRAFFIC_OFF_FOR_PEOPLE.c" //traffic off for People library
#include "operating LEDs.c"   //Response for LEDS
#include "interrupt.c"    //Interrupts Library to help blind people to stop cars
typedef unsigned char u8;    //unsigned char[8_bits] "u8"
 

int traffic_system_for_blinders(void)
{  INT0_Init();           // Enable and configure external INT0
	g_Interrupt_Flag = 0;   //initializing interrupt flag =0
	while(1)     //super loop to execute program until MCU turns off
			{
	operatinggreenLED();   //to turn on green leds for notify cars
			TRAFFIC_ON_FOR_CARS();  //to begin count 99 second for cars
			/*After reaching to 0 ;turn off green leds
			  for notify cars to stop*/ 
			disablegreenLED(); 
		operatingredLED(); //turn on red led to stop the cars
		TRAFFIC_OFF_FOR_PEOPLE();  //to begin count 24 second for people passing 
	  /*turn off red led to notify people to stop passing street, to permit cars to pass*/
	   disableredLED();  
			}
}