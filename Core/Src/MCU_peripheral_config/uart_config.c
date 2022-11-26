/*****************************************
File  : uart_config.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "uart_config.h"


void UART1_MANAGER_Initialize(void){
	/*  Uwaga : jeśli używasz bufora kołowego do nadawania po UART
	 *  nie włączaj tutaj przerwania TX.
	*/

	USART1->CR1 &= ~USART_CR1_UE ; // Disable UART1

	asm("nop");
	asm("nop");
	asm("nop");

	USART1->BRR = SystemCoreClock / UART_SPEED; // set baud rate - 16MHz / 9600
	USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_FIFOEN | USART_CR1_RXNEIE_RXFNEIE; // Enable TX / RX  / FIFO / Interrupt RX

	asm("nop");
	asm("nop");
	asm("nop");

	USART1->ICR |= ~USART_ICR_TCCF; // clear TC flag
	USART1->CR1 |= USART_CR1_UE ; // Enable UART1

	asm("nop");
	asm("nop");
	asm("nop");
}


/* Alternate Initialize if use DMA */
void UART1_DMA_MANAGER_Initialize(void){

	USART1->CR1 &= ~USART_CR1_UE ; // Disable UART1

	asm("nop");
	asm("nop");
	asm("nop");

	USART1->BRR = SystemCoreClock / UART_SPEED; // set baud rate - 16MHz / 9600

	USART1->CR3 |= USART_CR3_DMAR | USART_CR3_DMAT ; //Enable DMA for TX and RX
	USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_FIFOEN | USART_CR1_RXNEIE_RXFNEIE | USART_CR1_TCIE; // Enable TX / RX  / FIFO / Transmission complete interrupt enable

	asm("nop");
	asm("nop");
	asm("nop");

	USART1->ICR |= ~USART_ICR_TCCF; // Transmission complete clear flag
	USART1->CR1 |= USART_CR1_UE ; // Enable UART1

	asm("nop");
	asm("nop");
	asm("nop");
}

