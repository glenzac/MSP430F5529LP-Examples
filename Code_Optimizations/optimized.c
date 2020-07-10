//Handling Unused Interrupts
// The MSP430 compiler issues warning whenever all interrupts are not handled
//(i.e. when you don’t have a vector specified for each interrupt)
// Here’s a simple example of how this might be handled:
// Example for UNUSED_HWI_ISR()
#pragma vector=ADC12_VECTOR
#pragma vector=COMP_B_VECTOR
#pragma vector=DMA_VECTOR
#pragma vector=PORT1_VECTOR
#pragma vector=TIMER1_A1_VECTOR
#pragma vector=TIMER2_A0_VECTOR
#pragma vector=TIMER2_A1_VECTOR
#pragma vector=UNMI_VECTOR
#pragma vector=USB_UBM_VECTOR
#pragma vector=WDT_VECTOR
__interrupt void UNUSED_HWI_ISR (void)
{
__no_operation();
}