#include "sregCharLCD.h"

#include "sreg74HC595N_driver.h"

// LCD shift register pin connection
static const char lcd_backlight = 7;
static const char lcd_rs = 6;
static const char lcd_enable = 5;

// LCD commands
static const char lcd_8bit_if_cmd = 0x30;
static const char lcd_4bit_if_cmd = 0x20;
#define lcd_cursor 1
#define lcd_cursor_blink 1
static const char lcd_enable_cmd = 0x0A;
#define lcd_on_cmd (0x0C | lcd_cursor << 1 | lcd_cursor_blink)
static const char lcd_clear_cmd = 0x01;
static const char lcd_reset_cursor_pos_cmd = 0x02;
static const char lcd_set_cursor_pos_cmd = 0x80;
static const char lcd_csr_cmd = 0x06;

void lcdDelay()
{
	short i = 0;
	for (i = 0; i < 0x4ff; i++);
}

static void toggleLcdEnable()
{
	writeSregBit(lcd_enable, HIGH);
	writeSregBit(lcd_enable, LOW);
}

static void writeLcdByte(int lcdDataNotCommand, unsigned char data)
{
	writeSregBit(lcd_rs, lcdDataNotCommand);
	writeSregLowNibble(data >> 4);
	toggleLcdEnable();
	writeSregLowNibble(data);
	toggleLcdEnable();
}

static void writeLcdData(unsigned char data)
{
	writeLcdByte(1, data);
}

static void writeLcdCmd(unsigned char cmd)
{
	writeLcdByte(0, cmd);
}

// initialize display

void initHD44780LCD()
{
	initSregIO();
	writeSregBit(lcd_backlight, 0);
	// reset sequence (assume lcd in 8 bit mode: only write high nibble)
	writeSregBit(lcd_rs, 0); // command
	writeSregLowNibble(lcd_8bit_if_cmd >> 4);
	toggleLcdEnable();
	lcdDelay();
	writeSregLowNibble(lcd_8bit_if_cmd >> 4);
	toggleLcdEnable();
	lcdDelay();
	writeSregLowNibble(lcd_8bit_if_cmd >> 4);
	toggleLcdEnable();
	lcdDelay();
	// set to 4 bit interface (assume lcd in 8 bit mode: only write high nibble)
	writeSregLowNibble(lcd_4bit_if_cmd >> 4);
	toggleLcdEnable();
	writeLcdCmd(lcd_enable_cmd);
	lcdClear();
	lcdDelay();
	writeLcdCmd(lcd_csr_cmd);
	writeLcdCmd(lcd_on_cmd);
}

// print a single character
void lcdPrintChar(const char c)
{
	writeLcdData(c);
}

// print a zero terminated character string
void lcdPrintStr(const char* str)
{
	int i = 0;
	while (str[i] != '\0' && i < 40)
	{
		lcdPrintChar(str[i]);
		i++;
	}
}

// clear display content
void lcdClear()
{
	writeLcdCmd(lcd_clear_cmd);
	lcdDelay();
}

static const unsigned char line_length = 0x40;
void lcdSetCursorPosition(char line, char pos)
{
	writeLcdCmd(lcd_set_cursor_pos_cmd | ((line_length*line) + pos));
}

// reset position of the read/write cursor
void lcdResetCursorPosition()
{
	writeLcdCmd(lcd_reset_cursor_pos_cmd);
}

// write a custom character to the character generator RAM
void lcdSetCustomChar(const unsigned char location, const unsigned char* pattern)
{
	 unsigned char i;
	if(location<8){
		writeLcdCmd(0x40+(location*8));
	for(i=0;i<8;i++)
		writeLcdData(pattern[i]);
	}
}