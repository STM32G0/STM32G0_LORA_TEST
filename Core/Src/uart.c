/*****************************************
File  : uart.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "uart.h"

/*** For circular RX buffer ***/
volatile char uart_rxBuff[UART_RX_BUF_SIZE];
volatile circ_buffer_t uart_rx_circBuff = { uart_rxBuff, 0, 0 };


void usart1_sendByte(uint8_t byte)
{
	while ((USART1->ISR & USART_ISR_TXE_TXFNF) == 0); // TXFIFO not full
	                USART1->TDR = byte;
}

void usart1_sendString(const char *string)
{
        while (*string) {
                usart1_sendByte(*string++);
        }
}
/*** For send configuration structure ***/
void usart1_sendStructure(const void *structure, uint8_t lengthStructure)
{
        while (lengthStructure--) {

        	usart1_sendByte(*(uint8_t*)structure++);

        }
}
