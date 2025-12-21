/*
 * stm32f303xx.h
 *
 *  Created on: Nov 4, 2025
 *      Author: aswin
 */

#ifndef INC_STM32F303XX_H_
#define INC_STM32F303XX_H_


#define __vo volatile
#include <stdint.h>


//Some Basic Macros
#define ENABLE						 1
#define DISABLE						 0
#define SET							 ENABLE
#define RESET						 DISABLE




//Base Addresses of various memories
#define FLASH_BASEADDR				0x08000000u
#define SRAM1_BASEADDR				0x20000000u
#define SRAM2_BASEADDR				0x10000000u
#define ROM_BASEADDR				0x1FFFD800u
#define SRAM						SRAM1_BASEADDR


//Base Addresses of various Buses
#define AHB1_BASEADDR				0x40020000u
#define AHB2_BASEADDR				0x48000000u
#define AHB3_BASEADDR				0x50000000u
#define AHB4_BASEADDR				0x60000000u
#define APB1_BASEADDR				0x40000000u
#define APB2_BASEADDR				0x40010000u


//Base Addresses of various peripherals

//GPIO Peripherals
#define GPIOA_BASEADDR				(AHB2_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB2_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB2_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB2_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB2_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB2_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB2_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB2_BASEADDR + 0x1C00)

//RCC Peripherals
#define RCC_BASEADDR				(AHB1_BASEADDR + 0x1000)

//SPIx Peripherals
#define SPI4_BASEADDR				(APB2_BASEADDR + 0x3C00)
#define SPI3_BASEADDR				(APB1_BASEADDR + 0x3C00)
#define SPI2_BASEADDR				(APB1_BASEADDR + 0x3800)
#define SPI1_BASEADDR				(APB2_BASEADDR + 0x3000)

//I2Cx Peripherals
#define I2C3_BASEADDR				(APB1_BASEADDR + 0x7800)
#define I2C2_BASEADDR				(APB1_BASEADDR + 0x5800)
#define I2C1_BASEADDR				(APB1_BASEADDR + 0x5400)

//UART USART Peripherals
#define UART5_BASEADDR				(APB1_BASEADDR + 0x5000)
#define UART4_BASEADDR				(APB1_BASEADDR + 0x4C00)
#define USART3_BASEADDR				(APB1_BASEADDR + 0x4800)
#define USART2_BASEADDR				(APB1_BASEADDR + 0x4400)
#define USART1_BASEADDR				(APB2_BASEADDR + 0x3800)

#define EXTI_BASEADDR				(APB2_BASEADDR + 0x0400)
#define SYSCFG_BASEADDR				(APB2_BASEADDR + 0x0000)



//Structure for RCC Registers
typedef struct{

	__vo uint32_t CR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t CFGR2;
	__vo uint32_t CFGR3;

}RCC_Regs_t;



//Structure for GPIOx registers
typedef struct{

	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
	__vo uint32_t BSR;

} GPIO_Regs_t;



//Structure for SPIx registers
typedef struct{

	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;

} SPI_Regs_t;


//Structure for I2Cx registers
typedef struct{

	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t TIMINGR;
	__vo uint32_t TIMEOUTR;
	__vo uint32_t ISR;
	__vo uint32_t ICR;
	__vo uint32_t PECR;
	__vo uint32_t RXDR;
	__vo uint32_t TXDR;

} I2C_Regs_t;


//Structure for USARTx registers
typedef struct{

	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t CR3;
	__vo uint32_t BRR;
	__vo uint32_t GTPR;
	__vo uint32_t RTOR;
	__vo uint32_t RQR;
	__vo uint32_t ISR;
	__vo uint32_t ICR;
	__vo uint32_t RDR;
	__vo uint32_t TDR;

} USART_Regs_t;


//GPIO Peripheral definitions
#define GPIOA						((GPIO_Regs_t*)GPIOA_BASEADDR)
#define GPIOB						((GPIO_Regs_t*)GPIOB_BASEADDR)
#define GPIOC						((GPIO_Regs_t*)GPIOC_BASEADDR)
#define GPIOD						((GPIO_Regs_t*)GPIOD_BASEADDR)
#define GPIOE						((GPIO_Regs_t*)GPIOE_BASEADDR)
#define GPIOF						((GPIO_Regs_t*)GPIOF_BASEADDR)
#define GPIOG						((GPIO_Regs_t*)GPIOG_BASEADDR)
#define GPIOH						((GPIO_Regs_t*)GPIOH_BASEADDR)


//RCC Peripheral definitions
#define RCC							((RCC_Regs_t*)RCC_BASEADDR)


//SPI Peripheral definitions
#define SPI1						((SPI_Regs_t*)SPI1_BASEADDR)
#define SPI2						((SPI_Regs_t*)SPI2_BASEADDR)
#define SPI3						((SPI_Regs_t*)SPI3_BASEADDR)
#define SPI4						((SPI_Regs_t*)SPI4_BASEADDR)


//I2C Peripheral definitions
#define I2C1						((I2C_Regs_t*)I2C1_BASEADDR)
#define I2C2						((I2C_Regs_t*)I2C2_BASEADDR)
#define I2C3						((I2C_Regs_t*)I2C3_BASEADDR)


//USART Peripheral definitions
#define USART1						((USART_Regs_t*)USART1_BASEADDR)
#define USART2						((USART_Regs_t*)USART2_BASEADDR)
#define USART3						((USART_Regs_t*)USART3_BASEADDR)
#define UART4						((USART_Regs_t*)UART4_BASEADDR)
#define UART5						((USART_Regs_t*)UART5_BASEADDR)

/* USART_CR1 bits */
/* USART_CR1 bits (32-bit) */
#define USART_CR1_UE        (1U << 0)
#define USART_CR1_UESM      (1U << 1)
#define USART_CR1_RE        (1U << 2)
#define USART_CR1_TE        (1U << 3)
#define USART_CR1_IDLEIE    (1U << 4)
#define USART_CR1_RXNEIE    (1U << 5)
#define USART_CR1_TCIE      (1U << 6)
#define USART_CR1_TXEIE     (1U << 7)
#define USART_CR1_PEIE      (1U << 8)
#define USART_CR1_PS        (1U << 9)
#define USART_CR1_PCE       (1U << 10)
#define USART_CR1_WAKE      (1U << 11)
#define USART_CR1_M0        (1U << 12)
#define USART_CR1_MME       (1U << 13)
#define USART_CR1_CMIE      (1U << 14)
#define USART_CR1_OVER8     (1U << 15)
#define USART_CR1_DEDT      (1U << 16)
#define USART_CR1_DEAT      (1U << 21)
#define USART_CR1_RTOIE     (1U << 26)
#define USART_CR1_EOBIE     (1U << 27)
#define USART_CR1_M1        (1U << 28)
/* Bits 29–31: Reserved */


/* USART_CR2 bits */
/* Bits 0–3: Reserved */
#define USART_CR2_ADDM7     (1U << 4)
#define USART_CR2_LBDL      (1U << 5)
#define USART_CR2_LBDIE     (1U << 6)
/* Bit 7: Reserved */
#define USART_CR2_LBCL      (1U << 8)
#define USART_CR2_CPHA      (1U << 9)
#define USART_CR2_CPOL      (1U << 10)
#define USART_CR2_CLKEN     (1U << 11)
#define USART_CR2_STOP0     (1U << 12)
#define USART_CR2_STOP1     (1U << 13)
#define USART_CR2_LINEN     (1U << 14)
#define USART_CR2_SWAP      (1U << 15)
#define USART_CR2_RXINV     (1U << 16)
#define USART_CR2_TXINV     (1U << 17)
#define USART_CR2_DATAINV   (1U << 18)
#define USART_CR2_MSBFIRST  (1U << 19)
#define USART_CR2_ABREN     (1U << 20)
#define USART_CR2_ABRMOD    (1U << 21)
#define USART_CR2_RTOEN     (1U << 23)
#define USART_CR2_ADD       (1U << 24)


/* USART_CR3 bits (32-bit) */
#define USART_CR3_EIE       (1U << 0)
#define USART_CR3_IREN      (1U << 1)
#define USART_CR3_IRLP      (1U << 2)
#define USART_CR3_HDSEL     (1U << 3)
#define USART_CR3_NACK      (1U << 4)
#define USART_CR3_SCEN      (1U << 5)
#define USART_CR3_DMAR      (1U << 6)
#define USART_CR3_DMAT      (1U << 7)
#define USART_CR3_RTSE      (1U << 8)
#define USART_CR3_CTSE      (1U << 9)
#define USART_CR3_CTSIE     (1U << 10)
#define USART_CR3_ONEBIT    (1U << 11)
#define USART_CR3_OVRDIS    (1U << 12)
#define USART_CR3_DDRE      (1U << 13)
#define USART_CR3_DEM       (1U << 14)
#define USART_CR3_DEP       (1U << 15)
/* Bit 16: Reserved */
#define USART_CR3_SCARCNT  (1U << 17)
#define USART_CR3_WUS      (1U << 20)
#define USART_CR3_WUFIE     (1U << 22)
/* Bits 23–31: Reserved */


/* USART_RQR bits */
#define USART_RQR_ABRRQ     (1U << 0)
#define USART_RQR_SBKRQ     (1U << 1)
#define USART_RQR_MMRQ      (1U << 2)
#define USART_RQR_RXFRQ     (1U << 3)
#define USART_RQR_TXFRQ     (1U << 4)


/* USART_ISR bits */
#define USART_ISR_PE        (1U << 0)   /* Parity error */
#define USART_ISR_FE        (1U << 1)   /* Framing error */
#define USART_ISR_NF        (1U << 2)   /* Noise detected flag */
#define USART_ISR_ORE       (1U << 3)   /* Overrun error */
#define USART_ISR_IDLE      (1U << 4)   /* Idle line detected */
#define USART_ISR_RXNE      (1U << 5)   /* Read data register not empty */
#define USART_ISR_TC        (1U << 6)   /* Transmission complete */
#define USART_ISR_TXE       (1U << 7)   /* Transmit data register empty */
#define USART_ISR_LBDF      (1U << 8)   /* LIN break detection flag */
#define USART_ISR_CTSIF     (1U << 9)   /* CTS interrupt flag */
#define USART_ISR_CTS       (1U << 10)  /* CTS flag */
#define USART_ISR_RTOF      (1U << 11)  /* Receiver timeout */
#define USART_ISR_EOBF      (1U << 12)  /* End of block flag */
#define USART_ISR_ABRE      (1U << 14)  /* Auto baud rate error */
#define USART_ISR_ABRF      (1U << 15)  /* Auto baud rate flag */
#define USART_ISR_BUSY      (1U << 16)  /* Busy flag */
#define USART_ISR_CMF       (1U << 17)  /* Character match flag */
#define USART_ISR_SBKF      (1U << 18)  /* Send break flag */
#define USART_ISR_RWU       (1U << 19)  /* Receiver wakeup */
#define USART_ISR_WUF       (1U << 20)  /* Wakeup from Stop mode */
#define USART_ISR_TEACK     (1U << 21)  /* Transmit enable acknowledge */
#define USART_ISR_REACK     (1U << 22)  /* Receive enable acknowledge */

/* USART_ICR bits */
#define USART_ICR_PECF      (1U << 0)   /* Parity error clear */
#define USART_ICR_FECF      (1U << 1)   /* Framing error clear */
#define USART_ICR_NCF       (1U << 2)   /* Noise detected clear */
#define USART_ICR_ORECF     (1U << 3)   /* Overrun error clear */
#define USART_ICR_IDLECF    (1U << 4)   /* Idle line clear */
#define USART_ICR_TCCF      (1U << 6)   /* Transmission complete clear */
#define USART_ICR_LBDCF     (1U << 8)   /* LIN break detection clear */
#define USART_ICR_CTSCF     (1U << 9)   /* CTS clear */
#define USART_ICR_RTOCF     (1U << 11)  /* Receiver timeout clear */
#define USART_ICR_EOBCF     (1U << 12)  /* End of block clear */
#define USART_ICR_CMCF      (1U << 17)  /* Character match clear */
#define USART_ICR_WUCF      (1U << 20)  /* Wakeup from Stop mode clear */


//Clock Enable Macros for GPIOx
#define GPIOA_CLK_EN()				( RCC -> AHBENR |= (1 << 17))
#define GPIOB_CLK_EN()				( RCC -> AHBENR |= (1 << 18))
#define GPIOC_CLK_EN()				( RCC -> AHBENR |= (1 << 19))
#define GPIOD_CLK_EN()				( RCC -> AHBENR |= (1 << 20))
#define GPIOE_CLK_EN()				( RCC -> AHBENR |= (1 << 21))
#define GPIOF_CLK_EN()				( RCC -> AHBENR |= (1 << 22))
#define GPIOG_CLK_EN()				( RCC -> AHBENR |= (1 << 23))
#define GPIOH_CLK_EN()				( RCC -> AHBENR |= (1 << 16))


//Clock Enable Macros for SPI
#define SPI1_CLK_EN()				( RCC -> APB2ENR |= (1 << 12))
#define SPI2_CLK_EN()				( RCC -> APB1ENR |= (1 << 14))
#define SPI3_CLK_EN()				( RCC -> APB1ENR |= (1 << 15))
#define SPI4_CLK_EN()				( RCC -> APB2ENR |= (1 << 15))


//Clock Enable Macros for I2C
#define I2C1_CLK_EN()				(RCC -> APB1ENR |= (1 << 21))
#define I2C2_CLK_EN()				(RCC -> APB1ENR |= (1 << 22))
#define I2C3_CLK_EN()				(RCC -> APB1ENR |= (1 << 30))


//Clock Enable Macros for USART UART
#define USART1_CLK_EN()				(RCC -> APB2ENR |= (1 << 14))
#define USART2_CLK_EN()				(RCC -> APB1ENR |= (1 << 17))
#define USART3_CLK_EN()				(RCC -> APB1ENR |= (1 << 18))
#define UART4_CLK_EN()				(RCC -> APB1ENR |= (1 << 19))
#define UART5_CLK_EN()				(RCC -> APB1ENR |= (1 << 20))


//Clock Enable Macros for SYSCFG & EXTI
#define SYSCFG_CLK_EN()				( RCC -> APB2ENR |= (1 << 0))


//Clock Disable Macros for GPIOx
#define GPIOA_CLK_DI()				( RCC -> AHBENR &= ~(1 << 17))
#define GPIOB_CLK_DI()				( RCC -> AHBENR &= ~(1 << 18))
#define GPIOC_CLK_DI()				( RCC -> AHBENR &= ~(1 << 19))
#define GPIOD_CLK_DI()				( RCC -> AHBENR &= ~(1 << 20))
#define GPIOE_CLK_DI()				( RCC -> AHBENR &= ~(1 << 21))
#define GPIOF_CLK_DI()				( RCC -> AHBENR &= ~(1 << 22))
#define GPIOG_CLK_DI()				( RCC -> AHBENR &= ~(1 << 23))
#define GPIOH_CLK_DI()				( RCC -> AHBENR &= ~(1 << 16))


//Clock Disable Macros for SPI
#define SPI1_CLK_DI()				( RCC -> APB2ENR &= ~(1 << 12))
#define SPI2_CLK_DI()				( RCC -> APB1ENR &= ~(1 << 14))
#define SPI3_CLK_DI()				( RCC -> APB1ENR &= ~(1 << 15))
#define SPI4_CLK_DI()				( RCC -> APB2ENR &= ~(1 << 15))

//Clock Disable Macros for I2C
#define I2C1_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 21))
#define I2C2_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 22))
#define I2C3_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 30))


//Clock Disable Macros for USART UART
#define USART1_CLK_DI()				(RCC -> APB2ENR &= ~(1 << 14))
#define USART2_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 17))
#define USART3_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 18))
#define UART4_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 19))
#define UART5_CLK_DI()				(RCC -> APB1ENR &= ~(1 << 20))


//Clock Disable Macros for SYSCFG & EXTI
#define SYSCFG_CLK_DI()				( RCC -> APB2ENR &= ~(1 << 0))


//Gpio Reset Macro
#define GPIOA_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 17));  ( RCC -> AHBRSTR &= ~(1 << 17));} while(0)
#define GPIOB_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 18));  ( RCC -> AHBRSTR &= ~(1 << 18));} while(0)
#define GPIOC_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 19));  ( RCC -> AHBRSTR &= ~(1 << 19));} while(0)
#define GPIOD_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 20));  ( RCC -> AHBRSTR &= ~(1 << 20));} while(0)
#define GPIOE_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 21));  ( RCC -> AHBRSTR &= ~(1 << 21));} while(0)
#define GPIOF_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 22));  ( RCC -> AHBRSTR &= ~(1 << 22));} while(0)
#define GPIOG_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 23));  ( RCC -> AHBRSTR &= ~(1 << 23));} while(0)
#define GPIOH_REG_RST()				do {( RCC -> AHBRSTR |= (1 << 16));  ( RCC -> AHBRSTR &= ~(1 << 16));} while(0)


//I2C Reset Macro
#define I2C1_REG_RST()				do {( RCC -> APB1RSTR |= (1 << 21));  ( RCC -> APB1RSTR &= ~(1 << 21));} while(0)
#define I2C2_REG_RST()				do {( RCC -> APB1RSTR |= (1 << 22));  ( RCC -> APB1RSTR &= ~(1 << 22));} while(0)
#define I2C3_REG_RST()				do {( RCC -> APB1RSTR |= (1 << 30));  ( RCC -> APB1RSTR &= ~(1 << 30));} while(0)


//USART Reset Macro
#define USART1_REG_RST()			do {( RCC -> APB2RSTR |= (1 << 14));  ( RCC -> APB2RSTR &= ~(1 << 14));} while(0)
#define USART2_REG_RST()			do {( RCC -> APB1RSTR |= (1 << 17));  ( RCC -> APB1RSTR &= ~(1 << 17));} while(0)
#define USART3_REG_RST()			do {( RCC -> APB1RSTR |= (1 << 18));  ( RCC -> APB1RSTR &= ~(1 << 18));} while(0)
#define UART4_REG_RST()				do {( RCC -> APB1RSTR |= (1 << 19));  ( RCC -> APB1RSTR &= ~(1 << 19));} while(0)
#define UART5_REG_RST()				do {( RCC -> APB1RSTR |= (1 << 20));  ( RCC -> APB1RSTR &= ~(1 << 20));} while(0)


#include "stm32f303xx_gpio_driver.h"
#include "stm32f303xx_spi_driver.h"
#include "stm32f303xx_i2c_driver.h"
#include "stm32f303xx_usart_driver.h"

#endif /* INC_STM32F303XX_H_ */
