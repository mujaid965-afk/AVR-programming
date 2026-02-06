/*
 * timer_CTCmode.c
 *
 * Created: 2/6/2026 9:39:56 PM
 * Author : Mujaid
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL

void delay_1s()
{

	for(int i=0;i<78;i++) //repeating the process 78 times to get 1s  delay
	{
		while(!(TIFR0 & (1 << OCF0A)));	//  // wait until OCF0A = 1 (compare match occurs)

		TIFR0 |= (1 << OCF0A); //clear flag 
	}
}

int main(void)
{
	
	TCNT0=0; // Initial value of TCNT0 =0
	
	// configuring Timer0 for CTC mode
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00); //prescalar 1024
	OCR0A = 200;
	
	
	
	//CONFIGURING A PIN
	DDRB |= (1<<PB5); //CONFIGURING PIN 5 AS OUTPUT

	while (1)
	{
		
		PORTB |=(1<<PB5);
		delay_1s();
		PORTB&=~(1<<PB5);
		delay_1s();
		
	}
}


