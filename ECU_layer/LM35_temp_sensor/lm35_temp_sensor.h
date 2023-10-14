/* 
 * File:   lm35_temp_sensor.h
 * Author: Ahmed Yasser
 *
 * Created on October 14, 2023, 6:58 AM
 */

#ifndef LM35_TEMP_SENSOR_H
#define	LM35_TEMP_SENSOR_H

/* Section : Includes */
#include "../../MCAL_layer/ADC/adc.h"
/* Section : Macro Declarations */
/* Section : Macro Function Declaration */
/* Section : Data Type Declarations */
/* Section : Function Declarations */
Std_ReturnType get_temperaturevalue(uint16 *temp_val, uint16 adc_val);

#endif	/* LM35_TEMP_SENSOR_H */

