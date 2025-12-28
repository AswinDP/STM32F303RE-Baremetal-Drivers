/*
 * stm32f303xx_exti_driver.c
 *
 *  Created on: Dec 28, 2025
 *      Author: aswin
 */


#include "stm32f303xx.h"

/* ================= EXTI Line Configuration ================= */

/* Configure GPIO port for EXTI line (EXTI0–EXTI15) */
void EXTI_ConfigGPIO(uint8_t exti_line, uint8_t gpio_port)
{

}

/* Configure trigger type: rising, falling, or both */
void EXTI_ConfigTrigger(uint8_t exti_line, uint8_t trigger)
{

}


/* ================= Interrupt Control ================= */

/* Enable interrupt generation for EXTI line */
void EXTI_EnableInterrupt(uint8_t exti_line)
{

}

/* Disable interrupt generation for EXTI line */
void EXTI_DisableInterrupt(uint8_t exti_line)
{

}


/* ================= Event Control (Optional) ================= */

/* Enable event generation for EXTI line */
void EXTI_EnableEvent(uint8_t exti_line)
{

}

/* Disable event generation for EXTI line */
void EXTI_DisableEvent(uint8_t exti_line)
{

}


/* ================= Pending Flag Handling ================= */

/* Clear EXTI pending flag (write 1 to clear) */
void EXTI_ClearPending(uint8_t exti_line)
{

}

/* Get EXTI pending status (returns 0 or 1) */
uint8_t EXTI_GetPending(uint8_t exti_line)
{

}


/* ================= Software Trigger ================= */

/* Generate EXTI interrupt/event by software */
void EXTI_GenerateSWInterrupt(uint8_t exti_line)
{

}


/* ================= IRQ Handling Support ================= */

/* Generic EXTI IRQ handler helper (used inside ISR) */
void EXTI_HandleIRQ(uint8_t exti_line)
{

}

/* Weak user callback called from EXTI_HandleIRQ */
void EXTI_Callback(uint8_t exti_line)
{

}

















