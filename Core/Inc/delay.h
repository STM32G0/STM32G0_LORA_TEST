/*****************************************
File  : delay.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

extern volatile uint16_t ms_counter;
void delay_ms(uint16_t ms);

#endif /* INC_DELAY_H_ */
