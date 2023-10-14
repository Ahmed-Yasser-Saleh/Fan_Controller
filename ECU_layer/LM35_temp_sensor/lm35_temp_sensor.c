/* 
 * File:   lm35_temp_sensor.h
 * Author: Ahmed Yasser
 *
 * Created on October 14, 2023, 6:58 AM
 */


/* Section : Includes */
#include "lm35_temp_sensor.h"
/* Section : Macro Declarations */
/* Section : Macro Function Declaration */
/* Section : Data Type Declarations */
/* Section : Function Declarations */
Std_ReturnType get_temperaturevalue(uint16 *temp_val, uint16 adc_val){
    Std_ReturnType ret = E_OK;
    uint16 pow = 1;
    uint8 adc_resol = ADC_RESOLUTION;
    if(NULL == temp_val)
        ret = E_NOT_OK;
    else{
        while(adc_resol){
            pow *= 2;
            adc_resol--;
        }
        //5000 -> voltage reference in mv
        *temp_val = (adc_val * (5000 / (float)(pow - 1))) / 10; //output of LM35 Is 10.0 mv/degree
    }
    return ret;
}


