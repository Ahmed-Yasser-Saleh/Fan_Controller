/* 
 * File:   adc.h
 * Author: Ahmed Yasser
 *
 * Created on September 17, 2023, 8:17 AM
 */

#ifndef ADC_H
#define	ADC_H

/* Section : Includes */
#include "../mcal_std_types.h"
#include <../proc/pic18f4620.h>
#include "../device_config.h"
#include "../Interrupt/interrupt_cfg.h"
#include "../GPIO/gpio.h"
#include "../Interrupt/interrupt_internal.h"
/* Section : Macro Declarations */     

/* Section : Macro Function Declaration */
#define DISABLE_ADC_MODULE()                (ADCON0bits.ADON = 0)
#define ENABLE_ADC_MODULE()                 (ADCON0bits.ADON = 1)

#define SART_ADC_MODULE()                   (ADCON0bits.GODONE = 1)

#define ADC_ENABLE_VOLTAGE_REFERENCE()      do{ADCON1bits.VCFG1 = 1;\
                                                 ADCON1bits.VCFG0 = 1;\
                                              }while(0)
#define ADC_DISABLE_VOLTAGE_REFERENCE()     do{ADCON1bits.VCFG1 = 0;\
                                                 ADCON1bits.VCFG0 = 0;\
                                              }while(0)

#define ADC_LEFT_RESULT_FORMAT()            (ADCON2bits.ADFM = 0)   
#define ADC_RIGHT_RESULT_FORMAT()           (ADCON2bits.ADFM = 1)

/* Section : Data Type Declarations */

#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY    0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY    0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY    0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY    0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY    0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY    0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY    0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY    0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY    0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY   0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY   0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY   0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY    0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY   0x0F

typedef enum{
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12
}adc_channel_select_t;

typedef enum{
    ADC_0_TAD = 0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
}adc_acquisition_time_t;

typedef enum{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
}adc_conversion_clock_t;

typedef struct {
 void(*internalfun_interrupt)(void);
 Pin_Config_t adc_pin_confg;
 adc_channel_select_t adc_channel;
 adc_acquisition_time_t adc_acquisition_time;
 adc_conversion_clock_t adc_conversion_clock;  
 interrupt_priority_status priority;
 uint8 result_format : 1;
 uint8 voltage_reference : 1;
}adc_confg_t;

Std_ReturnType adc_init(adc_confg_t *adc_confg);
Std_ReturnType adc_deinit(adc_confg_t *adc_confg);
Std_ReturnType adc_select_channel(adc_confg_t *adc_confg,adc_channel_select_t channel);
Std_ReturnType adc_startconversion(adc_confg_t *adc_confg);
Std_ReturnType adc_isconversion_done(adc_confg_t *adc_confg, uint8 *conversion_status);
Std_ReturnType adc_getconversion_result(adc_confg_t *adc_confg, uint16 *conversion_result);
Std_ReturnType ADC_GetConversion_Blocking(const adc_confg_t *adc_confg, adc_channel_select_t channel, 
                                 uint16 *conversion_result);
Std_ReturnType ADC_StartConversion_Interrupt( adc_confg_t *adc_confg, adc_channel_select_t channel);
/* Section : Function Declarations */

#endif	/* ADC_H */

