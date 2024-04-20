/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

// Prototipo de la funci�n de inicializaci�n del sistema
void SystemInit(void);

void delay_ms(uint32_t ms){
	for(uint32_t i = 0; i < ms * 15000; i++){

	}
}


typedef enum {
	ENCENDIDO_25 = 0,		//Prende 25 ms
	APAGADO_25,				//Apaga 25 ms
	ENCENDIDO_40,			//Prende 40 ms
	APAGADO_40,				//Apaga 40 ms
	ENCENDIDO_110,			//Prende 110 ms
	APAGADO_110,			//Apaga 110 ms
} VALORES;

int main(void) {
	// Inicializaci�n del sistema
	SystemInit();

	// Habilitar el reloj para el puerto GPIOA
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// Configurar el pin PA5 como salida
	GPIO_InitTypeDef GPIO_InitStruct_LED;
	GPIO_InitStruct_LED.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct_LED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA, &GPIO_InitStruct_LED);

	VALORES VALOR = ENCENDIDO_25;

	while (1) {
		switch(VALOR){
		case ENCENDIDO_25:
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			VALOR = APAGADO_25;
			delay_ms(20);
			break;

		case APAGADO_25:
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			VALOR = ENCENDIDO_40;
			delay_ms(20);
			break;

		case ENCENDIDO_40:
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			VALOR = APAGADO_40;
			delay_ms(40);
			break;

		case APAGADO_40:
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			VALOR = ENCENDIDO_110;
			delay_ms(40);
			break;

		case ENCENDIDO_110:
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			VALOR = APAGADO_110;
			delay_ms(110);
			break;

		case APAGADO_110:
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			VALOR = ENCENDIDO_25;
			delay_ms(110);
			break;
		}
	}
}
