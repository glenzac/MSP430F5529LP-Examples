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

// MSP-EXP430F5529LP-Examples
// Glen Zachariah

/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output

	volatile unsigned int i;		// volatile to prevent optimization

	while(1)
	{
		P1OUT ^= 0x01;				// toggle P1.0
		for(i=50000; i>0; i--);     // delay
	}
}
