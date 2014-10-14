/* 
 * File:   char_lcd_hd44780.h
 * Author: hele
 *
 * Created on 14. Oktober 2014, 19:49
 * Summary: driver for using generic HD44780 compatible character LCDs
 */

#ifndef CHAR_LCD_HD44780_H
#define	CHAR_LCD_HD44780_H

#ifdef	__cplusplus
extern "C"
{
#endif

// initialize display
void initHD44780LCD();

// print a zero terminated character string
void lcdPrint(const char* str);

// clear display content
void lcdClear();

// reset position of the read/write cursor
void lcdResetCursorPosition();

#ifdef	__cplusplus
}
#endif

#endif	/* CHAR_LCD_HD44780_H */

