/*****************************************
File  : pin_config.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

void PIN_MANAGER_Initialize(void);
/* definitions for led on PA2 on MikroBUS board */
#define LED2_SetHigh()           (GPIOA->BSRR |= GPIO_BSRR_BS2)
#define LED2_SetLow()            (GPIOA->BSRR |= GPIO_BSRR_BR2)
#define LED2_Toggle()            ((GPIOA->ODR & GPIO_ODR_OD2)  ? (GPIOA->BSRR |= GPIO_BSRR_BR2) : (GPIOA->BSRR |= GPIO_BSRR_BS2))

/* definitions for led on PA6 on MikroBUS board */
#define LED1_SetHigh()           (GPIOA->BSRR |= GPIO_BSRR_BS6)
#define LED1_SetLow()            (GPIOA->BSRR |= GPIO_BSRR_BR6)
#define LED1_Toggle()            ((GPIOA->ODR & GPIO_ODR_OD6)  ? (GPIOA->BSRR |= GPIO_BSRR_BR6) : (GPIOA->BSRR |= GPIO_BSRR_BS6))

/* definitions for led on MCU Board PA8 */
#define LED_SetHigh()           (GPIOA->BSRR |= GPIO_BSRR_BS8)
#define LED_SetLow()            (GPIOA->BSRR |= GPIO_BSRR_BR8)
#define LED_Toggle()            ((GPIOA->ODR & GPIO_ODR_OD8)  ? (GPIOA->BSRR |= GPIO_BSRR_BR8) : (GPIOA->BSRR |= GPIO_BSRR_BS8))

/* definitions for M0 (LORA) on PA9 */
#define M0_SetHigh()            (GPIOA->BSRR |= GPIO_BSRR_BS9)
#define M0_SetLow()             (GPIOA->BSRR |= GPIO_BSRR_BR9)

/* definitions for M1 (LORA) on PB9 */
#define M1_SetHigh()            (GPIOB->BSRR |= GPIO_BSRR_BS9)
#define M1_SetLow()             (GPIOB->BSRR |= GPIO_BSRR_BR9)

/* definitions for AUX (LORA) on PB8 */
#define AUX_Test()				(GPIOB->IDR & GPIO_IDR_ID8)

#endif /*PIN_CONFIG_H*/
