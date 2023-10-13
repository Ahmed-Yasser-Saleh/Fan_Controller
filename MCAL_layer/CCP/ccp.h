/* 
 * File:   ccp.h
 * Author: Ahmed Yasser
 *
 * Created on October 3, 2023, 6:13 AM
 */

#ifndef CCP_H
#define	CCP_H

/* Section : Includes */
#include "../mcal_std_types.h"
#include <../proc/pic18f4620.h>
#include "../device_config.h"
#include "../Interrupt/interrupt_cfg.h"
#include "../Interrupt/interrupt_internal.h"
#include "ccp_cfg.h"
#include "../GPIO/gpio.h"
#include "../TIMER2/timer2.h"


/* Section : Macro Declarations */  
#define CCP_MODULE_DISABLE                 ((uint8)0x00)
/* Timer2 Input Clock Post-scaler */
#define CCP_TIMER2_POSTSCALER_DIV_BY_1       1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2       2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3       3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4       4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5       5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6       6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7       7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8       8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9       9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10      10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11      11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12      12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13      13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14      14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15      15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16      16

/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16
            



/* Section : Macro Function Declaration */

#define TIMER1_CLK_SOURCE_CCP()                             do {(T3CONbits.T3CCP1 = 0);\
                                                               (T3CONbits.T3CCP2 = 0);\
                                                               }while(0)
                                                                
#define TIMER3_CLK_SOURCE_CCP()                             do { (T3CONbits.T3CCP1 = 1);\
                                                                 (T3CONbits.T3CCP2 = 1);\
                                                                }while(0)

#define TIMER1_CLK_SOURCE_CCP1_TIMER3_CLK_SOURCE_CCP2()     do {(T3CONbits.T3CCP1 = 1);\
                                                                 (T3CONbits.T3CCP2 = 0);\
                                                                }while(0)


#define  CCP1_DISABLE()                                (CCP1CONbits.CCP1M = 0x00) 

#if MODE_CCP1_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE

#define CAPTURE_MODE_EVERY_FALLING_EDGE_CCP1()              (CCP1CONbits.CCP1M = 0x04)
#define CAPTURE_MODE_EVERY_RISING_EDGE_CCP1()               (CCP1CONbits.CCP1M = 0x05)
#define CAPTURE_MODE_EVERY_4_RISING_EDGE_CCP1()             (CCP1CONbits.CCP1M = 0x06)
#define CAPTURE_MODE_EVERY_16_RISING_EDGE_CCP1()            (CCP1CONbits.CCP1M = 0x07)


#elif MODE_CCP1_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE

#define COMPARE_MODE_TOGGLE_OUTPUT_CCP1()                   (CCP1CONbits.CCP1M = 0x02)
#define COMPARE_MODE_LOW_OUTPUT_CCP1()                      (CCP1CONbits.CCP1M = 0x08)
#define COMPARE_MODE_HIGH_OUTPUT_CCP1()                     (CCP1CONbits.CCP1M = 0x09)
#define COMPARE_MODE_GENERATE_INTERRUPT_CCP1()              (CCP1CONbits.CCP1M = 0x0A)
#define COMPARE_MODE_TRIGGER_SPECIAL_EVENT_CCP1()           (CCP1CONbits.CCP1M = 0x0B)


#elif MODE_CCP1_MODULE_SELECTED == PWM_MODE_CCP_MODULE

#define PWM_MODE_CCP1()                                     (CCP1CONbits.CCP1M = 0x0C) 

#endif



#define  CCP2_DISABLE()                                (CCP2CONbits.CCP2M = 0x00) 

#if MODE_CCP2_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE

#define CAPTURE_MODE_EVERY_FALLING_EDGE_CCP2()              (CCP2CONbits.CCP2M = 0x04)
#define CAPTURE_MODE_EVERY_RISING_EDGE_CCP2()               (CCP2CONbits.CCP2M = 0x05)
#define CAPTURE_MODE_EVERY_4_RISING_EDGE_CCP2()             (CCP2CONbits.CCP2M = 0x06)
#define CAPTURE_MODE_EVERY_16_RISING_EDGE_CCP2()            (CCP2CONbits.CCP2M = 0x07)

#elif MODE_CCP2_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE

#define COMPARE_MODE_TOGGLE_OUTPUT_CCP2()                   (CCP2CONbits.CCP2M = 0x02)
#define COMPARE_MODE_LOW_OUTPUT_CCP2()                      (CCP2CONbits.CCP2M = 0x08)
#define COMPARE_MODE_HIGH_OUTPUT_CCP2()                     (CCP2CONbits.CCP2M = 0x09)
#define COMPARE_MODE_GENERATE_INTERRUPT_CCP2()              (CCP2CONbits.CCP2M = 0x0A)
#define COMPARE_MODE_TRIGGER_SPECIAL_EVENT_CCP2()           (CCP2CONbits.CCP2M = 0x0B)

#elif MODE_CCP2_MODULE_SELECTED == PWM_MODE_CCP_MODULE

#define PWM_MODE_CCP2()                                     (CCP2CONbits.CCP2M = 0x0C) 

#endif


/* Section : Data Type Declarations */
typedef enum{
  CAPTURE_MODE_EVERY_FALLING_EDGE,  
  CAPTURE_MODE_EVERY_RISING_EDGE,
  CAPTURE_MODE_EVERY_4_RISING_EDGE,
  CAPTURE_MODE_EVERY_16_RISING_EDGE
}capture_status_t;

typedef enum{
  TIMER1_CLK_SRC_CCP,  
  TIMER1_CLK_SRC_CCP1_TIMER3_CLK_SOURCE_CCP2,
  TIMER3_CLK_SRC_CCP
}capture_compare_clk_source_t;

typedef enum {
 TOGGLE_PIN = 2,
 LOW_PIN = 8,
 HIGH_PIN,
 UNCHANGED_GENERATE_INTERRUPT,
 TRIGGER_EVENT        
}compare_mode_t;

typedef struct{
    void (*interrupt_ccp1)(void);
    interrupt_priority_status CCP1_priority;
  
    void (*interrupt_ccp2)(void);
    interrupt_priority_status CCP2_priority;
    
    #if CCP_MODULE_SELECTED == CCP2_MODULE
    void (*interrupt_ccp2)(void);
    interrupt_priority_status CCP2_priority;
    #endif

   #if (MODE_CCP1_MODULE_SELECTED == PWM_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == PWM_MODE_CCP_MODULE)
    uint32 pwm_freq;
    uint8 timer2_prescaler;
    uint8 timer2_postscaler; 
   #endif

    #if (MODE_CCP1_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE)
      capture_status_t capture_st;
      capture_compare_clk_source_t capture_compare_clk_source;
    #endif 

    #if (MODE_CCP1_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE)
     compare_mode_t  compare_mode_st;
     capture_compare_clk_source_t capture_compare_clk_source;
    #endif
    uint8 ccp_mode_module;
    uint8 ccp_mode;
    Pin_Config_t ccp_pin;
}ccp_confg_t;
 
/* Section : Function Declarations */
Std_ReturnType CCP_Init( ccp_confg_t *ccp_obj);
Std_ReturnType CCP_DeInit( ccp_confg_t *ccp_obj);

#if (MODE_CCP1_MODULE_SELECTED == PWM_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == PWM_MODE_CCP_MODULE)
Std_ReturnType CCP_PWM_Set_Duty( ccp_confg_t *ccp_obj, uint8 duty);
Std_ReturnType CCP_PWM_Stop( ccp_confg_t *ccp_obj);
#endif

#if (MODE_CCP1_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == CAPTURE_MODE_CCP_MODULE)
Std_ReturnType CCP_Capture_Mode_Read_Value(ccp_confg_t *ccp_obj, uint16 *capture_value);
#endif

#if (MODE_CCP1_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE) || (MODE_CCP2_MODULE_SELECTED == COMPARE_MODE_CCP_MODULE)
Std_ReturnType CCP_Compare_Mode_write_Value(ccp_confg_t *ccp_obj, uint16 capture_value);
#endif

#endif	/* CCP_H */

