/*****************************************
File  : uart_config.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "uart_config.h"


void UART1_MANAGER_Initialize(void){

	USART1->CR1 &= ~USART_CR1_UE ; // Disable UART1

	asm("nop");
	asm("nop");
	asm("nop");

	USART1->BRR = SystemCoreClock / UART_SPEED; // set baud rate - 16MHz / 9600
	USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_FIFOEN | USART_CR1_RXNEIE_RXFNEIE; // Enable TX / RX  / FIFO / Interrupt RX

	asm("nop");
	asm("nop");
	asm("nop");

	USART1->CR1 |= USART_CR1_UE ; // Enable UART1

	asm("nop");
	asm("nop");
	asm("nop");
}
