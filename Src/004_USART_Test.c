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


	USART_Handle_t USART2TEST;

	USART2TEST.pUSARTx = USART2;
	USART2TEST.USART_Config.USART_Baud = USART_BAUD_9600;
	USART2TEST.USART_Config.USART_Mode = USART_MODE_RX_ONLY;
	USART2TEST.USART_Config.USART_StopBits = USART_STOPBITS_1;
	USART2TEST.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	USART2TEST.USART_Config.USART_HWFlowControl = USART_FLOWCTRL_DIS;
	USART2TEST.USART_Config.USART_ParityControl = USART_PARITYCTRL_DIS;

//	// 1. Calculate the address of RCC_CFGR3
//	// RCC_BASEADDR is 0x40021000. CFGR3 offset is 0x30.
//	volatile uint32_t *pRCC_CFGR3 = (uint32_t *)(RCC_BASEADDR + 0x30);
//
//	// 2. Clear bits 16 and 17 (USART2SW)
//	*pRCC_CFGR3 &= ~(0x3 << 16);
//
//	// 3. Set bits 16 and 17 to '11' to select HSI (8 MHz) as the source
//	*pRCC_CFGR3 |= (0x3 << 16);

	USART_Init(&USART2TEST);


	uint8_t myData[6] = {'1','2','3','4','5','6'};

	uint8_t currentIndex = 0;
	uint8_t arraySize = 6;

	while(1)
	{
	    // 1. Detect the Press (Active LOW)
	    if (GPIO_ReadPin(GPIOC, 13) == 0)
	    {
	        // 2. Short Delay to skip the initial "bouncing" noise
	        delay_ms(50);

	        // 3. Double check the button is still pressed (validates it's not noise)
	        if (GPIO_ReadPin(GPIOC, 13) == 0)
	        {
	            // Turn LED ON
	            GPIO_WritePin(GPIOA, 5, 1);

	            // 4. Send the Data
	            USART_SendData(&USART2TEST, &myData[currentIndex], 1);

	            // 5. Update index for next time
	            currentIndex++;
	            if (currentIndex >= arraySize) currentIndex = 0;

	            // 6. TRAP: Wait here as long as the button is held down
	            // This prevents the loop from repeating while you are still touching the button
	            while(GPIO_ReadPin(GPIOC, 13) == 0);

	            // 7. Small exit delay to prevent "release bounce"
	            delay_ms(50);

	            // Turn LED OFF
	            GPIO_WritePin(GPIOA, 5, 0);
	        }
	    }
	}



}








