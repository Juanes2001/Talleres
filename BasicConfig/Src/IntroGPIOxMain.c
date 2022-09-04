/*
 * IntroGPIOxMain.c
 *
 *  Created on: Aug 27, 2022
 *      Author: JUAN ESTEBAN
 */


#include <stdint.h>

#include "stm32f411xx_hal.h"
#include "GPIOxDriver.h"
uint32_t contador1=0, contador2=0;



/*Funcion principal del programa. Es aca donde se ejecuta todo
 */

int main(void){

	//Definimos el handler para el PIN que deseamos configurar
	GPIO_Handler_t handlerUserLedPin ={0};

	//Deseamos trabajar con el puerto GPIOA
	handlerUserLedPin.pGPIOx = GPIOA;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinNumber = PIN_5;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDR_PULLUP;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEEDR_MEDIUM;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinAltFunMode = AF0; //Ninguna función

	//Cargamos la configuracion del PIN especifico
	GPIO_Config(&handlerUserLedPin);

	//Hacemos que el PIN_A5 quede encendido
	while(1){

		GPIO_WritePin (&handlerUserLedPin, SET);

		for (contador1=0 ;contador1<6000000;contador1++) {
			NOP();
		}
		GPIO_WritePin (&handlerUserLedPin, RESET);
		for (contador1=0; contador1<6000000;contador2++){
			NOP();
		}

		NOP();
	}


	//Este es el ciclo principal, donde se ejecuta todo el programa
}

