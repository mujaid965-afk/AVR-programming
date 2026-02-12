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

	for(uint32_t i = 0; i < 62500; i++) //repeating the process 62500 times to get 1s  delay
	{
		TCNT = 0;  // Initial value of TCNT0 =0
	 	while (!(TIFR0 & (1 << TOV0)));	//  wait until t0v0=1. overflow happens
	 	TIFR0 |= (1 << TOV0); //WRITING 1 TO TOVO bit to make it 0 .
	}
}

int main(void)
{;	
	 // Normal mode (WGM bits = 0)
    TCCR0A = 0x00;

    // Prescaler = 1
    TCCR0B = (1 << CS00);

    // LED output
    DDRB |= (1 << PB5);
	

	while (1)
	{
		
	PORTB |=(1<<PB5);
	delay_1ms();
	PORTB&=~(1<<PB5);
	delay_1ms();
    
	}


