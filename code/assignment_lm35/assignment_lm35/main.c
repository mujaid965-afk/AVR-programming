/*
 * assignment_lm35.c
 *
 * Created: 24-Mar-26 11:31:41 PM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include "lcd.h"

// set UART
void uart_init(void)
{
	UBRR0H = 0;
	UBRR0L = 103; // 9600 baud rate

	UCSR0B = (1 << TXEN0); // enable transmitter
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void uart_tx(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void uart_print(const char *s)
{
	while (*s)
	{
		uart_tx(*s++);
	}
}

// 
void uart_print_uint16(uint16_t v)
{
	char buf[6];
	int i = 0;

	if (v == 0)
	{
		uart_tx('0');
		return;
	}

	while (v > 0)
	{
		buf[i++] = (v % 10) + '0';
		v /= 10;
	}

	while (i--)
	{
		uart_tx(buf[i]);
	}
}

// ADC initialization
void adc_init(void)
{
	ADMUX = (1 << REFS0); // AVcc reference, ADC0 channel
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // enable ADC, prescaler 64
}

uint16_t adc_read(void)
{
	ADCSRA |= (1 << ADSC); // start conversion
	while (ADCSRA & (1 << ADSC)); // wait
	return ADC;
}

int main(void)
{
	lcd_init();
	uart_init();
	adc_init();

	// LED pin (PB0)
	DDRB |= (1 << PB0);

	uint16_t adc_val;
	uint16_t temperature;

	while (1)
	{
		// Read LM35
		adc_val = adc_read();

		// Convert to Celsius
		// LM35: 10mV/°C ? Temp = (ADC * 5 * 100) / 1024
		temperature = (adc_val * 500UL) / 1024;

		// LCD 
		lcd_clear();
		lcd_set_cursor(0, 0);
		lcd_print("Temp: ");
		lcd_print_uint16(temperature);
		lcd_print(" C");

		// UART
		uart_print("Temperature: ");
		uart_print_uint16(temperature);
		uart_print(" C\r\n");

		// LED BLINK
		PORTB ^= (1 << PB0);  // toggle LED
		my_delay_ms(500);     // 0.5 second delay
	}
}
