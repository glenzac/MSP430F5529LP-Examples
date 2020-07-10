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

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    // ------------- Configure on-board LEDs and Buttons --------------- //

    P1DIR |= BIT0;              // Set P1.0 as OUTPUT
    P4DIR |= BIT7;              // Set P4.7 as OUTPUT
    P2DIR &= ~BIT1;             // Set P2.1 as INPUT
    P2REN |= BIT1;              // Enable P2.1 pull up/down configuration
    P2OUT |= BIT1;              // Set P2.1 as INPUT
    P1DIR &= ~BIT1;             // Set P1.1 as INPUT
    P1REN |= BIT1;              // Enable P1.1 pull up/down configuration
    P1OUT |= BIT1;              // Enable pull up on P1.1

    // ----------------------------------------------------------------- //

    P1IES &= ~BIT1; // Set low to high interrupt on P1.1
    P1IE |= BIT1; // Enable P1.1 as interrupt
    __bis_SR_register(GIE); //Set GIE bit in Status Register to enable Global Interrupts

    return 0;
}


#pragma vector=PORT1_VECTOR
__interrupt void myISR(void)
{
    //_even_in_range: tells compiler to only worry about even interrupts up to 0x10
    // useful in creating optimized ISRs
    switch(__even_in_range( P1IV, 0x10 ))
    {
        case 0x00: break;   // None
        case 0x02: break;   // Interrupt on Pin 0
        case 0x04: P4OUT ^= BIT7;   // Interrupt on Pin 1
                   break;
        case 0x06: break;   // Interrupt on  Pin 2
        case 0x08: break;   // Interrupt on Pin 3
        case 0x0A: break;   // Interrupt on Pin 4
        case 0x0C: break;   // Interrupt on Pin 5
        case 0x0E: break;   // Interrupt on Pin 6
        case 0x10: break;   // Interrupt on Pin 7
        //_never_executed(): tells compiler that default case will never occur
        // useful in creating optimized ISRs
        default: _never_executed();
    }
}

