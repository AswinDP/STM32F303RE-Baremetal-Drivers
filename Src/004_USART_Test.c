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
	GPIO_Handle_t GPIOTX;

	GPIOTX.pGPIOx = GPIOA;
	GPIOTX.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN2;
	GPIOTX.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIOTX.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MEDIUM;
	GPIOTX.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOTX.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIOTX.GPIO_PinConfig.GPIO_PinAltFunMode = GPIO_AF7;


	GPIO_Handle_t GPIORX;

	GPIORX.pGPIOx = GPIOA;
	GPIORX.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN3;
	GPIORX.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIORX.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MEDIUM;
	GPIORX.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIORX.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIORX.GPIO_PinConfig.GPIO_PinAltFunMode = GPIO_AF7;


	GPIO_Handle_t GPIOBtn;

	GPIOBtn.pGPIOx = GPIOC;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN13;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GPIOBtn);
	GPIO_Init(&GPIOTX);
	GPIO_Init(&GPIORX);


	USART_Handle_t USART2TEST;

	USART2TEST.pUSARTx = USART2;
	USART2TEST.USART_Config.USART_Baud = USART_BAUD_115200;
	USART2TEST.USART_Config.USART_Mode = USART_MODE_TX_RX;
	USART2TEST.USART_Config.USART_StopBits = USART_STOPBITS_1;
	USART2TEST.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	USART2TEST.USART_Config.USART_HWFlowControl = USART_FLOWCTRL_DIS;
	USART2TEST.USART_Config.USART_ParityControl = USART_PARITYCTRL_DIS;

	USART_Init(&USART2TEST);


	uint8_t ch = 'U';

	while (1)
	{
	    USART_SendData(&USART2TEST, &ch, 1);
	    delay_ms(1000);
	}




}








