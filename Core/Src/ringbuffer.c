/*****************************************
File  : ringbuffer.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include "ringbuffer.h"

/*** For circular RX buffer ***/
volatile char uart_rxBuff[UART_RX_BUF_SIZE];
volatile uint8_t endLine = 0 ; //zlicza znaki CR (Enter) /n
volatile ringBuffer_t uart_rx_ringBuff = { uart_rxBuff, 0, 0 };

int8_t ringBufferGetChar(void){
	if(uart_rx_ringBuff.head == uart_rx_ringBuff.tail) return -1 ; //bufor pełny zwracamy -1, wykorzystujemy to w funkcji pobierajacej stringa
	uart_rx_ringBuff.tail = (uart_rx_ringBuff.head + 1) % UART_RX_BUF_SIZE; //obliczamy nowy indeks dla tail ("ogon")
	return uart_rxBuff[uart_rx_ringBuff.tail] ; //zwracamy bajt pobrany z ringBuffer
}

char* ringBufferGetString(char *buf){
	char znak ;
	char *wsk = buf ;

	if(endLine){ // czy w buforze jest znak konca linii - CR (Enter) \n ?
		while((znak = ringBufferGetChar())) {
			if(ASCII_CR == znak || znak < 0) break ;
		*buf++ = znak ;
	}
	*buf = 0;  // zamiana znaku CR (Enter) na 0
	endLine-- ;
}

	return wsk ;
}
