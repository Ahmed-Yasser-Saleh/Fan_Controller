/* 
 * File:   timer2.h
 * Author: Ahmed Yasser
 *
 * Created on September 30, 2023, 6:34 AM
 */

#ifndef TIMER2_H
#define	TIMER2_H
/* Section : Includes */
#include "../mcal_std_types.h"
#include <../proc/pic18f4620.h>
#include "../device_config.h"
#include "../Interrupt/interrupt_cfg.h"
#include "../Interrupt/interrupt_internal.h"


/* Section : Macro Declarations */  

            



/* Section : Macro Function Declaration */

#define TIMER2_MODULE_DISABLE()                 (T2CONbits.TMR2ON = 0)
#define TIMER2_MODULE_ENABLE()                  (T2CONbits.TMR2ON = 1)

/* Section : Data Type Declarations */
typedef enum{
    TIMER2_POSTSCALER_DIV_BY_1 = 0,
    TIMER2_POSTSCALER_DIV_BY_2,
    TIMER2_POSTSCALER_DIV_BY_3,
    TIMER2_POSTSCALER_DIV_BY_4,
    TIMER2_POSTSCALER_DIV_BY_5,
    TIMER2_POSTSCALER_DIV_BY_6,
    TIMER2_POSTSCALER_DIV_BY_7,
    TIMER2_POSTSCALER_DIV_BY_8,
    TIMER2_POSTSCALER_DIV_BY_9,
    TIMER2_POSTSCALER_DIV_BY_10,
    TIMER2_POSTSCALER_DIV_BY_11,
    TIMER2_POSTSCALER_DIV_BY_12,
    TIMER2_POSTSCALER_DIV_BY_13,
    TIMER2_POSTSCALER_DIV_BY_14,
    TIMER2_POSTSCALER_DIV_BY_15,
    TIMER2_POSTSCALER_DIV_BY_16,        
}timer2_postscaler_select_t;

typedef enum{
    TIMER2_PRESCALER_DIV_BY_1 = 0,
    TIMER2_PRESCALER_DIV_BY_4,
    TIMER2_PRESCALER_DIV_BY_16
}timer2_prescaler_select_t;

typedef struct {
    #if INTERRUPT_INTERNAL_FEATURE == INTERRUPT_INTERNAL_ENABLE
    void (*interrupt_timer2)(void);
    #if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE
    interrupt_priority_status priority;
    #endif
    #endif

    timer2_prescaler_select_t prescaler_timer2_value;
    timer2_postscaler_select_t postscaler_timer2_value;
    uint16 value_start_cnt;
}Timer2_cfg_t;

/* Section : Function Declarations */
Std_ReturnType Timer2_init(Timer2_cfg_t *timer2);
Std_ReturnType Timer2_deinit(Timer2_cfg_t *timer2);
Std_ReturnType Timer2_write_value(Timer2_cfg_t *timer2, uint8 value);
Std_ReturnType Timer2_read_value(Timer2_cfg_t *timer2, uint8 *value);

#endif	/* TIMER2_H */

