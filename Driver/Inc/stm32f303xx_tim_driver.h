/*
 * stm32f303xx_tim_driver.h
 *
 *  Created on: Dec 23, 2025
 *      Author: aswin
 */

#ifndef INC_STM32F303XX_TIM_DRIVER_H_
#define INC_STM32F303XX_TIM_DRIVER_H_


#include "stm32f303xx.h"


typedef struct{

    uint32_t GP1TIM_Prescaler;        /* PSC value */
    uint32_t GP1TIM_AutoReload;       /* ARR value */
    uint32_t GP1TIM_CounterMode;      /* Up &| Down */
    uint32_t GP1TIM_ClockDivision;    /* CKD */

}GP1_TIM_Config_t;


typedef struct{

	GP1_TIM_Regs_t *pGP1TIMx;
	GP1_TIM_Config_t GP1_TIM_Config;
    uint32_t Channel;            /* Active channel */
    uint8_t  State;              /* RESET / READY / BUSY */

}GP1_TIM_Handle_t;


#define GP1TIM_CKD_1						0
#define GP1TIM_CKD_2						1
#define GP1TIM_CKD_4						2

#define GP1TIM_COUNTMODE_UP            		0  /* DIR = 0 */
#define GP1TIM_COUNTMODE_DOWN          		1  /* DIR = 1 */
#define GP1TIM_COUNTMODE_CENTER_ALIGNED 	2  /* CMS != 00 */

#define GP1TIM_STATE_RST					RESET
#define GP1TIM_STATE_RDY					READY
#define GP1TIM_STATE_BSY					BUSY




/* Clock control */
void GP1TIM_PeriClockControl(GP1_TIM_Regs_t *pTIMx, uint8_t EnorDi);

/* Base timer */
void GP1TIM_Init(GP1_TIM_Handle_t *pTIMHandle);
void GP1TIM_DeInit(GP1_TIM_Handle_t *pTIMHandle);
void GP1TIM_Start(GP1_TIM_Handle_t *pTIMHandle);
void GP1TIM_Stop(GP1_TIM_Handle_t *pTIMHandle);

/* Delay services */
void GP1TIM_Delay_ms(GP1_TIM_Handle_t *pTIMHandle, uint32_t delay_ms);
void GP1TIM_Delay_us(GP1_TIM_Handle_t *pTIMHandle, uint32_t delay_us);

/* Output Compare */
void GP1TIM_OC_Init(GP1_TIM_Handle_t *pTIMHandle);
void GP1TIM_OC_Start(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);
void GP1TIM_OC_Stop(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);

/* PWM */
void GP1TIM_PWM_Init(GP1_TIM_Handle_t *pTIMHandle);
void GP1TIM_PWM_Start(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);
void GP1TIM_PWM_Stop(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);
void GP1TIM_PWM_SetDuty(GP1_TIM_Regs_t *pTIMx, uint8_t Channel, uint32_t Duty);

/* Input Capture */
void GP1TIM_IC_Init(GP1_TIM_Handle_t *pTIMHandle);
void GP1TIM_IC_Start(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);
void GP1TIM_IC_Stop(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);
uint32_t GP1TIM_IC_GetCaptureValue(GP1_TIM_Regs_t *pTIMx, uint8_t Channel);






#endif /* INC_STM32F303XX_TIM_DRIVER_H_ */
