/*
 * blink.c
 *
 * Created: 1/28/2026 10:29:05 AM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL // defining the crystal frequency 160 MHz
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
DDRB = 0b00001000; // configuring PB3 a output
   while(1)
   {
	   PORTB=0b00001000; // making PB3 HIGH
	   _delay_ms(500); // 1000ms delay
	   PORTB=0B00000000; // making PB3 LOW
	   _delay_ms(500);// 1000ms delay
	  
   }

}

