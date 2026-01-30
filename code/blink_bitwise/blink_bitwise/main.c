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
   // Set PB0 and PB1 as output
    DDRB |= (1 << PB0) | (1 << PB1);

    while (1)
    {
        // CLOCKWISE
        PORTB |= (1 << PB0);   // IN1 = 1
        PORTB &= ~(1 << PB1);  // IN2 = 0
        _delay_ms(2000);

        // STOP
        PORTB &= ~((1 << PB0) | (1 << PB1));
        _delay_ms(2000);

        // ANTICLOCKWISE
        PORTB |= (1 << PB1);   // IN2 = 1
        PORTB &= ~(1 << PB0);  // IN1 = 0
        _delay_ms(2000);

        // STOP
        PORTB &= ~((1 << PB0) | (1 << PB1));
        _delay_ms(2000);
    }
}