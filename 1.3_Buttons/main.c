/*
 * Created on Sat Jul 11 2020
 *
 * Created by: Glen Zachariah
 * For more: https://glenzac.wordpress.com
 * License: CC0 1.0 Universal
 *
 * For MSP430F5529LP
 * --------Hardware---------
 * LED1 -> P1.0 (Red)
 * LED2 -> P4.7 (Green)
 * Button S1 -> P2.1
 * Button S2 -> P1.1
 * -------------------------
 */

#include <msp430.h> 

void switch1()
{
    if(P2IN & BIT1)
        P1OUT &= ~BIT0;
    else
        P1OUT |= BIT0;
}

void switch2()
{

    if(P1IN & BIT1)
        P4OUT &= ~BIT7;
    else
        P4OUT |= BIT7;
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0;              // Set P1.0 as OUTPUT
    P4DIR |= BIT7;              // Set P4.7 as OUTPUT
    P2DIR &= ~BIT1;             // Set P2.1 as INPUT
    P2REN |= BIT1;              // Enable P2.1 pull up/down configuration
    P2OUT |= BIT1;              // Set P2.1 as INPUT
    P1DIR &= ~BIT1;             // Set P1.1 as INPUT
    P1REN |= BIT1;              // Enable P1.1 pull up/down configuration
    P1OUT |= BIT1;              // Enable pull up on P1.1

    while(1)
    {
        switch1();
        switch2();
    }
    return 0;
}
