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

// pin out definition
#define pclk 0
#define sclk 1
#define ser 2

void writeSregBit(int nbit, int input);
void writeSreg(unsigned char data);
void initSregIO();
void writeSregLowNibble(int nibble);

#ifdef	__cplusplus
}
#endif

#endif	/* SREG74HC595N_DRIVER_H */

