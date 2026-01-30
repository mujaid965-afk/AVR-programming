/*
 * dcmotorprogram_usingfunctions.c
 *
 * Created: 1/31/2026 12:32:50 AM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/* Function declarations */
void cw(unsigned int time);
void ccw(unsigned int time);
void stp(unsigned int time);
void delay_ms(unsigned int ms);

int main(void)
{
	DDRB |= (1 << PB0) | (1 << PB1);   // PB0, PB1 as output

	while (1)
	{
		cw(2000);     // Clockwise 2s
		stp(2000);    // Stop 2s
		ccw(2000);    // Anticlockwise 2s
		stp(2000);    // Stop 2s
	}
}

/* Clockwise rotation */
void cw(unsigned int time)
{
	PORTB |= (1 << PB0);
	PORTB &= ~(1 << PB1);
	delay_ms(time);
}

/* Anticlockwise rotation */
void ccw(unsigned int time)
{
	PORTB |= (1 << PB1);
	PORTB &= ~(1 << PB0);
	delay_ms(time);
}

/* Stop motor */
void stp(unsigned int time)
{
	PORTB &= ~((1 << PB0) | (1 << PB1));
	delay_ms(time);
}

/* Custom delay function */
void delay_ms(unsigned int ms)
{
	while (ms--)
	{
		_delay_ms(1);
	}
}

