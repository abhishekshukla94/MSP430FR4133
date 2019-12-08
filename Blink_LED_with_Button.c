#include <msp430.h>

#define RED_ON 0x01 // P1.0 is the red LED

#define RED_OFF 0x7E // Used to turn off the red LED

#define BUTTON12 0x04 // P1.2 is the lower-right push-button

#define DEVELOPMENT 0x5A80 // Stop the watch dog timer

#define ENABLE_PINS 0xFFFE // Required to use inputs and outputs

main()

{

 WDTCTL = DEVELOPMENT; // Need for development mode

 PM5CTL0 = ENABLE_PINS; // Prepare pins for I/O usage

 P1DIR = RED_ON; // Red LED connected to P1.0 as output

 P1OUT = BUTTON12; // Button needs a pull-up resistor

 P1REN = BUTTON12;

 while(1) // Keep looping forever

 {

 while((BUTTON12 & P1IN) == 0) // Is P12 button pushed?

 {

 P1OUT = P1OUT | RED_ON; // Turn on the green LED

 }

 P1OUT = P1OUT & RED_OFF; // Turn off the green LED

 }
}
