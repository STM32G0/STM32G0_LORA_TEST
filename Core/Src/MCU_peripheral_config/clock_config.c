/*****************************************
File  : clock_config.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "clock_config.h"

void CLOCK_MANAGER_Initialize(void){

RCC->IOPENR |= RCC_IOPENR_GPIOAEN; 		//Open clock for GPIOA
RCC->IOPENR |= RCC_IOPENR_GPIOBEN; 		//Open clock for GPIOB
RCC->IOPENR |= RCC_IOPENR_GPIOCEN; 		//Open clock for GPIOC
RCC->APBENR2 |= RCC_APBENR2_USART1EN; 	//Open clock for UART1

}
