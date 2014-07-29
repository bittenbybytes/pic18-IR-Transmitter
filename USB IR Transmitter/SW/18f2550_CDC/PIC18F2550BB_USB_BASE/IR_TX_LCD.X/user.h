/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */
#define LED_TRISBIT TRISBbits.TRISB4
#define LED_PORTBIT PORTBbits.RB4
#define LED_ON 1
#define LED_OFF 0

#define LCD_RESET_N_TRISBIT TRISBbits.TRISB2
#define LCD_RESET_N_PORTBIT PORTBbits.RB2

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
