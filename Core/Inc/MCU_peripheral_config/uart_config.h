/*****************************************
File  : uart_config.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define UART_SPEED 9600

void UART1_MANAGER_Initialize(void);
void UART1_DMA_MANAGER_Initialize(void);

#endif /*UART_CONFIG_H*/
