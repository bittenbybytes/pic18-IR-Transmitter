/* 
 * File:   midas_i2c_lcd.h
 * Author: h.angerer
 *
 * Created on 8. März 2014, 19:12
 */

#ifndef MIDAS_I2C_LCD_H
#define	MIDAS_I2C_LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * i2c_lcd.h
 *
 *  Created on: 28.07.2012
 *      Author: hele
 */

// Different options for display supply voltage
#define DISPLAY_5V_SUPPLY	0x00UL
#define DISPLAY_3V3_SUPPLY	0x01UL

//TODO: Double check those 2 defines, add lcd adress
#define LCD_ADDR	(0x3E << 1)
#define LCD_COMMAND		0x00UL
#define LCD_DATA	0x40UL

#define LCD_CLEAR	0x01
#define LCD_RETURN_HOME		0x02
#define LCD_ENTRY_MODE(inc, shift)	( (0x04 & ((inc != 0) << 1) | (shift != 0))))
#define LCD_DISPLAY_ON_OFF(display, cursor, cursor_blink)	( (0x08 | ((display != 0) << 2) | \
                                                                (cursor != 0) << 1) | (cursor_blink != 0))

#define LCD_FUNCTION_SET(if_8b, lcd_2line, double_height, instr_table1)\
				(0x20 | ((if_8b != 0) << 4) | ((lcd_2line != 0) << 3)\
				| ((double_height != 0) << 2) | (instr_table1 != 0))

#define LCD_SET_DDRAM_ADDRESS(address)	(0x80 | (address & 0x7F))

void initLcd(unsigned long ulOptions);
void printLcd(const char* cpStr);
void clearLcd();
void printStringLcd(const char* ucStr);
void write_cmd(unsigned char ucCtrl, unsigned char ucData);

#ifdef	__cplusplus
}
#endif

#endif	/* MIDAS_I2C_LCD_H */

