/* 
 * File:   adc.c
 * Author: Ahmed Yasser
 *
 * Created on September 17, 2023, 8:17 AM
 */

#include "adc.h"

void (*hundler_ADC) (void);
static Std_ReturnType analog_pin_functionality(uint8 pin_functionality);
static Std_ReturnType set_adc_interrupt(adc_confg_t *adc_confg);

Std_ReturnType adc_init(adc_confg_t *adc_confg){
    Std_ReturnType ret = E_OK;
    if(NULL == adc_confg)
        ret = E_NOT_OK;
    else
    {
      DISABLE_ADC_MODULE();
      
      gpio_pin_direction_intialize(&(adc_confg->adc_pin_confg));
      
     analog_pin_functionality(ADC_AN0_ANALOG_FUNCTIONALITY);
      
        ADCON2bits.ACQT = adc_confg->adc_acquisition_time;
        ADCON2bits.ADCS = adc_confg->adc_conversion_clock;
        
        ADCON0bits.CHS = adc_confg->adc_channel;
      
      if(adc_confg->voltage_reference == 0)
        ADC_DISABLE_VOLTAGE_REFERENCE();
      else if(adc_confg->voltage_reference == 1)
        ADC_ENABLE_VOLTAGE_REFERENCE();
      else{
          ADC_ENABLE_VOLTAGE_REFERENCE();
      }
      
      if(adc_confg->result_format == 1)
         ADC_RIGHT_RESULT_FORMAT();
      else if(adc_confg->result_format == 0)
          ADC_LEFT_RESULT_FORMAT();
      else{ 
          ADC_RIGHT_RESULT_FORMAT();
      }
      
      ENABLE_ADC_MODULE();
      
     #if INTERRUPT_INTERNAL_FEATURE == INTERRUPT_INTERNAL_ENABLE

     ADC_INTERRUPT_NOT_OCCURE();
     #if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE
      INTERRUPT_PRIORITY_GENERAL_ENABLE();
      
      if(adc_confg->priority == LOW_PRIORITY)
      {
          INTERRUPT_LOW_PRIORITY_ENABEL();
          ADC_LOW_PRIORITY();
      }
      else if(adc_confg->priority == HIGH_PRIORITY)
      {
          INTERRUPT_HIGH_PRIORITY_ENABLE();
          ADC_HIGH_PRIORITY();
      }
    #else
       INTERRUPT_PeripheralInterrupt_Enable();
       INTERRUPT_GlobalInterrupt_Enable();
    #endif
    set_adc_interrupt(adc_confg);
    ADC_INTERRUPT_ENABLE();
      
    #endif
    }
    return ret;
}

Std_ReturnType adc_deinit(adc_confg_t *adc_confg){
      Std_ReturnType ret = E_OK;
    if(NULL == adc_confg)
        ret = E_NOT_OK;
    else
    {
      DISABLE_ADC_MODULE();
    }
    return ret;
    
}

Std_ReturnType adc_select_channel(adc_confg_t *adc_confg,adc_channel_select_t channel){
    Std_ReturnType ret = E_OK;
    if(NULL == adc_confg)
        ret = E_NOT_OK;
    else
    {
     ADCON0bits.CHS = channel;
    }
    return ret; 
}

Std_ReturnType adc_startconversion(adc_confg_t *adc_confg){
     Std_ReturnType ret = E_OK;
    if(NULL == adc_confg)
        ret = E_NOT_OK;
    else
    {
     SART_ADC_MODULE();
    }
    return ret;  
}

Std_ReturnType adc_isconversion_done(adc_confg_t *adc_confg, uint8 *conversion_status){
     Std_ReturnType ret = E_OK;
    if(NULL == adc_confg)
        ret = E_NOT_OK;
    else
    {
       *conversion_status = (uint8)!(ADCON0bits.GODONE); 
    }
    return ret; 
}

Std_ReturnType ADC_GetConversion_Blocking(const adc_confg_t *adc_confg, adc_channel_select_t channel, 
                                 uint16 *conversion_result){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == adc_confg) || (NULL == conversion_result)){
        ret = E_NOT_OK;
    }
    else{
        /* select the A/D channel */
        ret = adc_select_channel(adc_confg, channel);
        /* Start the conversion */
        ret = adc_startconversion(adc_confg);
        /* Check if conversion is completed */
        while(ADCON0bits.GO_nDONE);
        ret = adc_getconversion_result(adc_confg, conversion_result);
    }
    return ret;
}

Std_ReturnType adc_getconversion_result(adc_confg_t *adc_confg, uint16 *conversion_result){
     Std_ReturnType ret = E_OK;
    if(NULL == adc_confg || NULL == conversion_result)
        ret = E_NOT_OK;
    else
    {
        if(1 == adc_confg->result_format){
            *conversion_result = (uint16)((ADRESH << 8) + ADRESL);
        }
        else if(0 == adc_confg->result_format){
            *conversion_result = (uint16)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else{
            *conversion_result = (uint16)((ADRESH << 8) + ADRESL);
        }
    }
    return ret;
}


static Std_ReturnType analog_pin_functionality(uint8 pin_functionality){
    ADCON1bits.PCFG = pin_functionality;
}


Std_ReturnType set_adc_interrupt(adc_confg_t *adc_confg){
    Std_ReturnType ret = E_OK;
    if(NULL == adc_confg)
        ret = E_NOT_OK;
    else
    {
      hundler_ADC = adc_confg->internalfun_interrupt; 
    }
    return ret;  
}

void ADC_ISR(void){
    ADC_INTERRUPT_NOT_OCCURE();
    if(hundler_ADC)
        hundler_ADC();
}

Std_ReturnType ADC_StartConversion_Interrupt(adc_confg_t *adc_confg, adc_channel_select_t channel){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == adc_confg){
        ret = E_NOT_OK;
    }
    else{
        ADC_INTERRUPT_NOT_OCCURE();
        /* select the A/D channel */
        ret = adc_select_channel(adc_confg, channel);
        /* Start the conversion */
        ret = adc_startconversion(adc_confg);
        
    }
    return ret;
}
