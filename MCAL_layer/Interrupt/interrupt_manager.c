/* 
 * File:   interrupt_manager.h
 * Author: Ahmed Yasser
 *
 * Created on September 7, 2023, 2:30 PM
 */

/* Section : Includes */
#include "interrupt_manager.h"

/* Section : Macro Declarations */ 


/* Section : Macro Function Declaration */

/* Section : Data Type Declarations */

/* Section : Function Declarations */

#if INTERRUPT_PRIORITY_FEATURE == INTERRUPT_PRIORITY_ENABLE
void __interrupt() InterruptManagerHigh(void){
   if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCURE == PIR1bits.ADIF)){
        ADC_ISR(); /* External Interrupt 0 */
    }
    else{ /* Nothing */ }
}

void __interrupt(low_priority) InterruptManagerLow(void){ 

    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCURE == PIR1bits.ADIF)){
        ADC_ISR(); /* External Interrupt 0 */
    }
    else{ /* Nothing */ }
}
#else

void __interrupt() InterruptManager(void){
 
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCURE == PIR1bits.ADIF)){
        ADC_ISR(); /* External Interrupt 0 */
    }
    else{ /* Nothing */ }
}
#endif
