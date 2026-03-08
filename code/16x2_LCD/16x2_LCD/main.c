/*
 * 16x2_LCD.c
 *
 * Created: 25-Feb-26 5:28:29 PM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	lcd_init();
	lcd_set_cursor(0, 0);
	lcd_print("Hi ");

	lcd_set_cursor(1, 0);
	lcd_print("count starts ");
	
	

	// small demo: print a number
	lcd_print_uint16(1234);

	while (1)
	{
		lcd_print_uint16(1234);
		_delay_ms(1000);
		lcd_clear();
		_delay_ms(1000);

	}
}

