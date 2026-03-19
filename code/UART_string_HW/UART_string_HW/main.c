/*
 * UART_string_HW.c
 *
 * Created: 19-Mar-26 2:44:57 PM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void uart_init(void)
{
	UBRR0H = 0;
	UBRR0L = 103;

	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

	UCSR0B &= ~(1 << UCSZ02);
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

	UCSR0C &= ~((1 << UPM01) | (1 << UPM00));
	UCSR0C &= ~(1 << USBS0);
}

void uart_transmit(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}


void uart_print_string(const char *str)
{
	while (*str)
	{
		uart_transmit(*str);
		str++;
	}
}

int main(void)
{
	uart_init();

	while (1)
	{
		uart_print_string("Hello \r\n");  // \r\n for new line
		_delay_ms(1000);
	}
}

