/*
 * blink_bitwise.c
 *
 * Created: 1/28/2026 11:55:07 AM
 * Author : Mujaid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
    DDRB|=(1<<DDB5);// configuring Pin 5 as output
    while (1) 
    {
		PORTB|=(1<<PB5);
		_delay_ms(1000);
		PORTB&=~(1<<PB5);
		_delay_ms(1000);
		
    }
}

