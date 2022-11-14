/*****************************************
File  : uart.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#ifndef INC_UART_H_
#define INC_UART_H_


void usart1_sendByte(uint8_t byte);
void usart1_sendString(const char *string);
void usart1_sendStructure(const void *structure, uint8_t lengthStructure);

#endif /* INC_UART_H_ */
