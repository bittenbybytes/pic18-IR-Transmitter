
#include "midas_i2c_lcd.h"
#include "i2c.h"

#define INIT_SEQ_LENGTH		8UL

static unsigned char uc5VSupplyInitSequence[] = {   0x38,
                                                    0x39,
                                                    0x14,
                                                    0x79,
                                                    0x50,
                                                    0x6c,
                                                    0x0f,
                                                    0x01
                                            };

static unsigned char uc3V3SupplyInitSequence[] = {0x38,
                                                0x39,
                                                0x14,
                                                0x74,
                                                0x54,
                                                0x6f,
                                                0x0c,
                                                0x01
                                        };

#define LCD_I2C_BASE	I2C1_BASE

void DrecksDelay(unsigned long ulDur)
{
	volatile unsigned long i;

	for(i = 0; i < ulDur; i++);

	return;
}


void write_cmd(unsigned char ucCtrl, unsigned char ucData)
{
    /* Write SLA(W), address and one data byte */
    IdleI2C();                         // Wait until the bus is idle
    StartI2C();                        // Send START condition
    IdleI2C();                         // Wait for the end of the START condition
    WriteI2C( LCD_ADDR );  // Send address with R/W cleared for write
    IdleI2C();                         // Wait for ACK
    WriteI2C( ucCtrl );               // Write first byte of data
    IdleI2C();                         // Wait for ACK
    WriteI2C( ucData );               // Write nth byte of data
    IdleI2C();                         // Wait for ACK
    StopI2C();                         // Hang up, send STOP condition
}

void initI2C()
{
    OpenI2C(MASTER, SLEW_ON);
}

int checkLcdBusy()
{
	// TODO: read function
	return 1;
}

void initLcd(unsigned long ulOptions)
{
	unsigned char* ucInitSequence;
	int i = 0;

	initI2C();

	if (ulOptions == DISPLAY_5V_SUPPLY)
		ucInitSequence = uc5VSupplyInitSequence;
	else
		ucInitSequence = uc3V3SupplyInitSequence;

	for (i = 0; i < INIT_SEQ_LENGTH; i++)
		write_cmd(LCD_COMMAND, ucInitSequence[i]);
}

void clearLcd()
{
	write_cmd(LCD_COMMAND, LCD_CLEAR);
}

void printStringLcd(const char* ucStr)
{
	// TODO: implement line feed at '\n'
	while(*ucStr != '\0')
	{
		if(*ucStr == '\n')
		{
			// set cursor to line 2
			write_cmd(LCD_COMMAND, LCD_SET_DDRAM_ADDRESS(0x40));
		}
		else
		{
			// print character
			write_cmd(LCD_DATA, *ucStr);
		}
		ucStr++;
	}
}