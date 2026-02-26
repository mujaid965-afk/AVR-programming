/*
 * dcmotor.c
 *
 * Created: 1/31/2026 12:09:51 AM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set PB5 and PB4 as output
	DDRB |= (1 << DDB5) | (1 << DDB4);

	while (1)
	{
		// CLOCKWISE
		PORTB |= (1 << PB5);   // IN1 = 1
		PORTB &= ~(1 << PB4);  // IN2 = 0
		_delay_ms(4000);

		// STOP
		PORTB &= ~(1 << PB4) ;
		PORTB &= ~ (1 << PB5);
		_delay_ms(5000);

		// ANTICLOCKWISE
		PORTB |= (1 << PB4);   // IN2 = 1
		PORTB &= ~(1 << PB5);  // IN1 = 0
		_delay_ms(4000);

		// STOP
		PORTB &= ~((1 << PB4) | (1 << PB5));
		_delay_ms(5000);
	}
}
