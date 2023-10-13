/* 
 * File:   interrupt_generate_cfg.h
 * Author: Ahmed Yasser
 *
 * Created on September 5, 2023, 11:02 PM
 */


#ifndef INTERRUPT_GENERATE_CFG_H
#define	INTERRUPT_GENERATE_CFG_H

/* Section : Includes */
#include "../mcal_std_types.h"
#include <../proc/pic18f4620.h>
#include "../device_config.h"


/* Section : Macro Declarations */
#define INTERRUPT_PRIORITY_DISABLE     0x00
#define INTERRUPT_PRIORITY_ENABLE      0x01
#define INTERRUPT_PRIORITY_FEATURE              INTERRUPT_PRIORITY_DISABLE

#define INTERRUPT_EXTERNAL_DISABLE     0x00 
#define INTERRUPT_EXTERNAL_ENABLE      0x01 

#define INTERRUPT_INTERNAL_DISABLE     0x00 
#define INTERRUPT_INTERNAL_ENABLE      0x01 

#define INTERRUPT_INTERNAL_DISABLE     0x00 
#define INTERRUPT_INTERNAL_ENABLE      0x01 

#define INTERRUPT_INTERNAL_FEATURE              INTERRUPT_INTERNAL_ENABLE        

#define INTERRUPT_INT_EXTERNAL_FEATURE          INTERRUPT_EXTERNAL_ENABLE 
#define INTERRUPT_ONCHANGE_EXTERNAL_FEATURE     INTERRUPT_EXTERNAL_ENABLE 

#endif	/* INTERRUPT_GENERATE_CFG_H */

