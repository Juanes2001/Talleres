/*
 * IntroGPIOxMain.c
 *
 *  Created on: Aug 27, 2022
 *      Author: JUAN ESTEBAN
 */


#include <stdint.h>

#include "stm32f4xx.h"
#include "GPIOxDriver.h"
#include "BasicTimer.h"

/*Funcion principal del programa. Es aca donde se ejecuta todo
 */
BasicTimer_Handler_t handlerTimer2 ={0};


int main(void){

	handlerTimer2.ptrTIMx                            =TIM2;
	handlerTimer2.TIMx_Config.TIMx_mode              = BTIMER_MODE_UP;
	handlerTimer2.TIMx_Config.TIMx_speed             = BTIMER_SPEED_100us;
	handlerTimer2.TIMx_Config.TIMx_interruptEnable   ;
	handlerTimer2.TIMx_Config.TIMx_period            ;

	//Este es el ciclo principal, donde se ejecuta todo el programa
	while(1){
		__NOP();

	}
}

