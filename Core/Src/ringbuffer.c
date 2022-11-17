/*****************************************
File  : ringbuffer.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include "ringbuffer.h"
#include <string.h>

/*** For circular RX buffer ***/
volatile char uart_rxBuff[UART_RX_BUF_SIZE];
char parseBuff[PARSE_BUF_SIZE] ;
volatile uint8_t endLine = 0 ; //counts CR characters (Enter) /r
volatile ringBuffer_t uart_rx_ringBuff = { uart_rxBuff, 0, 0 };

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

uint8_t uartRxStringEvent(void){

	if(strcmp(ringBufferGetString(parseBuff) , "messageToSendLora") == 0) return 1 ;
	else return 0 ;

	}


