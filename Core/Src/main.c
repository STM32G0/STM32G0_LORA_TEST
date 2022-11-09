/*****************************************
File  : main.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32Cube IDE
REV   : x.x
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32g071xx.h>
#include <stdbool.h>
#include "system_config.h"
#include "uart.h"
#include "delay.h"
#include "lora.h"

volatile uint16_t ms_timer1 = 100 ;

int main (void){
	SystemInit();
	SystemCoreClockUpdate();
	SYSTEM_MANAGER_Initialize(); // my hardware initialization
	SysTick_Config((SystemCoreClock/1000)-1); // Systick 1 ms

	delay_ms(40); // must be a delay for first init LORA
	LoraModuleInit();
	SetMode(MODE_0_NORMAL);

	while(1){

			if(!ms_timer1){
				if(AUX_Test() != 0){
					usart1_sendByte(0xFF); // target adress High Byte
					usart1_sendByte(0xFF); // target adress LOW Byte
					usart1_sendByte(0x00); // target channel number
					usart1_sendString("messageToSendLora");// send message to other module Lora
				};

				LED2_Toggle()  ;
			//	LED1_Toggle()  ;
				ms_timer1 = 200; //for 200 ms
			}


		}
	}


void SysTick_Handler(void){
	uint16_t n;

	/*** milisecond Counter ***/
	 n = ms_counter ;
	 if(n) ms_counter = --n;
	/*** milisecond Timer1 ***/
	 n = ms_timer1;
	 if (n) ms_timer1 = --n;

	 }






//void USART1_IRQHandler(void){
//uint8_t rxData = 0x00 ;
	/*** Odbiór danych ***/
//	if (USART1->ISR & USART_ISR_RXNE_RXFNE){// RX register not empty ?
//		rxData = (uint8_t)(USART1->RDR);// odczyt rejestru RDR kasuje flagę RXFNE
//	}
	/*** Transmisja danych ***/
	//if (USART1->ISR & USART_ISR_TC){// TX register empty ?
		//	USART1->ICR |= USART_ICR_TCCF;//  kasuje flagę TC
			//LED_Toggle();

		//}
//}
