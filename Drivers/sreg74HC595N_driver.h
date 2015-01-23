/* 
 * File:   sreg74HC595N_driver.h
 * Author: hele
 *
 * Created on 18. Jänner 2015, 12:48
 */

#ifndef SREG74HC595N_DRIVER_H
#define	SREG74HC595N_DRIVER_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include "arduino_GPIO.h"

// pin out definition
extern const int pclk;
extern const int sclk;
extern const int ser;

void writeSregBit(char nbit, char input);
void writeSreg(unsigned char data);
void initSregIO();
void writeSregLowNibble(char nibble);

#ifdef	__cplusplus
}
#endif

#endif	/* SREG74HC595N_DRIVER_H */

