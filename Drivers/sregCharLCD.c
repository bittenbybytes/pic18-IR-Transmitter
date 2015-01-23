#include "sregCharLCD.h"

#include "sreg74HC595N_driver.h"

// LCD shift register pin connection
static const char lcd_backlight = 7;
static const char lcd_rs = 6;
static const char lcd_enable = 5;

// LCD commands
static const char lcd_4bit_if_cmd = 0x20;
static const char lcd_cursor = 1;
static const char lcd_cursor_blink = 1;
static const char lcd_enable_cmd = 0x0A;
static const char lcd_on_cmd = 0x0C | lcd_cursor << 1 | lcd_cursor_blink;
static const char lcd_clear_cmd = 0x01;
static const char lcd_reset_cursor_pos_cmd = 0x02;
static const char lcd_csr_cmd = 0x06;

void lcdDelay()
{
	uint16_t i = 0;
	for (i = 0; i < 0x4f; i++);
}

void toggleLcdEnable()
{
	writeSregBit(lcd_enable, HIGH);
	writeSregBit(lcd_enable, LOW);
}

void writeLcdByte(int lcdDataNotCommand, unsigned char data)
{
	writeSregBit(lcd_rs, lcdDataNotCommand);
	writeSregLowNibble(data >> 4);
	toggleLcdEnable();
	writeSregLowNibble(data);
	toggleLcdEnable();
	lcdDelay();
}

void writeLcdData(unsigned char data)
{
	writeLcdByte(1, data);
}

void writeLcdCmd(unsigned char cmd)
{
	writeLcdByte(0, cmd);
}

// initialize display

void initHD44780LCD()
{
	initSregIO();
	writeSregBit(lcd_backlight, 0);
	lcdDelay();
	writeLcdCmd(lcd_4bit_if_cmd);
	writeLcdCmd(lcd_enable_cmd);
	lcdClear();
	writeLcdCmd(lcd_csr_cmd);
	writeLcdCmd(lcd_on_cmd);
}

// print a zero terminated character string

void lcdPrint(const char* str)
{
	int i = 0;
	while (str[i] != '\0' && i < 40)
	{
		writeLcdData(str[i]);
		i++;
	}
}

// clear display content

void lcdClear()
{
	writeLcdCmd(lcd_clear_cmd);
}

// reset position of the read/write cursor

void lcdResetCursorPosition()
{
	writeLcdCmd(lcd_reset_cursor_pos_cmd);
}