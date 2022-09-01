/*
 * IntroGPIOxMain.c
 *
 *  Created on: Aug 27, 2022
 *      Author: JUAN ESTEBAN
 */


#include <stdint.h>

#include "stm32f411xx_hal.h"
#include "GPIOxDriver.h"

/*Funcion principal del programa. Es aca donde se ejecuta todo
 */

uint8_t dummy=0;
uint8_t *ptrEjemplo;
uint32_t valorPuntero=0;

int main(void){

	dummy = 30;
	ptrEjemplo= &dummy;
	*ptrEjemplo += 45;
	valorPuntero = (int)ptrEjemplo;

	//Este es el ciclo principal, donde se ejecuta todo el programa
	while(1){
		NOP();

	}
}

