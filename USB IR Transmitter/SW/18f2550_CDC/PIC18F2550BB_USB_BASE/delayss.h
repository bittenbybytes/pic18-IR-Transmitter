#ifndef delayss_h
#define delayss_h

extern unsigned long clock;	//delayfunktions need clock-information  

void delay_ms(unsigned short long ms);	//maximal 16777215 miliseconds
void delay_us(unsigned short long us);	//maximal 16777215 mikroseconds

#endif delayss_h
