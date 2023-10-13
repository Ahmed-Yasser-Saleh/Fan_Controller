/* 
 * File:   Fan_contraller.c
 * Author: Ahmed Yasser
 *
 * Created on October 13, 2023, 1:56 PM
 */

#include "Fan_contraller.h"
#include "MCAL_layer/ADC/adc.h"
#include "MCAL_layer/CCP/ccp.h"
#include "MCAL_layer/TIMER2/timer2.h"

void adc_interrupt(void);

volatile uint16 lm35_res;
uint16 lm35_res_celsius;
uint8 arr_val[6];

lcd_confg_4_t lcd_4bit = {
 .rs_lcd.port = PORTD_INDEX,
 .rs_lcd.pin  = PIN2,
 .rs_lcd.direction = OUTPUT,
 .rs_lcd.logic     = LOW,
 .en_lcd.port = PORTD_INDEX,
 .en_lcd.pin = PIN3,
 .en_lcd.direction = OUTPUT,
 .en_lcd.logic = LOW,
 .lcd_pin[0].port = PORTD_INDEX,
 .lcd_pin[0].pin = PIN4,
 .lcd_pin[0].direction = OUTPUT,
 .lcd_pin[0].logic = LOW,
 .lcd_pin[1].port = PORTD_INDEX,    
 .lcd_pin[1].pin  = PIN5,
 .lcd_pin[1].direction = OUTPUT,
 .lcd_pin[1].logic = LOW,
 .lcd_pin[2].port = PORTD_INDEX,
 .lcd_pin[2].pin = PIN6,
 .lcd_pin[2].direction = OUTPUT,
 .lcd_pin[2].logic = LOW,
 .lcd_pin[3].port = PORTD_INDEX,
 .lcd_pin[3].pin  = PIN7,
 .lcd_pin[3].direction = OUTPUT,
 .lcd_pin[3].logic = LOW,
 };

motor_confg_t motor = {
  .motor_confg[0].port = PORTC_INDEX,
  .motor_confg[0].pin  = PIN0,
  .motor_confg[0].direction = OUTPUT,
  .motor_confg[0].logic = MOTOR_OFF,
  .motor_confg[1].port = PORTC_INDEX,
  .motor_confg[1].pin = PIN1,
  .motor_confg[1].direction = OUTPUT,
  .motor_confg[1].logic = MOTOR_OFF
};

adc_confg_t adc_0 = {
 .internalfun_interrupt = adc_interrupt,
 .adc_pin_confg.port = PORTA_INDEX,
 .adc_pin_confg.pin = PIN0,
 .adc_pin_confg.direction = INPUT,
 .adc_channel = ADC_CHANNEL_AN0,
 .adc_conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
 .adc_acquisition_time = ADC_12_TAD,
 .result_format = 1,
 .voltage_reference = 0
};

ccp_confg_t ccp_pwm_obj = {
.interrupt_ccp1 = NULL,
.ccp_mode = CCP1_MODULE,
.ccp_mode_module = PWM_MODE_CCP_MODULE,
.ccp_pin.port = PORTC_INDEX,
.ccp_pin.pin = PIN2,
.ccp_pin.direction = OUTPUT,
.pwm_freq = 10000,
.timer2_prescaler = CCP_TIMER2_PRESCALER_DIV_BY_1,
.timer2_postscaler = CCP_TIMER2_POSTSCALER_DIV_BY_1        
};

Timer2_cfg_t timer2_obj = {
.interrupt_timer2 = NULL,
.prescaler_timer2_value = TIMER2_PRESCALER_DIV_BY_1,
.postscaler_timer2_value = TIMER2_POSTSCALER_DIV_BY_1,
.value_start_cnt = 0
};

int main() {
    Std_ReturnType ret = E_NOT_OK;
     application_initialize();
     
     motor_move_right(&motor);
     while(1){
         ret = ADC_StartConversion_Interrupt(&adc_0, adc_0.adc_channel);
         
         lm35_res_celsius = ((lm35_res * 4.88f) / 10); //output of LM35 IS 10.0 mv/degree
         
         cnvert_uint8_to_string(lm35_res_celsius,arr_val);
         send_4_bit_string_data_pos(&lcd_4bit, 1, 1, "Temperature = ");
         send_4_bit_string_data_pos(&lcd_4bit, 1, 15, arr_val);
         send_4_bit_char_data(&lcd_4bit,'C');
         
         if(lm35_res_celsius < 25)
         {
             ret = CCP_PWM_Set_Duty(&ccp_pwm_obj,0);
             send_4_bit_string_data_pos(&lcd_4bit, 2, 1, "Motor Is Off");
             send_4_bit_string_data_pos(&lcd_4bit, 3, 1, "            ");
         }
         
         else if(lm35_res_celsius >= 25 && lm35_res_celsius < 40)
         {
             ret = CCP_PWM_Set_Duty(&ccp_pwm_obj,25);
             send_4_bit_string_data_pos(&lcd_4bit, 2, 1, "Motor Is On ");
             send_4_bit_string_data_pos(&lcd_4bit, 3, 1, "25% Capacity");
         }
         
         else if(lm35_res_celsius >= 40 && lm35_res_celsius < 50)
         {
             ret = CCP_PWM_Set_Duty(&ccp_pwm_obj,50);
             send_4_bit_string_data_pos(&lcd_4bit, 2, 1, "Motor Is On ");
             send_4_bit_string_data_pos(&lcd_4bit, 3, 1, "50% Capacity");
         }
         else if(lm35_res_celsius >= 50 && lm35_res_celsius < 60)
         {
             ret = CCP_PWM_Set_Duty(&ccp_pwm_obj,75);
             send_4_bit_string_data_pos(&lcd_4bit, 2, 1, "Motor Is On ");
             send_4_bit_string_data_pos(&lcd_4bit, 3, 1, "75% Capacity ");
         }
         
         else if(lm35_res_celsius >= 60)
         {
             ret = CCP_PWM_Set_Duty(&ccp_pwm_obj,100);
             send_4_bit_string_data_pos(&lcd_4bit, 2, 1, "Motor Is On ");
             send_4_bit_string_data_pos(&lcd_4bit, 3, 1, "Full Capacity");
         }
         else{/* NOTHING */}
     }
      return (EXIT_SUCCESS);
}

void application_initialize(void){
    lcd_pins_4_initialize(&lcd_4bit);
    motor_initialize(&motor);
    adc_init(&adc_0);
    CCP_Init(&ccp_pwm_obj);
    Timer2_init(&timer2_obj);
}

void adc_interrupt(void){
     Std_ReturnType ret = E_NOT_OK;
    ret = adc_getconversion_result(&adc_0,&lm35_res);
}