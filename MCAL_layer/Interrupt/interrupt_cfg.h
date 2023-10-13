/* 
 * File:   interrupt_cfg.h
 * Author: Ahmed Yasser
 *
 * Created on September 5, 2023, 9:33 PM
 */

#ifndef INTERRUPT_CFG_H
#define	INTERRUPT_CFG_H

/* Section : Includes */
#include "interrupt_generate_cfg.h"

/* Section : Macro Declarations */ 

#define INTERRUPT_DISABLE              0x00
#define INTERRUPT_ENABLE               0x01

#define INTERRUPT_NOT_OCCURE           0x00
#define INTERRUPT_OCCURE               0x01

#define INTERRUPT_LOW_PRIORITY         0x00
#define INTERRUPT_HIGH_PRIORITY        0x01

#define INTERRUPT_FALLING_EDGE         0x00
#define INTERRUPT_RISING_EDGE          0x01

/* Section : Macro Function Declaration */

#if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE
#define INTERRUPT_PRIORITY_GENERAL_ENABLE()                (RCONbits.IPEN = 1)
#define INTERRUPT_HIGH_PRIORITY_DISABLE()                  (INTCONbits.GIEH = 0)
#define INTERRUPT_HIGH_PRIORITY_ENABLE()                   (INTCONbits.GIEH = 1)
#define INTERRUPT_LOW_PRIORITY_DISABEL()                   (INTCONbits.GIEL = 0)
#define INTERRUPT_LOW_PRIORITY_ENABEL()                    (INTCONbits.GIEL = 1)

#else
#define INTERRUPT_PRIORITY_GENERAL_DISABLE()               (RCONbits.IPEN = 0) 
#define INTERRUPT_PeripheralInterrupt_Enable()             (INTCONbits.PEIE = 1) 
#define INTERRUPT_PeripheralInterrupt_Disable()            (INTCONbits.PEIE = 0)
#define INTERRUPT_GlobalInterrupt_Enable()                 (INTCONbits.GIE = 1) 
#define INTERRUPT_GlobalInterrupt_Disable()               (INTCONbits.GIE = 0)

#endif

/* Section : Data Type Declarations */


typedef enum{
    LOW_PRIORITY,
    HIGH_PRIORITY        
}interrupt_priority_status;


#endif	/* INTERRUPT_CFG_H */

