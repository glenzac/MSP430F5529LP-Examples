#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= BIT0; // configure P1.0 as output
    P4DIR |= BIT7; // configure P4.7 as output

    volatile unsigned int i;

    while(1)
    {
        P1OUT |= BIT0; //set P1.0 as HIGH
        P4OUT &= ~BIT7; //set P4.7 as LOW
        for(i=25000; i>0; i--);     // delay
        P1OUT &= ~BIT0; //set P1.0 as LOW
        P4OUT |= BIT7; //set P4.7 as HIGH
        for(i=25000; i>0; i--);     // delay

    }

    return 0;
}
