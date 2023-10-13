/* 
 * File:   interrupt_manager.h
 * Author: Ahmed Yasser
 *
 * Created on October 11, 2023, 2:30 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

/* Section : Includes */
#include "interrupt_cfg.h"

/* Section : Macro Declarations */ 


/* Section : Macro Function Declaration */

/* Section : Data Type Declarations */

/* Section : Function Declarations */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);

void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);
#endif	/* INTERRUPT_MANAGER_H */

