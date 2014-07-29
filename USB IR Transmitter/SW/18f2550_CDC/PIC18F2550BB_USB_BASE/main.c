// Open source PIC USB stack echo demo
// USB stack by JTR and Honken
// CC-BY
//
// USB driver files should be in '..\dp_usb\'
// Enter a USB VID and PID in prj_usb_config.h

//USB stack
#include "..\dp_usb\usb_stack_globals.h"    // USB stack only defines Not function related.
#include "descriptors.h"	// JTR Only included in main.c
#include "configwords.h"	// JTR only included in main.c
#include "delayss.h"
#include <stdio.h>
//#include "i2c.h"

// PIC18F Move reset vectors for bootloader compatibility
#define REMAPPED_RESET_VECTOR_ADDRESS		0x800
#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x808
#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x818

void SetupBoard(void);
void InterruptHandlerHigh();
void InterruptHandlerLow();
void USBSuspend(void);

void SetupPWM(void);

void EnablePWM(unsigned bEnable);

void putIR(BYTE data);

unsigned char PA, PB, clkF=0, DATA4=0,RS,RW;

#pragma udata
extern BYTE usb_device_state;

#pragma code
void main(void)
{
    BYTE data = 0;
    BYTE RecvdByte;
    BYTE buffer[16];
    unsigned bit = 0;
    long i = 0;
    ADCON1 = 0b00000100; // AN11-AN12 -> digital IO
    TRISBbits.TRISB4 = 0;
    PORTBbits.RB4 = 1;

    initCDC(); // setup the CDC state machine
    SetupBoard(); //setup the hardware, customize for your hardware
    usb_init(cdc_device_descriptor, cdc_config_descriptor, cdc_str_descs, USB_NUM_STRINGS); // initialize USB. TODO: Remove magic with macro
    usb_start(); //start the USB peripheral

    PORTBbits.RB4 = 0;

// PIC18 INTERRUPTS
// It is the users resposibility to set up high, low or legacy mode
// interrupt operation. The following macros for high and low interrupt
// setup have been removed:

//#define EnableUsbHighPriInterrupt()             do { RCONbits.IPEN = 1; IPR2bits.USBIP = 1; INTCONbits.GIEH = 1;} while(0) // JTR new
//#define EnableUsbLowPriInterrupt()              do { RCONbits.IPEN = 1; IPR2bits.USBIP = 0; INTCONbits.GIEL = 1;} while(0)  // JTR new

// By default, the interrupt mode will be LEGACY (ISR Vector 0x08)
// (Same as high priority vector wise but the operation (latency) is
// not the same. Consult the data sheet for details.)

// If a priority mode is enabled then this affects ALL other interrupt
// sources therefore it does not belong to the usb stack to be
// doing this. It is a global, user application choice.

    EnableUsbPerifInterrupts(USB_TRN + USB_SOF + USB_UERR + USB_URST);
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    EnableUsbGlobalInterrupt(); // Only enables global USB interrupt. Chip interrupts must be enabled by the user (PIC18)



// Wait for USB to connect
    do {
    } while (usb_device_state < CONFIGURED_STATE);

    usb_register_sof_handler(CDCFlushOnTimeout); // Register our CDC timeout handler after device configured

    PORTBbits.RB4 = 1;
    SetupPWM();

// Main echo loop
    do 
	{
		//Enter code here
		// Receive and send method 2
		// Same as poll_getc_cdc except that byte is NOT removed from queue.
		//This function will wait for a byte and return and remove it from the queue when it arrives.
        if (peek_getc_cdc(&RecvdByte)) { 
            RecvdByte = getc_cdc(); 
            putIR(RecvdByte);
            //putc_cdc('k');
            data++;
            sprintf(buffer,"TX #%i\n\r",data);
            for(i=0; i<strlen(buffer); i++)
                putc_cdc(buffer[i]);
            PORTBbits.RB4 = 0;
            Delay10KTCYx(20);
            PORTBbits.RB4 = 1;
        }
    } while (1);

} //end main

void SetupPWM(void){
     // Tosc = 48 Mhz = 21ns 
     // PWM Period = 4 x 21ns x 79 x 4 = 26.5us 
     // PWM Frequency = 1/PWM Period = 1/26.5us = 37.7 kHz 
     TRISCbits.RC1 = 1; //set TRIS bit
     PR2 = 79; // load with PWM period value (fixed at 3.7 kHz) 
     CCP2CON = 0b00001100; // setup for PWM mode 5:4 are PWM Duty Cycle LSB
     CCPR2L = (79/2); // (50% duty cycle)
     T2CON = 0b00000101; // Timer2 On, 1:1 Post, 4x prescale
     TRISCbits.RC1 = 0; // clear TRIS bit
     
     TRISCbits.RC2 = 1; //set TRIS bit
     CCP1CON = 0b00001100; // setup for PWM mode 5:4 are PWM Duty Cycle LSB
     CCPR1L = (79/4); // (25% duty cycle)
     TRISCbits.RC2 = 0; // clear TRIS bit
}

void EnablePWM(unsigned bEnable){
    // en/disable timer
    T2CONbits.TMR2ON = bEnable;
    // en/disable PWM
    CCP2CON = bEnable ? 0b00001100 : 0; // clearing CCPxCON clear output pin
}

void bit_delay(){
    Delay1KTCYx(20);
}

#define bit_delay() Delay1KTCYx(80)

#define NON_MODULATED_UART_TX_PORT_PIN PORTCbits.RC0
#define NON_MODULATED_UART_TX_TRIS_PIN TRISCbits.RC0


void putIR(BYTE data)
{
    int i = 0;
   // const unsigned short long tbit_us = 1666; // bit duration in us (1 / baud rate: 1/600 = 1666.7)
    NON_MODULATED_UART_TX_TRIS_PIN = 0; // clear TRIS bit

    // Start bit
    EnablePWM(1);
    NON_MODULATED_UART_TX_PORT_PIN = 0;
    //delay_us(tbit_us);
    bit_delay();

    for(i=0;i<8;i++){
        EnablePWM(!((data >> i) & 0x01));
        NON_MODULATED_UART_TX_PORT_PIN = ((data >> i) & 0x01);
        //delay_us(tbit_us);
        bit_delay();
    }

    // Stop bit
    EnablePWM(0);
    NON_MODULATED_UART_TX_PORT_PIN = 1;
    //delay_us(tbit_us);
    bit_delay();
}

/////////////////////////////////////////////////////////////////////////////
//board hardware setup
//add your hardware here
void SetupBoard(void) {
    //disable some defaults
    ADCON1 |= 0b1111; //all pins digital
    CVRCON = 0b00000000;
}

// USB suspend not yet enabled
void USBSuspend(void) {}

//interrupt routines for PIC 18 and PIC24
//	Interrupt remap chain
//
//This function directs the interrupt to
// the proper function depending on the mode
// set in the mode variable.
//USB stack on low priority interrupts,
#pragma interruptlow InterruptHandlerLow nosave= PROD, PCLATH, PCLATU, TBLPTR, TBLPTRU, TABLAT, section (".tmpdata"), section("MATH_DATA")
void InterruptHandlerLow(void) {
   if(PIR2bits.USBIF)//usb interrupt
	{
		usb_handler();
   		ClearGlobalUsbInterruptFlag();
	}
}

#pragma interrupt InterruptHandlerHigh nosave= PROD, PCLATH, PCLATU, TBLPTR, TBLPTRU, TABLAT, section (".tmpdata"), section("MATH_DATA")
void InterruptHandlerHigh(void) { //Also legacy mode interrupt.
   if(PIR2bits.USBIF)//usb interrupt
	{
	usb_handler();
    ClearGlobalUsbInterruptFlag();
	}
}

//these statements remap the vector to our function
//When the interrupt fires the PIC checks here for directions
#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS

void Remapped_High_ISR(void) {
    _asm goto InterruptHandlerHigh _endasm
}

#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS

void Remapped_Low_ISR(void) {
    _asm goto InterruptHandlerLow _endasm
}

//relocate the reset vector
extern void _startup(void);
#pragma code REMAPPED_RESET_VECTOR = REMAPPED_RESET_VECTOR_ADDRESS

void _reset(void) {
    _asm goto _startup _endasm
}
//set the initial vectors so this works without the bootloader too.
#pragma code HIGH_INTERRUPT_VECTOR = 0x08

void High_ISR(void) {
    _asm goto REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS _endasm
}
#pragma code LOW_INTERRUPT_VECTOR = 0x18

void Low_ISR(void) {
    _asm goto REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS _endasm
}

#pragma code


