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

inline void MatrixDisplayMultiplexingTask();

#define LED_MATRIX_NUM_OF_ROWS 7

extern volatile uint8_t display[LED_MATRIX_NUM_OF_ROWS];

#ifdef	__cplusplus
}
#endif

#endif	/* LEDMATRIXDISPLAY_H */

