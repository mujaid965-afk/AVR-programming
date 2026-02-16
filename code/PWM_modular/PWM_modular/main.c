/*
 * PWM_modular.c
 *
 * Created: 16-Feb-26 2:51:07 PM
 * Author : Mujaid
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "pwm.h"


int main(void)
{
    PWM0_Init(); // initialising pwm
	PWM0_Duty(40); // callling PWM with duty cycle 40
    while (1) 
    {
    }
}

