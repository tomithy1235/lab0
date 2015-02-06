// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

#define RELEASED 1
#define PRESSED 0


typedef enum stateTypeEnum{
    led4, led5, led6, led7
} stateType;

volatile stateType led;
volatile int move;

int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer32bit();
    initSW1();
    move = 1;
    led = led4;
    while(1)
    {
        switch(led){
            case led4:
                turnOnLEDs(4);
                break;
            case led5:
                turnOnLEDs(5);
                break;
            case led6:
                turnOnLEDs(6);
                break;
            case led7:
                turnOnLEDs(7);
                break;
        }
    }
    return 0;
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;

    if(PORTBbits.RB5 == PRESSED){
        T2CONbits.TON = 1;//turn on timer
    }

    if(PORTBbits.RB5 == RELEASED){
        T2CONbits.TON = 0;//turn off and clear timer
        clearTimer();
        if(led == led4 && move == 1)
            led = led5;
        else if(led == led5 && move == 1)
            led = led6;
        else if(led == led6 && move == 1)
            led = led7;
        else if(led == led7 && move == 1)
            led = led4;
        
    }
    move = 1;//if it was set to 0
}

void _ISR _T1Interrupt(void){
    IFS0bits.T1IF = 0;
    
    //T2CONbits.TON = 0;//ensure timer is off
    move = 0;
    LATB |= 0xF000;
    /*
    if(led == led4)
        led = led7;
    else if(led == led5)
        led = led4;
    else if(led == led6)
        led = led5;
    else if(led == led7)
        led = led6;
     * */
}