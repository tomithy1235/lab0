/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"
#define F_CY 14745600

void initLEDs(){
    TRISB &= 0x0FFF;//switches all leds to output
    LATB |= 0xF000;
}

void initSW1(){
    TRISBbits.TRISB5 = 1;//set as input
    IFS1bits.CNIF = 0;//interrupt flag down
    IEC1bits.CNIE = 1;//overall interrupt enable
    CNEN2bits.CN27IE = 1;//switch interrupt enabled
}


void initTimer32bit(){
    long int prVal = (F_CY*2)/256 - 1;
    PR3 = (prVal >> 16); //0x0001
    PR2 = (prVal << 16) >> 16; //0xC1FF
    T2CONbits.T32 = 1;
    T2CONbits.TCKPS = 0b11;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
    T2CONbits.TON = 0;
}

void clearTimer(){
    TMR2 = 0;
    TMR3 = 0;
}

void turnOnLEDs(int led){
    if(led == 4){
        LED4 = ON;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if (led == 5){
        LED4 = OFF;
        LED5 = ON;
        LED6 = OFF;
        LED7 = OFF;
    }

    else if (led == 6){
        LED4 = OFF;
        LED5 = OFF;
        LED6 = ON;
        LED7 = OFF;
    }

    else if (led == 7){
        LED4 = OFF;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = ON;
    }
}