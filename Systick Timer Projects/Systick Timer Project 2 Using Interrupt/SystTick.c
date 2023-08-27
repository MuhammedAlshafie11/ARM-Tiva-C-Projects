/*
 * SystTick.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Muhammed
 */
#include "SystTick.h"
/* Using INterrupt*/



void Systick_Init(void){
    NVIC_ST_RELOAD_R = 16000000 - 1; // Reload =  (require delay / clock tim_period) - 1
    NVIC_ST_CURRENT_R = 0; // to clear any current value
    NVIC_ST_CTRL_R |=(1<<0); // Enable the Timer
    NVIC_ST_CTRL_R |=(1<<1); // Enable interrupt
    NVIC_ST_CTRL_R |=(1<<2); // System clock
}
