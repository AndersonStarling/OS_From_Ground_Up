#include <stdint.h>
#include "stm32f4xx.h"


void System_Timer_Init(void)
{
    /* Clear current value */
    SysTick->VAL = 0;

    /* Program reload value */
    SysTick->LOAD |= 0xF42400;

    /* Use prosessor clock */
    SysTick->CTRL |= (1 << SysTick_CTRL_CLKSOURCE_Pos);

    /* Enable systick exception */
    SysTick->CTRL |= (1 << SysTick_CTRL_TICKINT_Pos);

}

void System_Timer_Start(void)
{
    /* Enable system timer */
    SysTick->CTRL |= (1 << SysTick_CTRL_ENABLE_Pos);
}




