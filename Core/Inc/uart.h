/*****************************************
File  : uart.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#ifndef INC_UART_H_
#define INC_UART_H_

/*** For circular buffer ***/
#define UART_RX_BUF_SIZE  96

typedef struct {
volatile char * const buffer;
uint8_t head;
uint8_t tail;
} circ_buffer_t;

/*** circular RX buffer ***/
volatile extern  circ_buffer_t uart_rx_circBuff ;
volatile extern uint8_t asciiLine ;
char* uart_get_str(char *buf) ;

void usart1_sendByte(uint8_t byte);
void usart1_sendString(const char *string);
void usart1_sendStructure(const void *structure, uint8_t lengthStructure);

#endif /* INC_UART_H_ */
