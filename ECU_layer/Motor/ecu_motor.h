/* 
 * File:   ecu_motor.h
 * Author: Ahmed Yasser
 *
 * Created on August 6, 2023, 11:08 PM
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H

/* Section : Includes */
#include "../../MCAL_layer/GPIO/gpio.h"
#include "ecu_motor_confg.h"

/* Section : Macro Declarations */
#define MOTOR_INPUT_1     0
#define MOTOR_INPUT_2     1
/* Section : Macro Function Declaration */
/* Section : Data Type Declarations */
typedef enum{
    MOTOR_OFF,
    MOTOR_ON        
}motor_st_t;

typedef struct{
    Pin_Config_t motor_confg[2];
}motor_confg_t; 

/* Section : Function Declarations */
Std_ReturnType motor_initialize(const motor_confg_t *motor);
Std_ReturnType motor_move_right(const motor_confg_t *motor);
Std_ReturnType motor_move_left(const motor_confg_t *motor);
Std_ReturnType motor_turn_off(const motor_confg_t *motor);

#endif	/* ECU_MOTOR_H */

