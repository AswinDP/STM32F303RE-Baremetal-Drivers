/*
 * stm32f303xx_tim_driver.c
 *
 *  Created on: Dec 23, 2025
 *      Author: aswin
 */


#include "stm32f303xx_tim_driver.h"


void GP1TIM_PeriClockControl(GP1_TIM_Regs_t *pTIMx, uint8_t EnorDi)
{

	if(EnorDi == ENABLE)
		{
			if(pTIMx == TIM2)
			{
				TIM2_CLK_EN();
			}
			else if(pTIMx == TIM3)
			{
				TIM3_CLK_EN();
			}
			else if(pTIMx == TIM4)
			{
				TIM4_CLK_EN();
			}
		}

	else
		{
			if(pTIMx == TIM2)
			{
				TIM2_CLK_DI();
			}
			else if(pTIMx == TIM3)
			{
				TIM3_CLK_DI();
			}
			else if(pTIMx == TIM4)
			{
				TIM4_CLK_DI();
			}
		}
}


void GP1TIM_Init(GP1_TIM_Handle_t *pTIMHandle)
{

	GP1TIM_PeriClockControl(pTIMHandle->pGP1TIMx, ENABLE);

	pTIMHandle->pGP1TIMx->CR1 &= ~(1 << GP1_TIM_CR1_CEN);
	uint32_t temp = 0;

	temp |= (pTIMHandle->GP1_TIM_Config.GP1TIM_ClockDivision << GP1_TIM_CR1_CKD);
	temp |= (1 << GP1_TIM_CR1_ARPE);

	temp &= ~(3 << GP1_TIM_CR1_CMS);
	temp |= (pTIMHandle->GP1_TIM_Config.GP1TIM_CounterMode << GP1_TIM_CR1_DIR);

	pTIMHandle->pGP1TIMx->CR1 = temp;

	pTIMHandle->pGP1TIMx->PSC = pTIMHandle->GP1_TIM_Config.GP1TIM_Prescaler;
	pTIMHandle->pGP1TIMx->ARR = pTIMHandle->GP1_TIM_Config.GP1TIM_AutoReload;

	pTIMHandle->pGP1TIMx->EGR |= (1 << GP1_TIM_EGR_UG);
	while(!(pTIMHandle->pGP1TIMx->SR & (1 << GP1_TIM_SR_UIF)));
	pTIMHandle->pGP1TIMx->SR &= ~(1 << GP1_TIM_SR_UIF);
	pTIMHandle->State = GP1TIM_STATE_RDY;

}


void GP1TIM_Start(GP1_TIM_Handle_t *pTIMHandle)
{
	if(pTIMHandle->State == GP1TIM_STATE_RDY)
	{
		pTIMHandle->pGP1TIMx->CR1 |= (1 << GP1_TIM_CR1_CEN);
		pTIMHandle->State = GP1TIM_STATE_BSY;
	}


}


void GP1TIM_Stop(GP1_TIM_Handle_t *pTIMHandle)
{
	if(pTIMHandle->State == GP1TIM_STATE_BSY)
	{
		pTIMHandle->pGP1TIMx->CR1 &= ~(1 << GP1_TIM_CR1_CEN);
		pTIMHandle->State = GP1TIM_STATE_RDY;
	}


}


void GP1TIM_Delay_ms(GP1_TIM_Handle_t *pTIMHandle, uint32_t delay_ms)
{
	// Max delay using Delay_ms is ~65.5 seconds for 16-bit timers (TIM3, TIM4)
	if(pTIMHandle->State == GP1TIM_STATE_RDY)
	{
		//Assuming 8MHz Clock
		pTIMHandle->pGP1TIMx->PSC = 7999;
		pTIMHandle->pGP1TIMx->ARR = delay_ms - 1;

		pTIMHandle->pGP1TIMx->EGR |= (1 << GP1_TIM_EGR_UG);
		pTIMHandle->pGP1TIMx->SR &= ~(1 << GP1_TIM_SR_UIF);

		GP1TIM_Start(pTIMHandle);

		while(!(pTIMHandle->pGP1TIMx->SR & (1 << GP1_TIM_SR_UIF)));
		pTIMHandle->pGP1TIMx->SR &= ~(1 << GP1_TIM_SR_UIF);

		GP1TIM_Stop(pTIMHandle);
	}
}


void GP1TIM_Delay_us(GP1_TIM_Handle_t *pTIMHandle, uint32_t delay_us)
{
	// Max delay using Delay_us is ~65 ms for 16-bit timers (TIM3, TIM4)
	// and ~71 minutes for 32-bit timer (TIM2, if configured as 32-bit)
	if(pTIMHandle->State == GP1TIM_STATE_RDY)
	{
		//Assuming 8MHz Clock
		pTIMHandle->pGP1TIMx->PSC = 7;
		pTIMHandle->pGP1TIMx->ARR = delay_us - 1;

		pTIMHandle->pGP1TIMx->EGR |= (1 << GP1_TIM_EGR_UG);
		pTIMHandle->pGP1TIMx->SR &= ~(1 << GP1_TIM_SR_UIF);

		GP1TIM_Start(pTIMHandle);

		while(!(pTIMHandle->pGP1TIMx->SR & (1 << GP1_TIM_SR_UIF)));
		pTIMHandle->pGP1TIMx->SR &= ~(1 << GP1_TIM_SR_UIF);

		GP1TIM_Stop(pTIMHandle);
	}
}


void GP1TIM_DeInit(GP1_TIM_Handle_t *pTIMHandle)
{
	if(pTIMHandle->pGP1TIMx == TIM2)
	{
		TIM2_REG_RST();
	}
	else if(pTIMHandle->pGP1TIMx == TIM3)
	{
		TIM3_REG_RST();
	}
	else if(pTIMHandle->pGP1TIMx == TIM4)
	{
		TIM4_REG_RST();
	}

	pTIMHandle->State = GP1TIM_STATE_RST;
}
