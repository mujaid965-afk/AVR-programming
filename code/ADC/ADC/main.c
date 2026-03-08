/*
 * ADC.c
 *
 * Created: 05-Mar-26 4:55:22 PM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void adc_init(void);
uint16_t ADC_read(uint8_t channel);

void adc_init(void)
{
    ADMUX |= (1 << REFS0);     // Avcc reference  
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // enabling adc and setting prescalar 128
	ADCSRA |= (1 << ADEN); // eneable ADC
}

uint16_t ADC_read(uint8_t channel)
{
	channel &= 0x07; //limiting the channel to max 7
	ADMUX = (ADMUX&0xF8) | channel; // selacting the correct channel
	ADCSRA |= (1 << ADSC); // start conversion
	while (ADCSRA & (1 << ADSC)); //wait till adc becomes zero
	return ADC;
}
	
int main(void)
{

	lcd_init();
	adc_init();
	lcd_clear();
	lcd_set_cursor(0,0);
	lcd_print("Temperature:");
	
    while (1) 
    {
		uint16_t value = ADC_read(0);
		float temperature = (value * 0.488);
		lcd_set_cursor(1,0);
		lcd_print(temperature);
		_delay_ms(2000);
    }
}

