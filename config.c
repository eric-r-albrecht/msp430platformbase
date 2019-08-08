/*
 * config.c
 *
 *  Created on: Aug 5, 2019
 *      Author: albrechter
 */

#include <stdint.h>
#include "config.h"
#include "gpio.h"
#include "digital_functions.h"

extern const io_function_map digital_functions;

const io_config LED_1_0_cfg = {.time = EMPTY, .alt_function_register=EMPTY, .port = PORT_1_ADDRESS, .orientation = eOrientation_Normal, .pin_mask = PIN_0, .direction = eDirection_OUT};
const io LED_1_0_IO = {.function_map = &digital_functions, .config = &LED_1_0_cfg};

const io_config LED_1_6_cfg = {.time = EMPTY, .alt_function_register=EMPTY, .port = PORT_1_ADDRESS, .orientation = eOrientation_Normal, .pin_mask = PIN_6, .direction = eDirection_OUT};
const io LED_1_6_IO = {.function_map = &digital_functions, .config=&LED_1_6_cfg};

const io_config PUSH_BUTTON_cfg = {.time = EMPTY, .alt_function_register=EMPTY, .port = PORT_1_ADDRESS, .orientation = eOrientation_Normal, .pin_mask = PIN_3, .direction = eDirection_IN};
const io PUSH_BUTTON_IO = {.function_map = &digital_functions, .config=&PUSH_BUTTON_cfg};
