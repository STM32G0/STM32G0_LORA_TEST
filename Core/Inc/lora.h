/*****************************************
File  : lora.h
Autor : strefapic.blogspot.com
MCU   : STM32G071KBT6
IDE   : STM32CUBE IDE
******************************************/

#ifndef INC_LORA_H_
#define INC_LORA_H_

/*** COMMAND ***/
#define Write_Register 			0xC0
#define Read_Register			0xC1

/***  MODE ***/
#define	MODE_0_NORMAL 			 0
#define	MODE_1_WOR_Transmiter 	 1
#define MODE_2_WOR_Receiver 	 2
#define	MODE_3_SLEEP_CONFIG 	 3

/*** REGISTER_ADDRESS ***/
#define	REG_ADDRESS_ADDH		 0x00
#define	REG_ADDRESS_ADDL 		 0x01
#define	REG_ADDRESS_REG0	 	 0x02
#define	REG_ADDRESS_REG1	 	 0x03
#define	REG_ADDRESS_REG2	 	 0x04
#define	REG_ADDRESS_REG3	 	 0x05
#define	REG_ADDRESS_CRYPTH	 	 0x06
#define	REG_ADDRESS_CRYPTL	 	 0x07

void SetMode(uint8_t mode);
void LoraModuleInit(void);


typedef enum {UART_RATE_1200, UART_RATE_2400, UART_RATE_4800, UART_RATE_9600, UART_RATE_19200,
	UART_RATE_38400, UART_RATE_57600, UART_RATE_115200} uartRate_t ;

typedef enum {_8N1, _8O1, _8E1} uartParityBit_t;

typedef enum {AIR_RATE_2400 = 2, AIR_RATE_4800, AIR_RATE_9600, AIR_RATE_19200, AIR_RATE_38400, AIR_RATE_62500} airRate_t ;

typedef enum {LENGHT_200_BYTE, LENGHT_128_BYTE, LENGHT_64_BYTE, LENGHT_32_BYTE } subPacketLenght_t ;

typedef enum {RSSI_NOISE_DISABLE, RSSI__NOISE_ENABLE} rssiAmbietNoiseSet_t ;

typedef enum {POWER_22dBm, POWER_17dBm, POWER_13dBm, POWER_10dBm } transmitPower_t ;

typedef enum {RSSI_DISABLE, RSSI_ENABLE}  rssiSet_t;

typedef enum {TRANSPARENT_MODE, FIXED_MODE} transmitMethod_t  ;

typedef enum {LBT_DISABLE, LBT_ENABLE}  lbtSet_t;

typedef enum {WOR_500ms, WOR_1000ms, WOR_1500ms, WOR_2000ms, WOR_2500ms, WOR_3000ms, WOR_3500ms, WOR_4000ms} worCycle_t;






typedef union {

	uint8_t byteConfig ;
	struct{
		airRate_t airRate : 3 ;
		uartParityBit_t uartParityBit : 2 ;
		uartRate_t uartRate : 3 ;
	};
} reg0_t;

typedef union {

	uint8_t byteConfig ;
	struct{
		transmitPower_t transmitPower : 2 ;
		uint8_t  : 3 ;
		rssiAmbietNoiseSet_t rssiAmbietNoiseSet : 1 ;
		subPacketLenght_t subPacketLenght : 2 ;
	};
} reg1_t;

typedef union {

	uint8_t byteConfig ;
	struct{
		worCycle_t worCycle : 3 ;
		uint8_t  : 1 ;
		lbtSet_t lbtSet : 1 ;
		uint8_t  : 1 ;
		transmitMethod_t transmitMethod : 1 ;
		rssiSet_t rssiSet : 1 ;
	};
} reg3_t;


 typedef struct {
	uint8_t ADDH ;
	uint8_t ADDL ;
	reg0_t 	REG0 ;
	reg1_t 	REG1 ;
	uint8_t REG2 ;
	reg3_t 	REG3 ;
	uint8_t CRYPT_H ;
	uint8_t CRYPT_L ;

	} loraRegister_t ;

	typedef struct {
		uint8_t ID ;
		uint8_t temperatura ;
		uint8_t czas ;

		} loraSend_t ;

extern  loraRegister_t configurationLoraRegister ;
extern 	loraSend_t messageToSendLora ;

#endif /* INC_LORA_H_ */
