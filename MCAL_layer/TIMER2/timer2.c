/* 
 * File:   timer2.c
 * Author: Ahmed Yasser
 *
 * Created on September 30, 2023, 6:34 AM
 */

/* Section : Includes */
#include "timer2.h"

/* Section : Macro Declarations */     

/* Section : Macro Function Declaration */
void (*TIMER2_HUNDLER)(void);

static Std_ReturnType postscaler_timer_status(Timer2_cfg_t *timer2);
static Std_ReturnType prescaler_timer_status(Timer2_cfg_t *timer2);
static Std_ReturnType set_TIMER2_interrupt(Timer2_cfg_t *timer2);
/* Section : Data Type Declarations */


/* Section : Function Declarations */
Std_ReturnType Timer2_init(Timer2_cfg_t *timer2){
  Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
        TIMER2_MODULE_DISABLE();

        TMR2 = (uint8)timer2->value_start_cnt;
        
        prescaler_timer_status(timer2);  
          
        TIMER2_MODULE_ENABLE();
     #if INTERRUPT_INTERNAL_FEATURE == INTERRUPT_INTERNAL_ENABLE
     TIMER0_INTERRUPT_NOT_OCCURE();
     #if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE
      INTERRUPT_PRIORITY_GENERAL_ENABLE();
      
      if(adc_confg->priority == LOW_PRIORITY)
      {
          INTERRUPT_LOW_PRIORITY_ENABEL();
          TIMER2_LOW_PRIORITY();
      }
      else if(adc_confg->priority == HIGH_PRIORITY)
      {
          INTERRUPT_HIGH_PRIORITY_ENABLE();
          TIMER2_HIGH_PRIORITY();
      }
    #else
       INTERRUPT_PeripheralInterrupt_Enable();
       INTERRUPT_GlobalInterrupt_Enable();
    #endif
    set_TIMER2_interrupt(timer2);
    TIMER2_INTERRUPT_DISABLE();      
    #endif
    }
    return ret;   
}
Std_ReturnType Timer2_deinit(Timer2_cfg_t *timer2){
   Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
       TIMER2_MODULE_DISABLE(); 
    }
    return ret;  
}
Std_ReturnType Timer2_write_value(Timer2_cfg_t *timer2,uint8 value){
    Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
        TMR2 = value;
    }
    return ret;
}
Std_ReturnType Timer2_read_value(Timer2_cfg_t *timer2,uint8 *value){
    Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
        *value = TMR2;
    }
    return ret; 
}


static Std_ReturnType prescaler_timer_status(Timer2_cfg_t *timer2){
     Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
        T2CONbits.T2CKPS = timer2->prescaler_timer2_value;
    }
    return ret; 
}
static Std_ReturnType postscaler_timer_status(Timer2_cfg_t *timer2){
       Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
       T2CONbits.TOUTPS = timer2->postscaler_timer2_value; 
    }
    return ret; 
}

static Std_ReturnType set_TIMER2_interrupt(Timer2_cfg_t *timer2){
       Std_ReturnType ret = E_OK;
    if(NULL == timer2)
        ret = E_NOT_OK;
    else
    {
       TIMER2_HUNDLER = timer2->interrupt_timer2;
    }
    return ret;   
}


void TIMER2_ISR(void){
    TIMER2_INTERRUPT_NOT_OCCURE();
   if(TIMER2_HUNDLER) 
       TIMER2_HUNDLER();
}