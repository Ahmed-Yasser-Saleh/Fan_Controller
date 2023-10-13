/* 
 * File:   interrupt_internal.h
 * Author: Ahmed Yasser
 *
 * Created on September 19, 2023, 8:09 AM
 */

#ifndef INTERRUPT_INTERNAL_H
#define	INTERRUPT_INTERNAL_H

/* Section : Includes */
#include "interrupt_cfg.h"


/* Section : Macro Declarations */ 




/* Section : Macro Function Declaration */
#if INTERRUPT_INTERNAL_FEATURE == INTERRUPT_INTERNAL_ENABLE

#define ADC_INTERRUPT_NOT_OCCURE()         (PIR1bits.ADIF = 0)
#define ADC_INTERRUPT_OCCURE()             (PIR1bits.ADIF = 1)

#define ADC_INTERRUPT_DISABLE()            (PIE1bits.ADIE = 0)
#define ADC_INTERRUPT_ENABLE()             (PIE1bits.ADIE = 1)

#define TIMER0_INTERRUPT_NOT_OCCURE()      (INTCONbits.TMR0IF = 0)
#define TIMER0_INTERRUPT_OCCURE()          (INTCONbits.TMR0IF = 1)

#define TIMER0_INTERRUPT_DISABLE()         (INTCONbits.TMR0IE = 0)
#define TIMER0_INTERRUPT_ENABLE()          (INTCONbits.TMR0IE = 1)

#define TIMER1_INTERRUPT_NOT_OCCURE()      (PIR1bits.TMR1IF = 0)
#define TIMER1_INTERRUPT_OCCURE()          (PIR1bits.TMR1IF = 1)

#define TIMER1_INTERRUPT_DISABLE()         (PIE1bits.TMR1IE = 0)
#define TIMER1_INTERRUPT_ENABLE()          (PIE1bits.TMR1IE = 1)

#define TIMER2_INTERRUPT_NOT_OCCURE()      (PIR1bits.TMR2IF = 0)
#define TIMER2_INTERRUPT_OCCURE()          (PIR1bits.TMR2IF = 1)

#define TIMER2_INTERRUPT_DISABLE()         (PIE1bits.TMR2IE = 0)
#define TIMER2_INTERRUPT_ENABLE()          (PIE1bits.TMR2IE = 1)

#define TIMER3_INTERRUPT_NOT_OCCURE()      (PIR2bits.TMR3IF = 0)
#define TIMER3_INTERRUPT_OCCURE()          (PIR2bits.TMR3IF = 1)

#define TIMER3_INTERRUPT_DISABLE()         (PIE2bits.TMR3IE = 0)
#define TIMER3_INTERRUPT_ENABLE()          (PIE2bits.TMR3IE = 1)

#define CCP1_INTERRUPT_NOT_OCCURE()        (PIR1bits.CCP1IF = 0)
#define CCP1_INTERRUPT_OCCURE()            (PIR1bits.CCP1IF = 1)

#define CCP1_INTERRUPT_DISABLE()           (PIE1bits.CCP1IE = 0)
#define CCP1_INTERRUPT_ENABLE()            (PIE1bits.CCP1IE = 1)

#define CCP2_INTERRUPT_NOT_OCCURE()        (PIR2bits.CCP2IF = 0)
#define CCP2_INTERRUPT_OCCURE()            (PIR2bits.CCP2IF = 1)

#define CCP2_INTERRUPT_DISABLE()           (PIE2bits.CCP2IE = 0)
#define CCP2_INTERRUPT_ENABLE()            (PIE2bits.CCP2IE = 1)

#if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE

#define ADC_LOW_PRIORITY()                 (IPR1bits.ADIP = 0)
#define ADC_HIGH_PRIORITY()                (IPR1bits.ADIP = 1)

#define TIEMER0_LOW_PRIORITY()             (INTCON2bits.TMR0IP = 0)
#define TIEMER0_HIGH_PRIORITY()            (INTCON2bits.TMR0IP = 1)

#define TIEMER1_LOW_PRIORITY()             (IPR1bits.TMR1IP = 0)
#define TIEMER1_HIGH_PRIORITY()            (IPR1bits.TMR1IP = 1)

#define TIEMER2_LOW_PRIORITY()             (IPR1bits.TMR2IP = 0)
#define TIEMER2_HIGH_PRIORITY()            (IPR1bits.TMR2IP = 1)

#define TIEMER3_LOW_PRIORITY()             (IPR2bits.TMR3IP = 0)
#define TIEMER3_HIGH_PRIORITY()            (IPR2bits.TMR3IP = 1)

#define CCP1_LOW_PRIORITY()                (IPR1bits.CCP1IP = 0)
#define CCP1_HIGH_PRIORITY()               (IPR1bits.CCP1IP = 1)

#define CCP2_LOW_PRIORITY()                (IPR2bits.CCP2IP = 0)
#define CCP2_HIGH_PRIORITY()               (IPR2bits.CCP2IP = 1)

#endif

#endif
/* Section : Data Type Declaration */

#endif	/* INTERRUPT_INTERNAL_H */

