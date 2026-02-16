/*
 * pwm.c
 *
 * Created: 16-Feb-26 2:55:22 PM
 *  Author: Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void PWM0_Init(void)
{
	// Set OC0A (PD6) as output
	DDRD |= (1 << PD6);
	
	// Fast PWM mode (WGM00=1, WGM01=1)
	TCCR0A |= (1 << WGM00) | (1 << WGM01);
	
	
	// Non-inverting mode
	TCCR0A |= (1 << COM0A1);
	
	// Prescaler = 64
	TCCR0B |= (1 << CS01) | (1 << CS00);
	
	OCR0A = 0; // initially 0 % duty cycle
}

void PWM0_Duty(uint8_t duty_percentage)
{
	if(duty_percentage >100) // to limit entering duty cycle greater than 100 
	{
		duty_percentage = 100;
	}
	OCR0A = (uint8_t)((duty_percentage*256)/100);
}