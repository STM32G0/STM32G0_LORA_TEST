/*****************************************
File  : system_config.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : SEGGER Embedded Studio
******************************************/
#include <stm32g071xx.h>
#include "clock_config.h"
#include "pin_config.h"
#include "system_config.h"
#include "interrupt_config.h"
#include "uart_config.h"


void SYSTEM_MANAGER_Initialize(void){

CLOCK_MANAGER_Initialize();
PIN_MANAGER_Initialize();
UART1_MANAGER_Initialize();
INTERRUPT_MANAGER_Initialize();

}
