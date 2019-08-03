#include <msp430.h> 


/**
 * main.c
 */

#include "gpio.h"
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	io new_io;
	return 0;
}
