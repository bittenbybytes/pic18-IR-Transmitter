/* 
 * File:   
 * Author: Helmut Angerer / engscope.com
 * Comments: The code has been lifted from Engscope's basic PIC24F I2C tutorial
 *           and modified to use I2C2 on larger PIC32MX devices.
 *           (see: http://www.engscope.com/pic24-tutorial/10-2-i2c-basic-functions )
 * Revision history: 
 */

#include "i2c2Master.h"

//loop nops for delay
void DelayuSec(unsigned int N)
{
   unsigned int j=0;
   while(N > 0)
   {
      for(j=0;j < 200; j++);
      N--;
   }
}

//Resets the I2C bus to Idle
void reset_i2c_bus(void)
{
   int x = 0;

   //initiate stop bit
   I2C2CONbits.PEN = 1;

   //wait for hardware clear of stop bit
   while (I2C2CONbits.PEN)
   {
      DelayuSec(1);
      x ++;
      if (x > 20) break;
   }
   I2C2CONbits.RCEN = 0;
   IFS1bits.I2C2MIF = 0; // Clear Interrupt
   I2C2STATbits.IWCOL = 0;
   I2C2STATbits.BCL = 0;
   DelayuSec(10);
}

void initI2C2Master()
{
    int temp;
    
   // I2CBRG = 09 for 10Mhz PBCLK with 400kHz I2C clock
   I2C2BRG = 0x09;
   I2C2CONbits.I2CEN = 0;	// Disable I2C Mode
   I2C2CONbits.DISSLW = 1;	// Disable slew rate control
   IFS1bits.I2C2MIF = 0;	 // Clear Interrupt
   I2C2CONbits.I2CEN = 1;	// Enable I2C Mode
   temp = I2C2RCV;	 // read buffer to clear buffer full
   reset_i2c_bus();	 // set bus to idle
}

//function iniates a start condition on bus
void i2c_start(void)
{
   int x = 0;
   I2C2CONbits.ACKDT = 0;	//Reset any previous Ack
   DelayuSec(10);
   I2C2CONbits.SEN = 1;	//Initiate Start condition
   Nop();

   //the hardware will automatically clear Start Bit
   //wait for automatic clear before proceding
   while (I2C2CONbits.SEN)
   {
      DelayuSec(1);
      x++;
      if (x > 20)
      break;
   }
   DelayuSec(2);
}

void i2c_restart(void)
{
   int x = 0;

   I2C2CONbits.RSEN = 1;	//Initiate restart condition
   Nop();
    
   //the hardware will automatically clear restart bit
   //wait for automatic clear before proceding
   while (I2C2CONbits.RSEN)
   {
      DelayuSec(1);
      x++;
      if (x > 20)	break;
   }
    
   DelayuSec(2);
}

//basic I2C byte send
char send_i2c_byte(int data)
{
   int i;

   while (I2C2STATbits.TBF) { }
   IFS1bits.I2C2MIF = 0; // Clear Interrupt
   I2C2TRN = data; // load the outgoing data byte

   // wait for transmission
   for (i=0; i<500; i++)
   {
      if (!I2C2STATbits.TRSTAT) break;
      DelayuSec(1);

      }
      if (i == 500) {
      return(1);
   }

   // Check for NO_ACK from slave, abort if not found
   if (I2C2STATbits.ACKSTAT == 1)
   {
      reset_i2c_bus();
      return(1);
   }
   
   DelayuSec(2);
   return(0);
}

//function reads data, returns the read data, no ack
char i2c_read(void)
{
   int i = 0;
   char data = 0;

   //set I2C module to receive
   I2C2CONbits.RCEN = 1;

   //if no response, break
   while (!I2C2STATbits.RBF)
   {
      i ++;
      if (i > 2000) break;
   }

   //get data from I2CRCV register
   data = I2C2RCV;

   //return data
   return data;
}

//function reads data, returns the read data, with ack
char i2c_read_ack(void)	//does not reset bus!!!
{
   int i = 0;
   char data = 0;

   //set I2C module to receive
   I2C2CONbits.RCEN = 1;

   //if no response, break
   while (!I2C2STATbits.RBF)
   {
      i++;
      if (i > 2000) break;
   }

   //get data from I2CRCV register
   data = I2C2RCV;

   //set ACK to high
   I2C2CONbits.ACKEN = 1;

   //wait before exiting
   DelayuSec(10);

   //return data
   return data;
}

void I2Cwrite(char addr, char subaddr, char value)
{
   i2c_start();
   send_i2c_byte(addr);
   send_i2c_byte(subaddr);
   send_i2c_byte(value);
   reset_i2c_bus();
}

char I2Cread(char addr, char subaddr)
{
   char temp;
   
   i2c_start();
   send_i2c_byte(addr);
   send_i2c_byte(subaddr);
   DelayuSec(10);

   i2c_restart();
   send_i2c_byte(addr | 0x01);
   temp = i2c_read();

   reset_i2c_bus();
   return temp;
}