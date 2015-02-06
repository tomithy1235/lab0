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
    T2CONbits.T32 = 1;//32bit mode enabled
    T2CONbits.TCKPS = 0b11;//prescaler 256
    IEC0bits.T3IE = 1;//over all enable
    IFS0bits.T3IF = 0;//flag down
    T2CONbits.TON = 0;//timer off
}

void clearTimer(){
    TMR2 = 0;
    TMR3 = 0;
}

void turnOnLEDs(int led){
    LATB |= 0xF000;
    if(led == 4){
        LED4 = ON;
    }
    else if (led == 5){
        LED5 = ON;
    }

    else if (led == 6){
        LED6 = ON;
    }

    else if (led == 7){
        LED7 = ON;
    }
}