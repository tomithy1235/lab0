/* 
* File:   initLab0.h
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/
//why?
#ifndef INITLAB0_H
#define	INITLAB0_H
#define RELEASED 1
#define PRESSED 0


//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12

#define OFF 1;
#define ON 0;

void initLEDs();
void initSW1();
void initTimer32bit();
void turnOnLEDs(int led);
void clearTimer();

#endif	/* INITLAB0_H */

