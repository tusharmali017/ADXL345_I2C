#include "timer1.h"


void initTimer1(void)
{
    T1CON = 0;
    TMR1 = 0;
    PR1 = 4000U;            //period value for 1 msec delay
}

void timer1Delay(int ms)  
{
    T1CONbits.TON = 1;      //start timer 1
    unsigned int i;
    
    for(i = 0; i<ms; i++)
    {
        while(!IFS0bits.T1IF);
        IFS0bits.T1IF = 0;
    }
    T1CONbits.TON = 0;      //stop timer 1
}

