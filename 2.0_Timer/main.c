#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // stop watchdog timer
  P1DIR |= BIT0;                            // Set P1.0 as OUTPUT
  // -------------  Configure Timer A0  --------------- //
  TA0CCTL0 = CCIE;                          // Enable CCR0 interrupt
  TA0CCR0 = 50000;                          // Set compare value of 50,000 in CCR0
  TA0CTL = TASSEL_2 + MC_1 + TACLR;         // Source = SMCLK, In Upmode, clear counter (TAR)

  // ----------------------------------------------------------------- //

  __bis_SR_register(GIE);                   //Enable Global interrupts
  while(1)
  {

  }
  return 0;

}

// -------------  Timer A0 ISR  --------------- //
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
  P1OUT ^= BIT0;                            // Toggle P1.0
}

