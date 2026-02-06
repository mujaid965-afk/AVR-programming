/*
 * timer0_normalmode.c
 *
 * Created: 2/3/2026 9:50:26 PM
 * Author : Mujaid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void delay_1ms()
{

	for(long int i=0;i<62500;i++) //repeating the process 62500 times to get 1s  delay
	{
	 while((!TIFR0&(1<<TOV0)));	//  wait until t0v0=1. overflow happens
	TIFR0|=(1<<TOV0); //WRITING 1 TO TOVO bit to make it 0 .
	}
}

int main(void)
{
   
    TCNT0=0; // Initial value of TCNT0 =0
	
	// configuring Timer0 for nomral mode
	TCCR0A &=~(1<<WGM00) ;
	TCCROA &=~(1<<WGM01) ;
	
	//Configuring Timer0 for  no prescalar 
	TCCR0B|=(1<<CS00);
	TCCR0B&=~(1<<CS01);
	TCCR0B&=~(1<<CS02);
	
	//CONFIGURING A PIN 
DDRB |=(1<<PB5); //CONFIGURING PIN 5 AS OUTPUT

	while (1)
	{
		
	PORTB |=(1<<PB5);
	delay_1ms();
	PORTB&=~(1<<PB5);
	delay_1ms();
    
	}


