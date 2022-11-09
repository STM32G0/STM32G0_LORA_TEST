/*****************************************
File  : clock_config.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "pin_config.h"

void PIN_MANAGER_Initialize(void){
/*** set OUT fuction mode (0b01)***/
/*  PA2 set Out for LED2 LORA module*/
GPIOA->MODER &= ~GPIO_MODER_MODE2_1;
/* PA6 set Out for LED1 LORA module */
GPIOA->MODER &= ~GPIO_MODER_MODE6_1;
/* PA9 set Out for M0 LORA module */
GPIOA->MODER &= ~GPIO_MODER_MODE9_1;
/* PB9 set Out for M1 LORA module */
GPIOB->MODER &= ~GPIO_MODER_MODE9_1;
/* PA8 set Out for LED MCU Board */
GPIOA->MODER &= ~GPIO_MODER_MODE8_1;
/* set M0 - PA9 and M1 - PB9 to HIGH - for MODE 3 LORA*/
GPIOA->BSRR |= GPIO_BSRR_BS9 ;
GPIOB->BSRR |= GPIO_BSRR_BS9 ;
/*** set INPUT fuction mode (0b00)***/
/* PB8 set INPUT for AUX LORA module */
GPIOB->MODER &= ~(GPIO_MODER_MODE8_0 | GPIO_MODER_MODE8_1);
/* set Pull-Up for PB8 (0b01) */
GPIOB->PUPDR |= GPIO_PUPDR_PUPD8_0 ;
GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD8_1;

/*** set Alternate fuction mode (0b10) ***/
/* PB6 for TX UART1*/
GPIOB->MODER |= GPIO_MODER_MODE6_1 ;
GPIOB->MODER &= ~(GPIO_MODER_MODE6_0);
/*PA10 for RX UART1*/
GPIOA->MODER |= GPIO_MODER_MODE10_1 ;
GPIOA->MODER &= ~(GPIO_MODER_MODE10_0);

/*** set for UART1 ***/
/* for PB6 (0b0000) */
GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL6) ; // clear
/* for PA10  (0b0001) */
GPIOA->AFR[1] &= ~(GPIO_AFRH_AFSEL10) ; // clear
GPIOA->AFR[1] |= GPIO_AFRH_AFSEL10_0 ; //set

}

