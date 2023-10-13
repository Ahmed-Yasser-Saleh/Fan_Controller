/* 
 * File:   ccp_cfg.h
 * Author: Ahmed Yasser
 *
 * Created on October 3, 2023, 6:14 AM
 */

#ifndef CCP_CFG_H
#define	CCP_CFG_H


/* Section : Includes */



/* Section : Macro Declarations */  
#define CCP1_MODULE                    0x00
#define CCP2_MODULE                    0x01

#define CAPTURE_MODE_CCP_MODULE        0x00
#define COMPARE_MODE_CCP_MODULE        0x01
#define PWM_MODE_CCP_MODULE            0x02
            
#define CCP_MODULE_SELECTED                  CCP1_MODULE   

#define MODE_CCP1_MODULE_SELECTED            PWM_MODE_CCP_MODULE 
#define MODE_CCP2_MODULE_SELECTED            PWM_MODE_CCP_MODULE 



/* Section : Macro Function Declaration */


/* Section : Data Type Declarations */


/* Section : Function Declarations */

#endif	/* CCP_CFG_H */

