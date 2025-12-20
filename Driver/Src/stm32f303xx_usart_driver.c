/*
 * stm32f303xx_usart_driver.c
 *
 *  Created on: Dec 20, 2025
 *      Author: aswin
 */

#include "stm32f303xx.h"


void USART_ClkControl(USART_Regs_t *pUSARTx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pUSARTx == USART1)
		{
			USART1_CLK_EN();
		}
		else if(pUSARTx == USART2)
		{
			USART2_CLK_EN();
		}
		else if(pUSARTx == UART3)
		{
			UART3_CLK_EN();
		}
		else if(pUSARTx == UART4)
		{
			UART4_CLK_EN();
		}
		else if(pUSARTx == UART5)
		{
			UART5_CLK_EN();
		}
	}

	else
	{
		if(pUSARTx == USART1)
		{
			USART1_CLK_DI();
		}
		else if(pUSARTx == USART2)
		{
			USART2_CLK_DI();
		}
		else if(pUSARTx == UART3)
		{
			UART3_CLK_DI();
		}
		else if(pUSARTx == UART4)
		{
			UART4_CLK_DI();
		}
		else if(pUSARTx == UART5)
		{
			UART5_CLK_DI();
		}
	}
}



void USART_Init(USART_Handle_t *pUSARTHandle)
{

	USART_ClkControl(pUSARTHandle->pUSARTx, ENABLE);

	/*
	 * CR1 Register Configuration
	 */

	uint32_t tempreg = 0;

	// DISABLE USART
	pUSARTHandle->pUSARTx->CR1 &= ~(USART_CR1_UE);

	//WordLength
	if(pUSARTHandle->USART_Config.USART_WordLength == 0)
		{
			tempreg &= ~(USART_CR1_M1);
			tempreg &= ~(USART_CR1_M0);
		}
	else if(pUSARTHandle->USART_Config.USART_WordLength == 1)
		{
			tempreg &= ~(USART_CR1_M1);
			tempreg |=  (USART_CR1_M0);
		}
	else if(pUSARTHandle->USART_Config.USART_WordLength == 2)
		{
			tempreg |=  (USART_CR1_M1);
			tempreg &= ~(USART_CR1_M0);
		}

	//OverSampling by 16
	tempreg &= ~(USART_CR1_OVER8);

	//Parity control
	if(pUSARTHandle->USART_Config.USART_ParityControl == 0)
		{
			tempreg &= ~(USART_CR1_PCE);
		}
	else if(pUSARTHandle->USART_Config.USART_ParityControl == 1)
		{
			tempreg |=  (USART_CR1_PCE);
			tempreg &= ~(USART_CR1_PS);
		}
	else if(pUSARTHandle->USART_Config.USART_ParityControl == 2)
		{
			tempreg |=  (USART_CR1_PCE);
			tempreg |=  (USART_CR1_PS);
		}

	//TxRx Modes
	if(pUSARTHandle->USART_Config.USART_Mode == 0)
		{
			tempreg &= ~(USART_CR1_TE);
			tempreg |=  (USART_CR1_RE);
		}
	else if(pUSARTHandle->USART_Config.USART_Mode == 1)
		{
			tempreg |=  (USART_CR1_TE);
			tempreg &= ~(USART_CR1_RE);
		}
	else if(pUSARTHandle->USART_Config.USART_Mode == 2)
		{
			tempreg |=  (USART_CR1_TE);
			tempreg |=  (USART_CR1_RE);
		}

	pUSARTHandle->pUSARTx->CR1 = tempreg;


	/*
	 * CR2 Register Configuration
	 */

	tempreg = 0;

	// MSBFIRST, DATAINV, TXINV, RXINV, SWAP, LINEN all in default due to tempreg = 0

	//No of StopBits
	if(pUSARTHandle->USART_Config.USART_StopBits == 0)
		{
			tempreg &=  ~(USART_CR2_STOP1);
			tempreg &=  ~(USART_CR2_STOP0);
		}
	else if(pUSARTHandle->USART_Config.USART_StopBits == 1)
		{
			tempreg &= ~(USART_CR2_STOP1);
			tempreg |=  (USART_CR2_STOP0);
		}
	else if(pUSARTHandle->USART_Config.USART_StopBits == 2)
		{
			tempreg |=   (USART_CR2_STOP1);
			tempreg &=  ~(USART_CR2_STOP0);
		}
	else if(pUSARTHandle->USART_Config.USART_StopBits == 3)
		{
			tempreg |= (USART_CR2_STOP1);
			tempreg |= (USART_CR2_STOP0);
		}

	//CPOL, CPHA, LBCL all in default due to tempreg = 0

	pUSARTHandle->pUSARTx->CR2 = tempreg;


	/*
	 * CR3 Register Configuration
	 */

	tempreg = 0;

	//FlowControl
	if(pUSARTHandle->USART_Config.USART_HWFlowControl)
		{
			tempreg |= (USART_CR3_CTSE);
			tempreg |= (USART_CR3_RTSE);
		}

	pUSARTHandle->pUSARTx->CR3 = tempreg;


	/*
	 * BRR Register Configuration
	 */

	// USART BRR values calculated for 8 MHz peripheral clock
	// Oversampling = 16
	pUSARTHandle->pUSARTx->BRR = pUSARTHandle->USART_Config.USART_Baud;


	// ENABLE USART
	pUSARTHandle->pUSARTx->CR1 |= (USART_CR1_UE);

}



void USART_DeInit(USART_Regs_t *pUSARTx)
{
    if (pI2Cx == USART1)
    {
        USART1_REG_RST();
    }
    else if (pI2Cx == USART2)
    {
       USART2_REG_RST();
    }
    else if (pI2Cx == UART3)
    {
       UART3_REG_RST();
    }
    else if (pI2Cx == UART4)
    {
       UART4_REG_RST();
    }
    else if (pI2Cx == UART5)
    {
       UART5_REG_RST();
    }
}
