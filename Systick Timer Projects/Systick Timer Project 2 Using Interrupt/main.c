#include "tm4c123gh6pm.h"
#include "SystTick.h"
/* project one using interrupts */


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

    }
}


void SysTick_Handler(void)
{
    if(((NVIC_ST_CTRL_R>>16)&1))
    {
        GPIO_PORTF_DATA_R^=(1<<1); // Turn on  the red led
        Systick_Init();
    }

}
