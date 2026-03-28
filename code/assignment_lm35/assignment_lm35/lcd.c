/*
 * lcd.c
 *
 * Created: 24-Mar-26 11:32:02 PM
 *  Author: Mujaid
 */ 
#include "lcd.h"

//CUSTOM DELAY
void my_delay_us(uint16_t us)
{
	while(us--)
	{
		for(uint8_t i=0; i< 16; i++)
		{
			__asm__("nop");
		}
	}
}


void my_delay_ms(uint16_t ms)
{
	while(ms--)
	{
		my_delay_us(1000);
	}
}

// enable  pulse
static void lcd_enable_pulse(void)
{
	LCD_EN_PORT |= (1 << LCD_EN_PIN);
	my_delay_us(1);
	LCD_EN_PORT &= ~(1 << LCD_EN_PIN);
	my_delay_us(50);
}

// send nibble
static void lcd_send_nibble(uint8_t nib)
{
	LCD_D_PORT &= ~((1<<LCD_D7_PIN)|(1<<LCD_D6_PIN)|(1<<LCD_D5_PIN)|(1<<LCD_D4_PIN));

	if (nib & 0x8) LCD_D_PORT |= (1<<LCD_D7_PIN);
	if (nib & 0x4) LCD_D_PORT |= (1<<LCD_D6_PIN);
	if (nib & 0x2) LCD_D_PORT |= (1<<LCD_D5_PIN);
	if (nib & 0x1) LCD_D_PORT |= (1<<LCD_D4_PIN);

	lcd_enable_pulse();
}

//send byte
static void lcd_send_byte(uint8_t value, uint8_t rs)
{
	if (rs)
	LCD_RS_PORT |= (1<<LCD_RS_PIN);
	else
	LCD_RS_PORT &= ~(1<<LCD_RS_PIN);

	lcd_send_nibble(value >> 4);
	lcd_send_nibble(value & 0x0F);
}

//Commands 
void lcd_cmd(uint8_t c)
{
	lcd_send_byte(c, 0);

	if (c == 0x01 || c == 0x02)
	my_delay_ms(2);
}

void lcd_data(uint8_t d)
{
	lcd_send_byte(d, 1);
}

//Cursor 
void lcd_set_cursor(uint8_t row, uint8_t col)
{
	uint8_t addr = (row ? 0x40 : 0x00) + (col & 0x0F);
	lcd_cmd(0x80 | addr);
}

//Print
void lcd_print(const char *s)
{
	while (*s)
	{
		lcd_data(*s++);
	}
}

void lcd_clear(void)
{
	lcd_cmd(0x01);
}

void lcd_home(void)
{
	lcd_cmd(0x02);
}

// Init
void lcd_init(void)
{
	LCD_RS_DDR |= (1<<LCD_RS_PIN);
	LCD_EN_DDR |= (1<<LCD_EN_PIN);
	LCD_D_DDR  |= (1<<LCD_D7_PIN)|(1<<LCD_D6_PIN)|(1<<LCD_D5_PIN)|(1<<LCD_D4_PIN);

	my_delay_ms(20);

	LCD_RS_PORT &= ~(1<<LCD_RS_PIN);
	LCD_EN_PORT &= ~(1 << LCD_EN_PIN);

	lcd_send_nibble(0x03);
	my_delay_ms(5);
	lcd_send_nibble(0x03);
	my_delay_us(150);
	lcd_send_nibble(0x03);
	my_delay_us(150);

	lcd_send_nibble(0x02);
	my_delay_us(150);

	lcd_cmd(0x28);
	lcd_cmd(0x08);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
}

//Print Integer
void lcd_print_uint16(uint16_t v)
{
	if (v >= 10)
	lcd_print_uint16(v / 10);

	lcd_data('0' + (v % 10));
}