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
	// Set PB0 and PB1 as output
	DDRB |= (1 << DDB5) | (1 << DDB4);

	while (1)
	{
		// CLOCKWISE
		PORTB |= (1 << DDB5);   // IN1 = 1
		PORTB &= ~(1 << DDB4);  // IN2 = 0
		_delay_ms(2000);

		// STOP
		PORTB &= ~(1 << DDB5) ;
		PORTB &= ~ (1 << DDB5);
		_delay_ms(2000);

		// ANTICLOCKWISE
		PORTB |= (1 << DDB4);   // IN2 = 1
		PORTB &= ~(1 << DDB5);  // IN1 = 0
		_delay_ms(2000);

		// STOP
		PORTB &= ~((1 << DDB4) | (1 << DDB5));
		_delay_ms(2000);
	}
}
