
/* 
 * File:   
 * Author: Helmut Angerer / engscope.com
 * Comments: The code has been lifted from Engscope's basic PIC24F I2C tutorial
 *           and modified to use I2C2 on larger PIC32MX devices.
 *           (see: http://www.engscope.com/pic24-tutorial/10-2-i2c-basic-functions )
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef I2C2MASTER_H
#define	I2C2MASTER_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
void initI2C2Master();

void I2Cwrite(char addr, char subaddr, char value);

char I2Cread(char addr, char subaddr);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* I2C2MASTER_H */

