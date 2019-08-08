/*
 * digital_functions.h
 *
 *  Created on: Aug 3, 2019
 *      Author: albrechter
 */

#ifndef DIGITAL_FUNCTIONS_H_
#define DIGITAL_FUNCTIONS_H_

#include "gpio.h"

void digital_init(const io_config* config);
ePinState digital_read(const io_config* config);
void digital_set(const io_config* config);
void digital_clear(const io_config* config);
void digital_pwm(const io_config* config, uint8_t first_time, uint8_t second_time, eIO_Pin_State starting_pin_state);
void digital_debounce(const io_config* config, uint8_t debounce_ms);
void digital_interrupt(const io_config* config);
void digital_update(const io_config* config);

#endif /* DIGITAL_FUNCTIONS_H_ */
