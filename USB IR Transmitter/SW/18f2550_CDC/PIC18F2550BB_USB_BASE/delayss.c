#include <math.h>
#include <delays.h>

unsigned long clock=48;	//In MHz

void delay_ms(unsigned short long ms)	//maximal 16777215 miliseconds
{
	unsigned short long delay = 0;
	unsigned char anzahl = 1, x = 0, zw = 0;

	delay = ((clock/4000)*ms)/1000;

	if (delay > 255)
	{	
		anzahl = delay / 255;
		anzahl = anzahl + 1;	
		delay = delay % 255;	//modulo	
	}

	for (x = 1; x <= anzahl; x++)
	{
		if (x == anzahl)
		{
			zw = delay;
			Delay1KTCYx(zw);
		}
		else
		{
			Delay1KTCYx(255); //1000 Zyklen x 100 Delay (1 Zyklus = 4 Takte)
		}	
	}
}
void delay_us(unsigned short long us)	//maximal 16777215 mikroseconds minimal 4 µs
{
	unsigned long delay = 0;
	unsigned int anzahl = 1, x = 0, zw = 0;

	delay = (clock/4)*us;

	if (delay > 255)
	{	
		anzahl = delay / 255;
		anzahl = anzahl + 1;	
		delay = delay % 255;	//modulo	
	}

	for (x = 1; x <= anzahl; x++)
	{
		if (x == anzahl)
		{
			zw = delay;
			while (zw > 0)
			{
				Nop();
				zw--;
			}
		}
		else
		{
			for (zw = 1; zw <= 255; zw++)
			{
				Nop();
			}
		}	
	}
}
