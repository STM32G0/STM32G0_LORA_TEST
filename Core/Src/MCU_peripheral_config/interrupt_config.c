/*****************************************
File  : interrupt_config.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/

#include <stm32g071xx.h>
#include "interrupt_config.h"

void INTERRUPT_MANAGER_Initialize(void){
/* UART1 interrupt init*/
 NVIC_SetPriority(USART1_IRQn, 2);
 NVIC_EnableIRQ(USART1_IRQn);
 
 NVIC_SetPriority(DMA1_Channel1_IRQn, 1);
 NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}
