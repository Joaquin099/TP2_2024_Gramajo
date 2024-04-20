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

// Prototipo de la función de inicialización del sistema
void SystemInit(void);

typedef enum {
	PRENDER = 0,		//ON
	APAGAR,				//OFF
} VALORES;

int main(void) {
	// Inicialización del sistema
	SystemInit();

	// Habilitar el reloj para el puerto GPIOA
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// Habilitar el reloj para el puerto GPIOC (donde está conectado el pulsador B2)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	// Habilitar el reloj para el puerto GPIOB (donde está conectado el pulsador D14)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	// Configurar el pin PA5 como salida
	GPIO_InitTypeDef GPIO_InitStruct_LED;
	GPIO_InitStruct_LED.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct_LED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStruct_LED);

	//Configurar el pin PC13 como entrada (pulsador)
	GPIO_InitTypeDef GPIO_InitStruct_Pulsador;
	GPIO_InitStruct_Pulsador.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct_Pulsador.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct_Pulsador.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct_Pulsador.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStruct_Pulsador);

	//Configurar el pin PB9 como entrada (pulsador)
	GPIO_InitTypeDef GPIO_InitStruct_Pulsador_Externo;
	GPIO_InitStruct_Pulsador_Externo.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct_Pulsador_Externo.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct_Pulsador_Externo.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct_Pulsador_Externo.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStruct_Pulsador_Externo);

	while (1) {
		// Leer el estado del pulsador
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == Bit_RESET || GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == Bit_RESET) {
			// El pulsador está presionado, encender el LED
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
		} else {
			// El pulsador no está presionado, apagar el LED
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		}
	}
}
