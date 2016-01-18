/* 
 * File:   LedMatrixDisplay.h
 * Author: hele
 *
 * Created on 14. September 2014, 17:51
 */

#ifndef LEDMATRIXDISPLAY_H
#define	LEDMATRIXDISPLAY_H

#ifdef	__cplusplus
extern "C"
{
#endif

void InitMatrixDisplay();

void InitMatrixDisplayGPIO();

inline void MatrixDisplayMultiplexingTask();

// display a 2 digit (5 by 3 pixel) decimal number on a single 5x7 display
void Display2Digit5x3Num(int8_t num);

// display a 2 digit (5 by 3 pixel) hexadecimal number on a single 5x7 display
void Display2Digit5x3Hex(uint8_t num);

#define LED_MATRIX_NUM_OF_ROWS 7

extern volatile uint8_t display[LED_MATRIX_NUM_OF_ROWS];

#ifdef	__cplusplus
}
#endif

#endif	/* LEDMATRIXDISPLAY_H */

