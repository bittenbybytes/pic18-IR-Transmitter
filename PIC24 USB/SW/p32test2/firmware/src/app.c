/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

#include "i2c2Master.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback funtions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
    initI2C2Master();
}

const uint8_t IODIRA = 0x00;
const uint8_t IODIRB = 0x01;

const uint8_t IOCON = 0x0A;

const uint8_t GPIOA = 0x12;
const uint8_t GPIOB = 0x13;

const uint8_t GPPUA = 0x0C;
const uint8_t GPPUB = 0x0D;

char numberPattern[] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F, // 9
  0x77, // A
  0x7C, // b
  0x39, // C
  0x5E, // d
  0x79, // E
  0x71, // F
  0x00, // Blank
  0x80, // dot
  0x40 // minus
};

void writeRegOLD(uint8_t address, uint8_t data)
{
    volatile int i = 0;
    while(!DRV_I2C0_MasterBusIdle());
   
    DRV_I2C0_MasterStart();
    DRV_I2C0_WaitForStartComplete();
    
    DRV_I2C0_ByteWrite((0x27));
    DRV_I2C0_WaitForByteWriteToComplete();
    
    DRV_I2C0_ByteWrite(address);
    DRV_I2C0_WaitForByteWriteToComplete();
    
    DRV_I2C0_ByteWrite(data);
    DRV_I2C0_WaitForByteWriteToComplete();
      LATFINV = 2;   
    DRV_I2C0_MasterStop();
    ///DRV_I2C0_WaitForStopComplete();
    for(i = 0; i < 0xffff; i++);

}

void writeReg(uint8_t address, uint8_t data)
{
    I2Cwrite((0x20 + 0x07) << 1, address, data);
}


#define abs(x) ((x<0) ? -x : x)

void toggleLedForever()
{   
    volatile int num = 0;
    
    writeReg(IODIRA, 0x00);
   // writeReg(GPPUA, 0xff);
        
    writeReg(IODIRB, 0x00);
    //writeReg(GPPUB, 0xff);
    
    DRV_ADC_Open();
    DRV_ADC_ChannelScanInputsAdd(DRV_ADC_INPUT_POSITIVE_AN11);
    DRV_ADC_Start();
    
    /* Open the Device Layer */
    
    LATF = 0;
    volatile int i = 0;
    while(1)
    {

        if(num%256 ==0)
            LATFINV = 0x00000002;
    
        for(i = 0; i < 0x3fff; i++);
        
        num++;
        
        static int adcVal = 0x1234;
        
       //  && (num%256 == 0))
       //   Nop();//adcVal = DRV_ADC_SamplesRead(0);
        if((num%256 == 0))
        {   
            adcVal++;
            if(DRV_ADC_SamplesAvailable())
            {
                adcVal = DRV_ADC_SamplesRead(0);
                DRV_ADC_Start();
            }
        }
        
        writeReg(GPIOA, 0x0F);
        
         char adcHexDigit = (adcVal >> (4*(num%4))) & 0xf;
        
        int voltage = (adcVal*3300) / 1024;
        
        int temp = (voltage - 500) / 10;
        
        char digit = 16;
        if ((num%4) == 1)
            digit = abs(temp) / 10;
        else if((num%4) == 0)
            digit = abs(temp) % 10;
        else if((num%4) == 2 && temp < 0)
            digit = 18;
        
        
        writeReg(GPIOB, ~(numberPattern[digit]));  
        
        writeReg(GPIOA, 0x0F & (~(1 << (num%4))));
    }
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            toggleLedForever();
            break;
        }

        /* TODO: implement your application state machine.*/

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}
 

/*******************************************************************************
 End of File
 */
