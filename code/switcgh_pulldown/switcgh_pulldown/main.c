/*
 * switcgh_pulldown.c
 *
 * Created: 1/31/2026 11:09:17 AM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
     /* Configure PD4 as INPUT */
     DDRD &= ~(1 << DDB4);   // PD4 = input

     /* Configure PB5 as OUTPUT */
     DDRB |= (1 << DDB5);    // PB5 = output

     while (1)
     {
	     /* Check if button on PD4 is pressed */
	     if (PIND & (1 << PD4))
	     {
		     PORTB |= (1 << PD5);   // Turn ON output (LED/motor)
	     }
	     else
	     {
		     PORTB &= ~(1 << PD5);  // Turn OFF output
	     }
     }
     }