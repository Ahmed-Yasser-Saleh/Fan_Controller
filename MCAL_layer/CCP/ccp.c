/* 
 * File:   ccp.c
 * Author: Ahmed Yasser
 *
 * Created on October 3, 2023, 6:13 AM
 */


/* Section : Includes */
#include "ccp.h"
/* Section : Macro Declarations */  
#define _XTAL_FREQ 4000000UL
/* Section : Macro Function Declaration */
/* Section : Data Type Declarations */
/* Section : Function Declarations */
void(*handler_cpp1)(void);
void(*handler_cpp2)(void);


static Std_ReturnType set_pwm_period(ccp_confg_t *ccp_obj);
static Std_ReturnType set_pwm_duty_cycle(ccp_confg_t *ccp_obj);


static void CCP_Mode_Timer_Select(ccp_confg_t  *ccp_obj);

static Std_ReturnType interrupt_ccp1_cfg(ccp_confg_t *ccp_obj);
static Std_ReturnType interrupt_ccp2_cfg(ccp_confg_t *ccp_obj);

Std_ReturnType CCP_Init( ccp_confg_t *ccp_obj){
    Std_ReturnType ret = E_OK;
    
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else
    {
        if(ccp_obj->ccp_mode == CCP1_MODULE)
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLE;
        
        else if(ccp_obj->ccp_mode == CCP2_MODULE)
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLE;
        
        else {}

        if(ccp_obj->ccp_mode == CCP1_MODULE)
        {
            #if (MODE_CCP1_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE)
            if(ccp_obj->ccp_mode_module == CAPTURE_MODE_CCP_MODULE)
            {
                if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_FALLING_EDGE)
                    CAPTURE_MODE_EVERY_FALLING_EDGE_CCP1();
                else if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_RISING_EDGE)
                    CAPTURE_MODE_EVERY_RISING_EDGE_CCP1();
                else if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_4_RISING_EDGE)
                    CAPTURE_MODE_EVERY_4_RISING_EDGE_CCP1(); 
                else if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_16_RISING_EDGE)
                    CAPTURE_MODE_EVERY_16_RISING_EDGE_CCP1(); 
                else{}
              gpio_pin_direction_intialize(&(ccp_obj->ccp_pin)); 
              CCP_Mode_Timer_Select(ccp_obj);
            }          
            #elif (MODE_CCP1_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE)
            if(ccp_obj->ccp_mode_module == COMPARE_MODE_CCP_MODULE)
            {
                if(ccp_obj->compare_mode_st == TOGGLE_PIN)
                    COMPARE_MODE_TOGGLE_OUTPUT_CCP1();
                else if(ccp_obj->compare_mode_st == LOW_PIN)
                    COMPARE_MODE_LOW_OUTPUT_CCP1();
                else if(ccp_obj->compare_mode_st == HIGH_PIN)
                    COMPARE_MODE_HIGH_OUTPUT_CCP1(); 
                else if(ccp_obj->compare_mode_st == UNCHANGED_GENERATE_INTERRUPT)
                    COMPARE_MODE_GENERATE_INTERRUPT_CCP1(); 
                else if(ccp_obj->compare_mode_st == TRIGGER_EVENT)
                    COMPARE_MODE_TRIGGER_SPECIAL_EVENT_CCP1(); 
                else{}
                
                gpio_pin_direction_intialize(&(ccp_obj->ccp_pin));
                CCP_Mode_Timer_Select(ccp_obj);
            }
            #elif (MODE_CCP1_MODULE_SELECTED == PWM_MODE_CCP_MODULE)
            if (ccp_obj->ccp_mode_module == PWM_MODE_CCP_MODULE)
            {
                set_pwm_period(ccp_obj);
                gpio_pin_direction_intialize(&(ccp_obj->ccp_pin));
                TIMER2_MODULE_ENABLE();
                PWM_MODE_CCP1();
            }
            #endif

        }

        else if(ccp_obj->ccp_mode == CCP2_MODULE){
             
            #if (MODE_CCP2_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE)
            if(ccp_obj->ccp_mode_module == CAPTURE_MODE_CCP_MODULE)
            {
                if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_FALLING_EDGE)
                    CAPTURE_MODE_EVERY_FALLING_EDGE_CCP2();
                else if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_RISING_EDGE)
                    CAPTURE_MODE_EVERY_RISING_EDGE_CCP2();
                else if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_4_RISING_EDGE)
                    CAPTURE_MODE_EVERY_4_RISING_EDGE_CCP2(); 
                else if(ccp_obj->capture_st == CAPTURE_MODE_EVERY_16_RISING_EDGE)
                    CAPTURE_MODE_EVERY_16_RISING_EDGE_CCP2();
                else{}
                
              gpio_pin_direction_intialize(&(ccp_obj->ccp_pin)); 
              CCP_Mode_Timer_Select(ccp_obj);
            }

            #elif (MODE_CCP2_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE)
            if(ccp_obj->ccp_mode_module == COMPARE_MODE_CCP_MODULE)
            {
                if(ccp_obj->compare_mode_st == TOGGLE_PIN)
                    COMPARE_MODE_TOGGLE_OUTPUT_CCP2();
                else if(ccp_obj->compare_mode_st == LOW_PIN)
                    COMPARE_MODE_LOW_OUTPUT_CCP2();
                else if(ccp_obj->compare_mode_st == HIGH_PIN)
                    COMPARE_MODE_HIGH_OUTPUT_CCP2(); 
                else if(ccp_obj->compare_mode_st == UNCHANGED_GENERATE_INTERRUPT)
                    COMPARE_MODE_GENERATE_INTERRUPT_CCP2(); 
                else if(ccp_obj->compare_mode_st == TRIGGER_EVENT)
                    COMPARE_MODE_TRIGGER_SPECIAL_EVENT_CCP2(); 
                else{}
                
              gpio_pin_direction_intialize(&(ccp_obj->ccp_pin)); 
              CCP_Mode_Timer_Select(ccp_obj);
            }

            #elif (MODE_CCP2_MODULE_SELECTED == PWM_MODE_CCP_MODULE)
            if (ccp_obj->ccp_mode_module == PWM_MODE_CCP_MODULE)
            {
                set_pwm_period(ccp_obj);
                gpio_pin_direction_intialize(&(ccp_obj->ccp_pin));
                TIMER2_MODULE_ENABLE();
                PWM_MODE_CCP2();
            }
            #endif   
        }  
        else {}
       interrupt_ccp1_cfg(ccp_obj);
      interrupt_ccp1_cfg(ccp_obj);
    }
    return ret;
}
Std_ReturnType CCP_DeInit( ccp_confg_t *ccp_obj){
      Std_ReturnType ret = E_OK;
    
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else
    {
        if(ccp_obj->ccp_mode == CCP1_MODULE)
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLE;
        
        else if(ccp_obj->ccp_mode == CCP2_MODULE)
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLE;
        
        else {}
    }
    return ret;
}
#if (MODE_CCP1_MODULE_SELECTED == PWM_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == PWM_MODE_CCP_MODULE)
static Std_ReturnType set_pwm_period(ccp_confg_t *ccp_obj){
      Std_ReturnType ret = E_OK;
    
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else
    {
        PR2 = (uint8)(((float)_XTAL_FREQ / ((float)ccp_obj->pwm_freq * 4.0 * (float)ccp_obj->timer2_prescaler * 
                    (float)ccp_obj->timer2_postscaler)) - 1);
    }
    return ret; 
}
Std_ReturnType CCP_PWM_Set_Duty(ccp_confg_t *ccp_obj, uint8 duty){
         Std_ReturnType ret = E_OK;
       uint16 val_reg;
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else
    {
        if(ccp_obj->ccp_mode == CCP1_MODULE)
        {
            val_reg = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)duty / 100.0));
            CCP1CONbits.DC1B = (val_reg & 0x0003);
            CCPR1L = (uint8)(val_reg >> 2);
        }
        
        else if(ccp_obj->ccp_mode == CCP2_MODULE)
        {
            val_reg = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)duty / 100.0));
            CCP2CONbits.DC2B = (val_reg & 0x0003);
            CCPR2L = (uint8)(val_reg >> 2);
        }
        
        else {}
        
    }
    return ret;
}
Std_ReturnType CCP_PWM_Stop(ccp_confg_t *ccp_obj){
          Std_ReturnType ret = E_OK;
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else
    {
        if(ccp_obj->ccp_mode == CCP1_MODULE)
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLE;
        
        else if(ccp_obj->ccp_mode == CCP2_MODULE)
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLE;
        
        else {}
    }
    return ret;  
}
#endif

#if (MODE_CCP1_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE)|| (MODE_CCP1_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == COMPARE_MODE_CCP_MODUL)
static void CCP_Mode_Timer_Select(ccp_confg_t  *ccp_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else{
          if(ccp_obj->capture_compare_clk_source == TIMER1_CLK_SRC_CCP)
                    TIMER1_CLK_SOURCE_CCP();
          else if(ccp_obj->capture_compare_clk_source == TIMER1_CLK_SRC_CCP1_TIMER3_CLK_SOURCE_CCP2)
                    TIMER1_CLK_SOURCE_CCP1_TIMER3_CLK_SOURCE_CCP2();
          else if(ccp_obj->capture_compare_clk_source == TIMER3_CLK_SRC_CCP)
                    TIMER3_CLK_SOURCE_CCP();
           else{}
        }
}
#endif
#if (MODE_CCP1_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE)
Std_ReturnType CCP_Capture_Mode_Read_Value(ccp_confg_t *ccp_obj, uint16 *capture_value){
 Std_ReturnType ret = E_OK;
    if(NULL == capture_value || NULL == ccp_obj)
        ret = E_NOT_OK;
    else{
        if(ccp_obj->ccp_mode == CCP1_MODULE)
        {
            *capture_value = CCPR1L + (CCPR1H << 8);
        }
        else if(ccp_obj->ccp_mode == CCP2_MODULE)
        {
            *capture_value = CCPR2L + (CCPR2H << 8);
        }
        else{}
        }
}
#endif

#if (MODE_CCP1_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE)
Std_ReturnType CCP_Compare_Mode_write_Value(ccp_confg_t *ccp_obj, uint16 capture_value){
     Std_ReturnType ret = E_OK;
    if(NULL == ccp_obj)
        ret = E_NOT_OK;
    else{
        if(ccp_obj->ccp_mode == CCP1_MODULE)
        {
            CCPR1H = (uint8)(capture_value >> 8);
           CCPR1L = (uint8)capture_value;
        }
        else if(ccp_obj->ccp_mode == CCP2_MODULE)
        {
            CCPR2H = (uint8)(capture_value >> 8);
           CCPR2L = (uint8)capture_value;
        }
        else{}
        }
}
#endif
static Std_ReturnType interrupt_ccp1_cfg(ccp_confg_t *ccp_obj){
/* CCP1 Interrupt Configurations */ 
#if INTERRUPT_INTERNAL_FEATURE == INTERRUPT_INTERNAL_ENABLE
    
    CCP1_INTERRUPT_ENABLE();
    CCP1_INTERRUPT_NOT_OCCURE();
    handler_cpp1 = ccp_obj->interrupt_ccp1;
/* Interrupt Priority Configurations */
#if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE 
    INTERRUPT_PriorityLevelsEnable();
    if(INTERRUPT_HIGH_PRIORITY == _ccp_obj->CCP1_priority){
        /* Enables all high-priority interrupts */
        INTERRUPT_GlobalInterruptHighEnable();
        CCP1_HighPrioritySet();
    }
    else if(INTERRUPT_LOW_PRIORITY == _ccp_obj->CCP1_priority){
        /* Enables all unmasked peripheral interrupts */
        INTERRUPT_GlobalInterruptLowEnable();
        CCP1_LowPrioritySet();
    }
    else{ /* Nothing */ }
#else
    INTERRUPT_GlobalInterrupt_Enable();
    INTERRUPT_PeripheralInterrupt_Enable();
 
#endif    
#endif
}  

static Std_ReturnType interrupt_ccp2_cfg(ccp_confg_t *ccp_obj){
/* CCP2 Interrupt Configurations */ 
#if INTERRUPT_INTERNAL_FEATURE == INTERRUPT_INTERNAL_ENABLE
    CCP2_INTERRUPT_ENABLE();
    CCP2_INTERRUPT_NOT_OCCURE();
    handler_cpp2 = ccp_obj->interrupt_ccp2;
/* Interrupt Priority Configurations */
#if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE 
    INTERRUPT_PriorityLevelsEnable();
    if(INTERRUPT_HIGH_PRIORITY == _ccp_obj->CCP2_priority){
        /* Enables all high-priority interrupts */
        INTERRUPT_GlobalInterruptHighEnable();
        CCP2_HighPrioritySet();
    }
    else if(INTERRUPT_LOW_PRIORITY == _ccp_obj->CCP2_priority){
        /* Enables all unmasked peripheral interrupts */
        INTERRUPT_GlobalInterruptLowEnable();
        CCP2_LowPrioritySet();
    }
    else{ /* Nothing */ }
#else
    INTERRUPT_GlobalInterrupt_Enable();
    INTERRUPT_PeripheralInterrupt_Enable();
#endif  
#endif
}      
 

void CCP1_ISR(void){
    CCP1_INTERRUPT_NOT_OCCURE();
    if(handler_cpp1)
        handler_cpp1();
}

void CCP2_ISR(void){
    CCP2_INTERRUPT_NOT_OCCURE();
    if(handler_cpp2)
        handler_cpp2();
}

