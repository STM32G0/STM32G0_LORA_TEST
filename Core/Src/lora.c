/*****************************************
File  : lora.c
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#include <stm32g071xx.h>
#include "pin_config.h"
#include "uart.h"
#include "delay.h"
#include "lora.h"

/*** Initialize structure Lora register configuration ***/
 loraRegister_t configurationLoraRegister = {
	/*** Set Adress ***/
	.ADDH = 0xFF ,
	.ADDL = 0xFF ,
	/*** Set REG0 ***/
	.REG0.airRate = AIR_RATE_9600 ,
	.REG0.uartParityBit = _8N1 ,
	.REG0.uartRate = UART_RATE_9600 ,
	/*** Set REG1 ***/
	.REG1.transmitPower = POWER_10dBm ,
	.REG1.subPacketLenght = LENGHT_200_BYTE ,
	.REG1.rssiAmbietNoiseSet = RSSI_NOISE_DISABLE ,
	/*** Set REG2 ***/
	.REG2 = 0x00 , // Lora channel number (0-83)
	/*** Set REG3 ***/
	.REG3.lbtSet = LBT_DISABLE ,
	.REG3.rssiSet = RSSI_DISABLE ,
	.REG3.transmitMethod = FIXED_MODE ,
	.REG3.worCycle = WOR_500ms ,
	/*** Set CRYPTO Register ***/
	.CRYPT_H = 0x00 ,
	.CRYPT_L = 0x00 ,
};



void SetMode(uint8_t mode){
	while(AUX_Test() == 0);
	delay_ms(2);
	switch(mode)
	{
					case MODE_0_NORMAL:
						M0_SetLow();
						M1_SetLow();
						break;
					case MODE_1_WOR_Transmiter:
						M0_SetHigh();
						M1_SetLow();
						break;
					case MODE_2_WOR_Receiver:
						M0_SetLow();
						M1_SetHigh();
						break;
					case MODE_3_SLEEP_CONFIG:
						M0_SetHigh();
						M1_SetHigh();
						break;
	}
	delay_ms(1);
	while(AUX_Test() == 0);
}


void LoraModuleInit(void) {

//	SetMode(MODE_3_SLEEP_CONFIG);
	/*** Send frame to module Lora register ***/
	usart1_sendByte(Write_Register);
	usart1_sendByte(REG_ADDRESS_ADDH); //start register adress
	usart1_sendByte(sizeof(configurationLoraRegister));
	usart1_sendStructure(&configurationLoraRegister, sizeof(configurationLoraRegister));

}



