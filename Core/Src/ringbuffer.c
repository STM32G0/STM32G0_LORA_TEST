/*****************************************
File  : ringbuffer.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "ringbuffer.h"
#include <string.h>

/*** For circular RX buffer ***/
volatile char uart_rxBuff[UART_RX_BUF_SIZE];
volatile char uart_txBuff[UART_TX_BUF_SIZE];

char parseBuff[PARSE_BUF_SIZE] ;

volatile uint8_t endLine = 0 ; //counts CR characters (Enter) /r

volatile ringBuffer_t uart_rx_ringBuff = { uart_rxBuff, 0, 0 };
volatile ringBuffer_t uart_tx_ringBuff = { uart_txBuff, 0, 0 };

int8_t ringBufferGetChar(void){
	if(uart_rx_ringBuff.head == uart_rx_ringBuff.tail) return -1 ; //buffer full return -1, use this in the function that retrieves the string
	uart_rx_ringBuff.tail = (uart_rx_ringBuff.tail + 1) % UART_RX_BUF_SIZE; //calculate a new index for tail
	return uart_rxBuff[uart_rx_ringBuff.tail] ; //return the byte retrieved from the ringBuffer
}

char* ringBufferGetString(char *buf){
	char znak ;
	char *wsk = buf ;

	if(endLine){ // end-of-line character in the buffer - CR (Enter) \r ?
		while((znak = ringBufferGetChar())) {
			if(ASCII_CR == znak || znak < 0) break ; // znak < 0 , see function ringBufferGetChar()
		*buf++ = znak ;
	}
	*buf = 0;  // conversion of CR (Enter) character to 0
	endLine-- ;
}

	 return wsk ;
}


int8_t ringBufferPutChar(char data){

		uint8_t head_temp = (uart_tx_ringBuff.head + 1)  % UART_RX_BUF_SIZE ; //calculate a new index for head

		if ( head_temp == uart_tx_ringBuff.tail )
			return -1;

		uart_tx_ringBuff.buffer[head_temp] = data;
		uart_tx_ringBuff.head = head_temp;

		USART1->CR1 |=  USART_CR1_TXEIE_TXFNFIE ; // Enable Interrupt TX

		return 0;

	}

void ringBufferPutString(char *s){

		while(*s)
			ringBufferPutChar(*s++);
	}


uint8_t uartRxStringEvent(void){

	if(strcmp(ringBufferGetString(parseBuff) , "messageToSendLora") == 0) return 1 ;
	else return 0 ;

	}


