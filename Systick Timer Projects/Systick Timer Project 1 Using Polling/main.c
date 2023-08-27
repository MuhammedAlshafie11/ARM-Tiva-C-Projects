#include "tm4c123gh6pm.h"

/* project one using polling */

void Systick_Init(void){
    NVIC_ST_RELOAD_R = 16000000 - 1; // Reload =  (require delay / clock tim_period) - 1
    NVIC_ST_CURRENT_R = 0; // to clear any current value
    NVIC_ST_CTRL_R |=(1<<0); // Enable the Timer
    NVIC_ST_CTRL_R |=(1<<2); // System clock
}
void GPIOF_Init(){

        SYSCTL_RCGCGPIO_R |=0x00000020; // Enabling Clock for PORTf
        while((SYSCTL_RCGCGPIO_R & 0x00000020 ) == 0){}; // waiting till the clock is activated
        GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock the pins
        GPIO_PORTF_CR_R = 0x0E;
        GPIO_PORTF_DIR_R = 0x0E;
        GPIO_PORTF_DEN_R = 0x0E;
}

void main(void)
{
    Systick_Init();
    GPIOF_Init();
    while (1)
    {
        if(((NVIC_ST_CTRL_R>>16)&1))
        {
            GPIO_PORTF_DATA_R^=(1<<1); // Turn on  the red led
            Systick_Init();
        }

     }
}


