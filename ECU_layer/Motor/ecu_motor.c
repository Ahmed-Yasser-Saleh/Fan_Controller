/* 
 * File:   ecu_motor.c
 * Author: Ahmed Yasser
 *
 * Created on August 6, 2023, 11:08 PM
 */

/* Section : Includes */
#include "ecu_motor.h"

/* Section : Macro Declarations */

/* Section : Macro Function Declaration */
/* Section : Data Type Declarations */
/* Section : Function Declarations */
Std_ReturnType motor_initialize(const motor_confg_t *motor){
    Std_ReturnType ret = E_OK;
    if(NULL == motor)
        ret = E_NOT_OK;
    else{
        gpio_pin_intialize(&(motor->motor_confg[MOTOR_INPUT_1]));
        gpio_pin_intialize(&(motor->motor_confg[MOTOR_INPUT_2]));
    }
    return ret;
}
 
Std_ReturnType motor_move_right(const motor_confg_t *motor){
    Std_ReturnType ret = E_OK;
    if(NULL == motor)
        ret = E_NOT_OK;
    else{
        gpio_pin_write_logic(&(motor->motor_confg[MOTOR_INPUT_1]),LOW);
        gpio_pin_write_logic(&(motor->motor_confg[MOTOR_INPUT_2]),HIGH);
    }
    return ret;
}
Std_ReturnType motor_move_left(const motor_confg_t *motor){
    Std_ReturnType ret = E_OK;
    if(NULL == motor)
        ret = E_NOT_OK;
    else{ 
        gpio_pin_write_logic(&(motor->motor_confg[MOTOR_INPUT_1]),HIGH);
        gpio_pin_write_logic(&(motor->motor_confg[MOTOR_INPUT_2]),LOW);
    }
    return ret;
}
Std_ReturnType motor_turn_off(const motor_confg_t *motor){
    Std_ReturnType ret = E_OK;
    if(NULL == motor)
        ret = E_NOT_OK;
    else{
       
        gpio_pin_write_logic(&(motor->motor_confg[MOTOR_INPUT_1]),HIGH);
        gpio_pin_write_logic(&(motor->motor_confg[MOTOR_INPUT_2]),HIGH);
    }
    return ret;
}