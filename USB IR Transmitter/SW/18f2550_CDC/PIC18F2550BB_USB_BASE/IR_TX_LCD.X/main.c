/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdio.h>
#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "midas_i2c_lcd.h"
#include "i2c.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

short readTCN75(const unsigned char addr);
void resetLcd();

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    // toggle lcd reset low
    resetLcd();

    initLcd(DISPLAY_5V_SUPPLY);

    ADCON0 = 0b00000101; // enable ADC, mux to AN1
    ADCON1 = 0b00001101; // AN0 - AN1 analog in, supply rails as reference
    ADCON2 = 0b00000001;
    //         0-------     left justified result
    //         --010---     TAD delay before reading
    //         -----011     A2C clock is Fosc/xx

    TRISAbits.TRISA3 = 0; // Output
    PORTAbits.RA3 = 0; // GND

    clearLcd();

    printStringLcd( "Hello World \n"
                    "Motherfucker ");

    write_cmd(LCD_COMMAND, LCD_DISPLAY_ON_OFF(1,0,0));
    int count = 10000;
    char str[33] = {0};
    while(1)
    {
        LED_PORTBIT = LED_ON;
        for(int i=0; i<0x3ff; i++);
        LED_PORTBIT = LED_OFF;
        for(int i=0; i<0x3ff; i++);
        char temp = readTCN75(0b111);
        ADCON0bits.GO_NOT_DONE = 1;
        while(ADCON0bits.GO_NOT_DONE);
        clearLcd();
        sprintf(str,"cnt: %06i \n %i degC, %i", count, temp, ADRESH);
        printStringLcd(str);
        count++;
        
    }
}

void resetLcd()
{
    LCD_RESET_N_PORTBIT = 0;
    for(int i=0; i<0x8ff; i++);
    LCD_RESET_N_PORTBIT = 1;
}

short readTCN75(const unsigned char addr)
{
        /* Write SLA(W), address and one data byte */
    IdleI2C();                         // Wait until the bus is idle
    StartI2C();                        // Send START condition
    IdleI2C();                         // Wait for the end of the START condition
    WriteI2C( 0b10010000 | (addr << 1) );  // Send address with R/W cleared for write
    IdleI2C();                         // Wait for ACK
    WriteI2C( 1 );               // Write first byte of data
    IdleI2C();                         // Wait for ACK

    RestartI2C();
    IdleI2C();                         // Wait for the end of the START condition
    WriteI2C( 0b10010001 | (addr << 1) );  // Send address with R/W set for read
    IdleI2C();                         // Wait for ACK
    char tmpHi = ReadI2C();
    //AckI2C();
    //char tmpLo = ReadI2C();
    NotAckI2C();
    StopI2C();

    return tmpHi;
}