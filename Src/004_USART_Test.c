/*
 * 004_USART_Test.c
 *
 *  Created on: Dec 21, 2025
 *      Author: aswin
 */

#include "stm32f303xx.h"



void delay_ms(uint32_t ms)
{
    volatile uint32_t i;
    while(ms--)
    {
        for(i = 0; i < 8000; i++);
    }
}


int main()
{
	SysClk_Config();
	USART_ClkControl(USART1, ENABLE);


	GPIO_Handle_t GPIOTX;

	GPIOTX.pGPIOx = GPIOA;
	GPIOTX.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN9;
	GPIOTX.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIOTX.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOTX.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOTX.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIOTX.GPIO_PinConfig.GPIO_PinAltFunMode = GPIO_AF7;



	GPIO_Handle_t GPIORX;

	GPIORX.pGPIOx = GPIOA;
	GPIORX.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN10;
	GPIORX.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIORX.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIORX.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIORX.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIORX.GPIO_PinConfig.GPIO_PinAltFunMode = GPIO_AF7;



	GPIO_Handle_t GPIOBtn;

	GPIOBtn.pGPIOx = GPIOC;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN13;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_Init(&GPIOBtn);
	GPIO_Init(&GPIOTX);
	GPIO_Init(&GPIORX);


	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioLed);


	USART_Handle_t USART1TEST;

	USART1TEST.pUSARTx = USART1;
	USART1TEST.USART_Config.USART_Baud = USART_BAUD_115200;
	USART1TEST.USART_Config.USART_Mode = USART_MODE_TX_ONLY;
	USART1TEST.USART_Config.USART_StopBits = USART_STOPBITS_1;
	USART1TEST.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	USART1TEST.USART_Config.USART_HWFlowControl = USART_FLOWCTRL_DIS;
	USART1TEST.USART_Config.USART_ParityControl = USART_PARITYCTRL_DIS;


//	// 1. Calculate the address of RCC_CFGR3
//	// RCC_BASEADDR is 0x40021000. CFGR3 offset is 0x30.
//	volatile uint32_t *pRCC_CFGR3 = (uint32_t *)(RCC_BASEADDR + 0x30);
//
//	// 2. Clear bits 16 and 17 (USART2SW)
//	*pRCC_CFGR3 &= ~(0x3 << 16);
//
//	// 3. Set bits 16 and 17 to '11' to select HSI (8 MHz) as the source
//	*pRCC_CFGR3 |= (0x3 << 16);

	USART_Init(&USART1TEST);


	uint8_t msg[] = "HELLO USART1\r\n";
	uint8_t startTx = 0;


	while(1)
	{
	    /* Wait for ONE button press */
	    if(startTx == 0)
	    {
	        if(GPIO_ReadPin(GPIOC, 13) == 0)   // Active LOW
	        {
	            delay_ms(50);                 // Debounce

	            if(GPIO_ReadPin(GPIOC, 13) == 0)
	            {
	                startTx = 1;              // Latch ON
	                GPIO_WritePin(GPIOA, 5, 1); // LED ON (indicates TX started)

	                while(GPIO_ReadPin(GPIOC, 13) == 0); // wait for release
	                delay_ms(50);
	            }
	        }
	    }
	    else
	    {
	        /* Repeated transmission */
	        USART_SendData(&USART1TEST, msg, sizeof(msg) - 1);
	        delay_ms(500);
	    }
	}



}








