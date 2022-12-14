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
#define UART_RX_BUF_SIZE  96 // RX Ring Buffer size
#define UART_TX_BUF_SIZE  96 // RX Ring Buffer size

#define PARSE_BUF_SIZE  32   // parsing incoming messages Buffer size

#define ASCII_CR 13
#define ASCII_NUL 0
#define ASCII_LF 10


typedef struct {
volatile char * const buffer;
uint8_t head;
uint8_t tail;
} ringBuffer_t;


volatile extern  ringBuffer_t uart_rx_ringBuff ;
volatile extern  ringBuffer_t uart_tx_ringBuff ;

volatile extern uint8_t endLine ; // character counter enter

int8_t ringBufferGetChar(void);
char* ringBufferGetString(char *buf);

int8_t ringBufferPutChar(char data);
void ringBufferPutString(char *s);

uint8_t uartRxStringEvent(void) ;



#endif /* INC_RINGBUFFER_H_ */
