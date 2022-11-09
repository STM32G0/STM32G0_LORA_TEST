/*****************************************
File  : delay.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stdint.h>
#include "delay.h"

volatile uint16_t ms_counter = 0;

void delay_ms(uint16_t ms)
{
        ms_counter = ms;
        while (ms_counter != 0) ;

}
