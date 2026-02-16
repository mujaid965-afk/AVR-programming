/*
 * timer0_pwmmode.c
 *
 * Created: 2/16/2026 12:49:54 PM
 * Author : Mujaid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

int main(void)
{
	// Set OC0A (PD6) as output
   DDRD |= (1 << PD6);
   
   // Fast PWM mode (WGM00=1, WGM01=1)
   TCCR0A |= (1 << WGM00) | (1 << WGM01);
   
   
   // Non-inverting mode
   TCCR0A |= (1 << COM0A1);
   
   // Prescaler = 64
   TCCR0B |= (1 << CS01) | (1 << CS00);
   
    // 40% duty cycle
   OCR0A = 102;
   
   while(1)
   {
	   
   }  
   
}

