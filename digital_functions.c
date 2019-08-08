/*
 * digital_functions.c
 *
 *  Created on: Aug 3, 2019
 *      Author: albrechter
 */

#include "digital_functions.h"
#include "config.h"
#include "gpio.h"

const io_function_map digital_functions = {&digital_init, &digital_read, &digital_set, &digital_clear, &digital_pwm, &digital_debounce, &digital_interrupt, &digital_update};

/**
 * This method initializes digital io
 */
void digital_init(const io_config* config){
    if(config->direction == eDirection_OUT){
        *((uint8_t*) (config->port | PxDIR)) |= (config->pin_mask);
    } else {
        *((uint8_t*) (config->port | PxDIR)) &= (~(config->pin_mask));
    }
}

/**
 * This method reads a digital IO's instantaneous status.
 */
ePinState digital_read(const io_config* config){
    ePinState return_value = ePin_Off;
    if((*((uint8_t*) (config->port | PxIN)) & config->pin_mask) == EMPTY){
        return_value = ePin_On;
    }
    return return_value;
}

/**
 * This method sets the digital IO's output high according to the orientation.
 */
void digital_set(const io_config* config){
    *((uint8_t*) (config->port | PxOUT)) |=  config->pin_mask;
}

/**
 * This method clears the digital IO's output low according to the orientation.
 */
void digital_clear(const io_config* config){
    *((uint8_t*) (config->port | PxOUT)) &= ~(config->pin_mask);
}

/**
 * This method pwm's the output based on the times and state provided.
 */
void digital_pwm(const io_config* config, uint8_t first_time, uint8_t second_time, eIO_Pin_State starting_pin_state){

}

/**
 * This method debounces the input.
 */
void digital_debounce(const io_config* config, uint8_t debounce_ms){

}

/**
 * This method configures the digital IO interrupt for the pin.
 */
void digital_interrupt(const io_config* interrupt_io){

}

/**
 * This updates the pin state.
 */
void digital_update(const io_config* config){

}
