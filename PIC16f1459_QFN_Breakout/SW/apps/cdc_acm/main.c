/*
 * USB CDC-ACM Demo
 *
 * This file may be used by anyone for any purpose and may be used as a
 * starting point making your own application using M-Stack.
 *
 * It is worth noting that M-Stack itself is not under the same license as
 * this file.
 *
 * M-Stack is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  For details, see sections 7, 8, and 9
 * of the Apache License, version 2.0 which apply to this file.  If you have
 * purchased a commercial license for this software from Signal 11 Software,
 * your commerical license superceeds the information in this header.
 *
 * Alan Ott
 * Signal 11 Software
 * 2014-05-12
 */

#include "usb.h"
#include <xc.h>
#include <string.h>
#include "usb_config.h"
#include "usb_ch9.h"
#include "usb_cdc.h"


#ifdef __PIC24FJ256GB106__

// pic 24 board only hardware

#include "LedMatrixDisplay.h"

#include <adc.h>
#endif

#ifdef __PIC32MX__
	#include <plib.h>
#endif

#ifdef __PIC24FJ64GB002__
_CONFIG1(WDTPS_PS16 & FWPSA_PR32 & WINDIS_OFF & FWDTEN_OFF & ICS_PGx1 & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
_CONFIG2(POSCMOD_NONE & I2C1SEL_PRI & IOL1WAY_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_FRCPLL & PLL96MHZ_ON & PLLDIV_NODIV & IESO_OFF)
_CONFIG3(WPFP_WPFP0 & SOSCSEL_IO & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM)
_CONFIG4(DSWDTPS_DSWDTPS3 & DSWDTOSC_SOSC & RTCOSC_SOSC & DSBOREN_OFF & DSWDTEN_OFF)

#elif __PIC24FJ256GB106__

// PIC24FJ256GB106 Configuration Bit Settings

// CONFIG3
#pragma config WPFP = WPFP511           // Write Protection Flash Page Segment Boundary (Highest Page (same as page 170))
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable bit (Segmented code protection disabled)
#pragma config WPCFG = WPCFGDIS         // Configuration Word Code Page Protection Select bit (Last page(at the top of program memory) and Flash configuration words are not protected)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select bit (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMOD = HS             // Primary Oscillator Select (HS oscillator mode selected)
#pragma config DISUVREG = OFF           // Internal USB 3.3V Regulator Disable bit (Regulator is disabled)
#pragma config IOL1WAY = OFF            // IOLOCK One-Way Set Enable bit (Unlimited Writes To RP Registers)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSCO functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-safe Clock Monitor are disabled)
#pragma config FNOSC = PRIPLL           // Oscillator Select (Primary oscillator (XT, HS, EC) with PLL module (XTPLL,HSPLL, ECPLL))
#pragma config PLL_96MHZ = ON           // 96MHz PLL Disable (Enabled)
#pragma config PLLDIV = DIV3            // USB 96 MHz PLL Prescaler Select bits (Oscillator input divided by 3 (12MHz input))
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-speed start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = ON              // Watchdog Timer Enable (Watchdog Timer is enabled)
#pragma config ICS = PGx2               // Comm Channel Select (Emulator functions are shared with PGEC2/PGED2)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG port is disabled)

#elif __PIC24FJ256DA206__
_CONFIG1(WDTPS_PS32768 & FWPSA_PR128 & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
_CONFIG2(POSCMOD_NONE & IOL1WAY_OFF & OSCIOFNC_ON & FCKSM_CSECMD & FNOSC_FRCPLL & PLL96MHZ_ON & PLLDIV_NODIV & IESO_OFF)
_CONFIG3(WPFP_WPFP255 & SOSCSEL_SOSC & WUTSEL_LEG & ALTPMP_ALPMPDIS & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM)

#elif _18F46J50
#pragma config PLLDIV = 3 /* 3 = Divide by 3. 12MHz crystal => 4MHz */
#pragma config XINST = OFF
#pragma config WDTEN = OFF
#pragma config CPUDIV = OSC1
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LPT1OSC = OFF
#pragma config T1DIG = ON
#pragma config OSC = ECPLL
#pragma config DSWDTEN = OFF
#pragma config IOL1WAY = OFF
#pragma config WPDIS = OFF /* This pragma seems backwards */

#elif _16F1459
#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config CLKOUTEN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config WRT = OFF
#pragma config CPUDIV = NOCLKDIV
#pragma config USBLSCLK = 48MHz
#pragma config PLLMULT = 3x
#pragma config PLLEN = ENABLED
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LPBOR = ON
#pragma config LVP = OFF

#elif _16F1454
#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config CLKOUTEN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config WRT = OFF
#pragma config CPUDIV = NOCLKDIV
#pragma config USBLSCLK = 48MHz
#pragma config PLLMULT = 3x
#pragma config PLLEN = ENABLED
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LPBOR = ON
#pragma config LVP = OFF

#elif __32MX460F512L__
#pragma config DEBUG = OFF, ICESEL = ICS_PGx2, PWP = OFF, BWP = OFF, CP = OFF
#pragma config FNOSC = PRIPLL, FSOSCEN = OFF, IESO = OFF, POSCMOD = HS, \
	       OSCIOFNC = OFF, FPBDIV = DIV_1, FCKSM = CSDCMD, WDTPS = PS1, \
	       FWDTEN = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_15, UPLLIDIV = DIV_2, \
	       UPLLEN = ON, FPLLODIV = DIV_1

#else
	#error "Config flags for your device not defined"

#endif

#ifdef MULTI_CLASS_DEVICE
static uint8_t cdc_interfaces[] = { 0 };
#endif

static void send_string_sync(uint8_t endpoint, const char *str)
{
	char *in_buf = (char*) usb_get_in_buffer(endpoint);

	while (usb_in_endpoint_busy(endpoint))
		;

	strcpy(in_buf, str);
	/* Hack: Get the length from strlen(). This is inefficient, but it's
	 * just a demo. strlen()'s return excludes the terminating NULL. */
	usb_send_in_buffer(endpoint, strlen(in_buf));
}

#ifdef __PIC24FJ256GB106__

// pic 24 board only hardware

void initADC()
{
	AD1CON1bits.SSRC = 0b111; // SSRC<3:0> = 111 implies internal
	// counter ends sampling and starts
	// converting.
	AD1CON3 = 0x1F00 | ADC_CONV_CLK_64Tcy; // Sample time = 31Tad

	AD1CON1bits.ADON = 1; // turn ADC on
}

unsigned short readADC(unsigned short ch)
{

	// select channel
	AD1CHS = ch;

	AD1CON1bits.DONE = 0; //resets DONE bit
	AD1CON1bits.SAMP = 1; //start sample
	while (!AD1CON1bits.DONE);
	return ADC1BUF0;
}

#endif


#ifdef _16F1459
void initADC()
{

	// setup Fixed Voltage Reference

	FVRCONbits.FVREN = 1; // enable
	FVRCONbits.ADFVR = 1; // ADC VRef (0=off, 1=1024mV, 2=2048mV, 4=4096mV)
	
	// setup ADC

	ADCON1bits.ADFM = 1; // result right justified?
	ADCON1bits.ADCS = 7; // ADC Clock source (7 = FRC)
	ADCON1bits.ADPREF = 3; // Vref+ (0 = VDD, 3 = Fixed Voltage Reference)

	ADCON0bits.ADON = 1;

	// setup RA4 / AN3 as analog in

	TRISAbits.TRISA4 = 1;
	ANSELAbits.ANSA4 = 1;

	ADCON0bits.CHS = 3;
}

short readADC()
{
	short result = 0;

	ADCON0bits.ADGO = 1;

	while(ADCON0bits.GO_nDONE);

	result = ADRESH;
	result <<= 8;
	result += ADRESL;

	return result;
}

#endif


int main(void)
{
#if defined(__PIC24FJ64GB002__)  || defined(__PIC24FJ256DA206__)
	unsigned int pll_startup_counter = 600;
	CLKDIVbits.PLLEN = 1;
	while(pll_startup_counter--);

#elif __PIC24FJ256GB106__
		/* When clock switch occurs switch to Prim Osc (HS, XT, EC)with PLL */
	__builtin_write_OSCCONH(0x03); /* Set OSCCONH for clock switch */
	__builtin_write_OSCCONL(0x01); /* Start clock switching */
	while (OSCCONbits.COSC != 0b011);

	/* Wait for Clock switch to occur */
	/* Wait for PLL to lock, if PLL is used */
	while(OSCCONbits.LOCK != 1);
	
#elif _18F46J50
	unsigned int pll_startup = 600;
	OSCTUNEbits.PLLEN = 1;
	while (pll_startup--)
		;
#elif _16F1459 || _16F1454
	OSCCONbits.IRCF = 0b1111; /* 0b1111 = 16MHz HFINTOSC postscalar */

	/* Enable Active clock-tuning from the USB */
	ACTCONbits.ACTSRC = 1; /* 1=USB */
	ACTCONbits.ACTEN = 1;

	initADC();

#elif __32MX460F512L__
	SYSTEMConfigPerformance(80000000);
#endif


/* Configure interrupts, per architecture */
#ifdef USB_USE_INTERRUPTS
	#if defined (_PIC18) || defined(_PIC14E)
		INTCONbits.PEIE = 1;
		INTCONbits.GIE = 1;
	#elif __PIC32MX__
		INTCONbits.MVEC = 1; /* Multi-vector interrupts */
		IPC11bits.USBIP = 4; /* Interrupt priority, must set to != 0. */
		__asm volatile("ei");
	#endif
#endif

#ifdef MULTI_CLASS_DEVICE
	cdc_set_interface_list(cdc_interfaces, sizeof(cdc_interfaces));
#endif
	usb_init();

	uint8_t char_to_send = 'A';
	bool send = true;
	bool loopback = false;
	bool displayTemperature = true;

#ifdef __PIC24FJ256GB106__

// pic 24 board only hardware
	InitMatrixDisplayGPIO();

	AD1PCFG = 0xFFFF; // Default all pins to digital

	AD1PCFGLbits.PCFG11 = 0; //Disable digital input on AN11

	initADC();

	TRISFbits.TRISF1 = 0;
	LATFbits.LATF1 = 1;
#endif

	uint16_t num = 0;
	while (1) {

#ifdef __PIC24FJ256GB106__

// pic 24 board only hardware
		if(!(num++ % 32768))
		{
			LATFbits.LATF1 = !PORTFbits.RF1;
			
			if(displayTemperature)
			{
				uint16_t result = readADC(11);
				int16_t voltage = ((uint32_t) (result) * 3300) / 1023;
				int8_t temp = (((voltage - 500) / 5) + 1) / 2;
				Display2Digit5x3Num(temp);
			}
		}

		MatrixDisplayMultiplexingTask();
#endif

		/* Send data to the PC */
		if (usb_is_configured() &&
		    !usb_in_endpoint_halted(2) &&
		    !usb_in_endpoint_busy(2) && send) {

			int i;
			unsigned char *buf = usb_get_in_buffer(2);
#if defined (_16F1459)
			
			i = 0;
			buf[i++] = 'A';
			buf[i++] = 'N';
			buf[i++] = '3';
			buf[i++] = ':';

			short result = readADC();
			char str[6] = {0};
			itoa(str,result, 10);
			int j=0;
			
			while(str[j] != '\0')
				buf[i++] = str[j++];

			buf[i++] = 'm';
			buf[i++] = 'V';

#else
			for (i = 0; i < 16; i++) {
				buf[i] = char_to_send++;
				if (char_to_send > 'Z')
					char_to_send = 'A';
			}
#endif
			buf[i++] = '\r';
			buf[i++] = '\n';
			usb_send_in_buffer(2, i);

		}

		/* Handle data received from the host */
		if (usb_is_configured() &&
		    !usb_out_endpoint_halted(2) &&
		    usb_out_endpoint_has_data(2)) {
			const unsigned char *out_buf;
			size_t out_buf_len;
			int i;

			/* Check for an empty transaction. */
			out_buf_len = usb_get_out_buffer(2, &out_buf);
			if (out_buf_len <= 0)
				goto empty;

			if (send) {
				/* Stop sendng if a key was hit. */
				send = false;
				send_string_sync(2, "Data send off ('h' for help)\r\n");
			}
			else if (loopback) {
				/* Loop data back to the PC */

				/* Wait until the IN endpoint can accept it */
				while (usb_in_endpoint_busy(2))
					;

				/* Copy contents of OUT buffer to IN buffer
				 * and send back to host. */
				memcpy(usb_get_in_buffer(2), out_buf, out_buf_len);
				usb_send_in_buffer(2, out_buf_len);

				/* Send a zero-length packet if the transaction
				 * length was the same as the endpoint
				 * length. This is for demo purposes. In real
				 * life, you only need to do this if the data
				 * you're transferring ends on a multiple of
				 * the endpoint length. */
				if (out_buf_len == EP_2_LEN) {
					/* Wait until the IN endpoint can accept it */
					while (usb_in_endpoint_busy(2))
						;
					usb_send_in_buffer(2, 0);
				}

				/* Scan for ~ character to end loopback mode */
				for (i = 0; i < out_buf_len; i++) {
					if (out_buf[i] == '~') {
						loopback = false;
						send_string_sync(2, "\r\nLoopback off ('h' for help)\r\n");
						break;
					}
				}
			}
			else {
				/* Scan for commands if not in loopback or
				 * send mode.
				 *
				 * This is a hack. One should really scan the
				 * entire string. In this case, since this
				 * is a demo, assume that the user is using
				 * a terminal program and typing the input,
				 * all but ensuring the data will come in
				 * single-character transactions. */
				if (out_buf[0] == 'h' || out_buf[0] == '?') {
					/* Show help.
					 * Make sure to not try to send more
					 * than 63 bytes of data in one
					 * transaction */
					send_string_sync(2,
						"\r\nHelp:\r\n"
						"\ts: send data\r\n"
						"\tl: loopback\r\n");
					send_string_sync(2,
						"\tn: send notification\r\n"
						"\th: help\r\n");
				}
				else if (out_buf[0] == 's')
					send = true;
				else if (out_buf[0] == 'l') {
					loopback = true;
					send_string_sync(2, "loopback enabled; press ~ to disable\r\n");
				}
				else if (out_buf[0] == 'd') {
					displayTemperature = false;
#ifdef __PIC24FJ256GB106__

// pic 24 board only hardware
					Display2Digit5x3Num(out_buf[2]);
#endif
					send_string_sync(2, "char hex display\r\n");
				}
				else if (out_buf[0] == 't') {
					displayTemperature = true;
					send_string_sync(2, "display temperature\r\n");
				}
				else if (out_buf[0] == 'n') {
					/* Send a Notification on Endpoint 1 */
					struct cdc_serial_state_notification *n =
						(struct cdc_serial_state_notification *)
							usb_get_in_buffer(1);

					n->header.REQUEST.bmRequestType = 0xa1;
					n->header.bNotification = CDC_SERIAL_STATE;
					n->header.wValue = 0;
					n->header.wIndex = 1; /* Interface */
					n->header.wLength = 2;
					n->data.serial_state = 0; /* Zero the whole bit mask */
					n->data.bits.bRxCarrier = 1;
					n->data.bits.bTxCarrier = 1;
					n->data.bits.bBreak = 0;
					n->data.bits.bRingSignal = 0;
					n->data.bits.bFraming = 0;
					n->data.bits.bParity = 0;
					n->data.bits.bOverrun = 0;

					/* Wait for the endpoint to be free */
					while (usb_in_endpoint_busy(1))
						;

					/* Send to to host */
					usb_send_in_buffer(1, sizeof(*n));

					send_string_sync(2, "Notification Sent\r\n");
				}
			}
empty:
			usb_arm_out_endpoint(2);
		}



		#ifndef USB_USE_INTERRUPTS
		usb_service();
		#endif
	}

	return 0;
}

/* Callbacks. These function names are set in usb_config.h. */
void app_set_configuration_callback(uint8_t configuration)
{

}

uint16_t app_get_device_status_callback()
{
	return 0x0000;
}

void app_endpoint_halt_callback(uint8_t endpoint, bool halted)
{

}

int8_t app_set_interface_callback(uint8_t interface, uint8_t alt_setting)
{
	return 0;
}

int8_t app_get_interface_callback(uint8_t interface)
{
	return 0;
}

void app_out_transaction_callback(uint8_t endpoint)
{

}

void app_in_transaction_complete_callback(uint8_t endpoint)
{

}

int8_t app_unknown_setup_request_callback(const struct setup_packet *setup)
{
	/* To use the CDC device class, have a handler for unknown setup
	 * requests and call process_cdc_setup_request() (as shown here),
	 * which will check if the setup request is CDC-related, and will
	 * call the CDC application callbacks defined in usb_cdc.h. For
	 * composite devices containing other device classes, make sure
	 * MULTI_CLASS_DEVICE is defined in usb_config.h and call all
	 * appropriate device class setup request functions here.
	 */
	return process_cdc_setup_request(setup);
}

int16_t app_unknown_get_descriptor_callback(const struct setup_packet *pkt, const void **descriptor)
{
	return -1;
}

void app_start_of_frame_callback(void)
{

}

void app_usb_reset_callback(void)
{

}

/* CDC Callbacks. See usb_cdc.h for documentation. */

int8_t app_send_encapsulated_command(uint8_t interface, uint16_t length)
{
	return -1;
}

int16_t app_get_encapsulated_response(uint8_t interface,
                                      uint16_t length, const void **report,
                                      usb_ep0_data_stage_callback *callback,
                                      void **context)
{
	return -1;
}

void app_set_comm_feature_callback(uint8_t interface,
                                     bool idle_setting,
                                     bool data_multiplexed_state)
{

}

void app_clear_comm_feature_callback(uint8_t interface,
                                       bool idle_setting,
                                       bool data_multiplexed_state)
{

}

int8_t app_get_comm_feature_callback(uint8_t interface,
                                     bool *idle_setting,
                                     bool *data_multiplexed_state)
{
	return -1;
}

void app_set_line_coding_callback(uint8_t interface,
                                    const struct cdc_line_coding *coding)
{

}

int8_t app_get_line_coding_callback(uint8_t interface,
                                    struct cdc_line_coding *coding)
{
	/* This is where baud rate, data, stop, and parity bits are set. */
	return -1;
}

int8_t app_set_control_line_state_callback(uint8_t interface,
                                           bool dtr, bool dts)
{
	return 0;
}

int8_t app_send_break_callback(uint8_t interface, uint16_t duration)
{
	return 0;
}


#ifdef _PIC14E
void interrupt isr()
{
	usb_service();
}
#elif _PIC18

#ifdef __XC8
void interrupt high_priority isr()
{
	usb_service();
}
#elif _PICC18
#error need to make ISR
#endif

#endif
