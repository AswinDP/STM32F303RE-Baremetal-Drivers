/*
 * stm32f303xx_it.c
 *
 *  Created on: Dec 28, 2025
 *      Author: aswin
 */


void EXTI0_IRQHandler(void)
{
    EXTI_HandleIRQ(0);
}

void EXTI1_IRQHandler(void)
{
    EXTI_HandleIRQ(1);
}

void EXTI9_5_IRQHandler(void)
{
    for (uint8_t i = 5; i <= 9; i++)
        EXTI_HandleIRQ(i);
}

void EXTI15_10_IRQHandler(void)
{
    for (uint8_t i = 10; i <= 15; i++)
        EXTI_HandleIRQ(i);
}
