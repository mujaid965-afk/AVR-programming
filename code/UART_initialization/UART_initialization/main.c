/*
 * UART_initialization.c
 *
 * Created: 18-Mar-26 5:47:28 PM
 * Author : Mujaid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void uart_init(void)
{
	// baud rate for 9600
	UBRR0H = 0;
	UBRR0L = 103;

	// enable TX and RX
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

	// 8-bit data
	UCSR0B &= ~(1 << UCSZ02);
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

	// parity select
	UCSR0C &= ~((1 << UPM01) | (1 << UPM00));

	// 1 stop bit
	UCSR0C &= ~(1 << USBS0);
}

// UART transmit
void uart_transmit(char data)
{
	// wait until buffer is empty
	while (!(UCSR0A & (1 << UDRE0)));

	// send data
	UDR0 = data;
}

int main(void)
{
	uart_init();   

	char data = 'H';

	while (1)
	{
		uart_transmit(data);
		uart_transmit('\n');   // to print a new line
		_delay_ms(1000);
	}
}