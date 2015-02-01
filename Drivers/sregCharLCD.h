/* 
 * File:   sregCharLCD.h
 * Author: hele
 *
 * Created on 18. Jänner 2015, 13:54
 */

#ifndef SREGCHARLCD_H
#define	SREGCHARLCD_H

#ifdef	__cplusplus
extern "C"
{
#endif

// initialize display
void initHD44780LCD();

// print a single character
void lcdPrintChar(const char c);

// print a zero terminated character string
void lcdPrintStr(const char* str);

// clear display content
void lcdClear();

// set cursor position
void lcdSetCursorPosition(char line, char pos);

// reset position of the read/write cursor
void lcdResetCursorPosition();

// write a custom character to the character generator RAM
void lcdSetCustomChar(const unsigned char location, const unsigned char* pattern);

#ifdef	__cplusplus
}
#endif

#endif	/* SREGCHARLCD_H */

