/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "char_lcd_hd44780.h"

void lcdDelay()
{
	uint16_t i =0;
	for	(i =0; i < 0x4ff; i++);
}

#define LCD_ENABLE (PORTEbits.RE6)
#define LCD_RS (PORTEbits.RE7)
#define LCD_WRITE_NIBBLE(nibble) (PORTE |= ((nibble & 0xf) << 0))

#define LCD_TOGGLE() {LCD_ENABLE = 0; lcdDelay();  LCD_ENABLE = 1; lcdDelay();}

void lcdWriteCommand(char cmd)
{
	LCD_RS = 0;
	LCD_WRITE_NIBBLE(cmd >> 4);
	LCD_TOGGLE();
	LCD_WRITE_NIBBLE(cmd);
	LCD_TOGGLE();
}

void lcdWriteData(char data)
{
	LCD_RS = 1;
	LCD_WRITE_NIBBLE(data >> 4);
	LCD_TOGGLE();
	LCD_WRITE_NIBBLE(data);
	LCD_TOGGLE();
}


void lcdClear()
{
	lcdWriteCommand(0x01);
}

void lcdResetCursorPosition()
{
	lcdWriteCommand(0x02);
}

void lcdPrint(const char* str)
{
	uint16_t i = 0;
	while(str[i] != 0)
		lcdWriteData(str[i++]);
}

void initHD44780LCD()
{
	TRISE = 0x00;

	// Set 4 bit mode
	LCD_RS = 0;
	LCD_ENABLE = 1;
	lcdDelay();
	lcdDelay();
	LCD_WRITE_NIBBLE(0x02);
	LCD_TOGGLE();

	// Function set, 8 bit
	lcdWriteCommand(0x28);

	// Display ON, Cursor On, Cursor Blinking
	lcdWriteCommand(0x0f);

	// Entry Mode, Increment cursor position, No display shift
	lcdWriteCommand(0x06);
}
