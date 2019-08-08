/*
 * gpio.h
 *
 *  Created on: Aug 3, 2019
 *      Author: albrechter
 */

#include <stdint.h>
#include <msp430.h>

#ifndef GPIO_H_
#define GPIO_H_

//This represents the pin operating state over time.
typedef enum{
    eIO_On=0U,
    eIO_Off,
    eIO_Cycle,
    eIO_Read,
    eIO_Debounce
}eIO_Pin_State;

//Port address for IO
typedef enum{
    ePort_ONE,
    ePort_TWO,
    ePort_THREE
}ePort;

//Orientation of reading/writing the port.
typedef enum{
    eOrientation_Normal,
    eOrientation_Inverted
}eIO_Orientation;

//Direction of IO
typedef enum{
    eDirection_IN=0U,
    eDirection_OUT
}eDirection;

//State of the IO input
typedef enum{
    ePin_On,
    ePin_Off
}ePinState;

//If interrupt capability, interrupt edge.
typedef enum{
    eInterrupt_Rising,
    eInterrupt_Falling,
    eInterrupt_None
}eInterrupt_Edge;

typedef enum{
    PxIN=0U,
    PxOUT,
    PxDIR,
    PxIFG,
    PxIES,
    PxIE,
    PxSEL,
    PxREN
}eRegisters;

//Port Structure for IO to use.
typedef struct{
    uint32_t time;
    uint16_t alt_function_register;
    uint16_t port;
    eIO_Orientation orientation;
    eDirection direction;
    uint8_t pin_mask;
}io_config;

//Function interface for function to map to.
typedef struct{
    void (*init)(const io_config* config);
    ePinState (*read)(const io_config* config);
    void (*set)(const io_config* config);
    void (*clear)(const io_config* config);
    void (*pwm)(const io_config* config, uint8_t first_time, uint8_t second_time, eIO_Pin_State starting_pin_state);
    void (*debounce)(const io_config* config, uint8_t debounce_ms);
    void (*interrupt_routine)(const io_config* io_config);
    void (*update)(const io_config* config);
}io_function_map;

//Overall IO information to operate.
typedef struct{
   const io_function_map* function_map;
   const io_config* const config;
}io;

//This is a place holder function for function_maps.
void do_nothing();

#endif /* GPIO_H_ */
