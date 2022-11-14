/*****************************************
File  : ringbuffer.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stdint.h>

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_

/*** For circular buffer ***/
#define UART_RX_BUF_SIZE  96
#define ASCII_CR 13
#define ASCII_NUL 0
#define ASCII_LF 10


typedef struct {
volatile char * const buffer;
uint8_t head;
uint8_t tail;
} ringBuffer_t;

typedef struct {
	uint8_t ringBuffer_OK ;
	uint8_t ringBuffer_ERROR ;
} ringBufferStatus_t ;


volatile extern  ringBuffer_t uart_rx_ringBuff ;
volatile extern uint8_t endLine ;
int8_t ringBufferGetChar(void);
char* ringBufferGetString(char *buf);

#endif /* INC_RINGBUFFER_H_ */
