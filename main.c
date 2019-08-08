#include <msp430.h> 


/**
 * main.c
 */

#include "gpio.h"
#include "config.h"

extern const io LED_1_0_IO;
extern const io LED_1_6_IO;
extern const io PUSH_BUTTON_IO;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	LED_1_0_IO.function_map->init(LED_1_0_IO.config);
	LED_1_6_IO.function_map->init(LED_1_6_IO.config);
	PUSH_BUTTON_IO.function_map->init(PUSH_BUTTON_IO.config);

	LED_1_0_IO.function_map->set(LED_1_0_IO.config);
	LED_1_6_IO.function_map->clear(LED_1_6_IO.config);

	while(1==1){
	    if(PUSH_BUTTON_IO.function_map->read(PUSH_BUTTON_IO.config) == ePin_On){
	        LED_1_0_IO.function_map->set(LED_1_0_IO.config);
	        LED_1_6_IO.function_map->clear(LED_1_6_IO.config);
	    } else {
	        LED_1_0_IO.function_map->clear(LED_1_0_IO.config);
	        LED_1_6_IO.function_map->set(LED_1_6_IO.config);
	    }
	}
}
