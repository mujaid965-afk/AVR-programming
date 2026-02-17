/*
 * EXT_INT0.c
 *
 * Created: 17-Feb-26 9:48:12 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect) // interrupt vector table
{
	PORTB ^=(1<<PB4);
	

int main(void)
{
	DDRB |= (1<<PB5); // PB5 as output
	DDRB |= (1<<PB4); //PB4 as output
	DDRD &=~(1<<PD2); // PD2 as input (INT0)
	
    EIMSK |= (1<<INT0); //enabling INTO
	EICRA |= (1<<ISC01); //interrupt on falling edge
	sei(); //enabling global interrupt
    while (1) 
    {
		PORTB |= (1<<PB5);
		_delay_ms(1000);
		PORTB &=~(1<<PB5);
		_delay_ms(1000);
    }
}

