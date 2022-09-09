/*
 * main.c
 *
 *  Created on: 4 sep. 2022
 *      Author: JUAN ESTEBAN
 */


#include <stdint.h>


#define SUMA '+'
#define RESTA '-'
#define MULTIPLICACION '*'
#define DIVISION '/'

#include <GPIOxDriver.h>

//Funcion ejemplo del switch Case

uint16_t resultadoDeOperacion (uint8_t tipoDeOperacion, uint8_t numeroA, uint8_t numero8);
void delay(uint64_t retardo);

int main(void){

	uint16_t operacionFinal = 0;
	operacionFinal =resultadoDeOperacion(SUMA, 16,12);

	//Ejemplo basico del while

//	uint8_t contador =0
//
//	while(contador <10){
//
//		contador+=3;
//
//	}

	//Actividad #1:

	//Crear una funcion llamada delay, que tome un parametro
	//y que no retorne nada

	//El parametro que debe recibir tiene que mantener ocupado
	//al MCU haciendo nada NOP()
	delay(1000000);

	GPIO_Handler_t handlerstateLED={0};

	handlerstateLED.pGPIOx =GPIOA;
	handlerstateLED.GPIO_PinConfig.GPIO_PinNumber= PIN_5;
	handlerstateLED.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
	handlerstateLED.GPIO_PinConfig.GPIO_PinOPType=GPIO_OTYPE_PUSHPULL;
	handlerstateLED.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PUPDR_NOTHING;
	handlerstateLED.GPIO_PinConfig.GPIO_PinSpeed=GPIO_OSPEEDR_HIGH;

	GPIO_Config(&handlerstateLED);

	while(1){

		GPIO_WritePin(&handlerstateLED, SET);
		delay(150000);
		GPIO_WritePin(&handlerstateLED, RESET);
		delay(70000);

	}


}


uint16_t resultadoDeOperacion (uint8_t tipoDeOperacion, uint8_t numeroA, uint8_t numeroB){
	uint16_t resultado = 0;

	switch( tipoDeOperacion){

	case SUMA:
	{
		resultado = numeroA+numeroB;
		return resultado;
		//LO MAS IMPORTANTE
		break;
	}
	case RESTA:
	{
		resultado = numeroA-numeroB;
		return resultado;
		//LO MAS IMPORTANTE
		break;
	}

	case MULTIPLICACION:
	{
		resultado = numeroA*numeroB;
		return resultado;
		//LO MAS IMPORTANTE
		break;
	}
	case DIVISION:
	{
		resultado = numeroA/numeroB;
		return resultado;
		//LO MAS IMPORTANTE
		break;
	}
	default:
	{
		resultado = 0;
		return resultado;
		//LO MAS IMPORTANTE
		break;
	}


	}
}

void delay(uint64_t retardo){

	while(retardo != 0){
		__asm("NOP");
		retardo--;
	}

}

