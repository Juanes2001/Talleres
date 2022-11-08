/**
 ******************************************************************************
 * Examen_Tema_4
 * Autor: Juan Esteban Rodriguez Ochoa
 * Correo: jrodriguezoc@unal.edu.co
 ******************************************************************************
 ******************************************************************************
 */
#include "BasicTimer.h"
#include "GPIOxDriver.h"
#include "USARTxDriver.h"
#include "EXTIDriver.h"
#include "PwmDriver.h"
#include "I2CDriver.h"
#include "AdcDriver.h"
#include "OLEDDriver.h"
#include "RTCDriver.h"

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// configuracion USART que se usara = Serial_1, 28800, EVEN

//handler para ADC
ADC_Config_t handlerADCJoy = {0};

//Pines handler para comunicación Serial
GPIO_Handler_t handlerPinTx = {0};
GPIO_Handler_t handlerPinRx = {0};

GPIO_Handler_t handlerPinR = {0};
GPIO_Handler_t handlerPinG = {0};
GPIO_Handler_t handlerPinB = {0};

GPIO_Handler_t handlerI2cSCL = {0};
GPIO_Handler_t handlerI2cSDA = {0};

//Pin del blinky
GPIO_Handler_t handlerLEDPin = {0};

//handler para USART1
USART_Handler_t handlerUSART1 = {0};

//handler para PWM

PWM_Handler_t handlerPwmR   = {0};
PWM_Handler_t handlerPwmG   = {0};
PWM_Handler_t handlerPwmB   = {0};

//Handlers de Timers
BasicTimer_Handler_t handlerLEDTim = {0};
BasicTimer_Handler_t handlerADCTim = {0};
BasicTimer_Handler_t handlerDateTim = {0};

//handlers I2C
I2C_Handler_t handlerI2C1 = {0};

//handler para el tiempo actual
RTC_Handler_t handlerRTC = {0};


void inSystem (void);
void parseCommands(char *stringVector);


//Variables necesarias para el programa
uint32_t adcData[2] ;
uint8_t adcFlag = RESET;
uint8_t rxData = '\0';
uint8_t counter = 0;
char cmd[32];
char userMsg[64];



unsigned int firstParameter;
unsigned int secondParameter;
unsigned int thirdParameter;

char bufferReception[64];

uint8_t counterReception = 0;
uint8_t doneTransaction = RESET;
uint8_t counterADC = 0;

uint8_t setPWM = RESET;

uint8_t duttyUpR = 0;
uint8_t duttyUpG = 0;
uint8_t duttyUpB1 = 0;
uint8_t duttyUpB2 = 0;
uint8_t duttyDownR = 0;
uint8_t duttyDownG1 = 0;
uint8_t duttyDownG2 = 0;
uint8_t duttyDownB = 0;
uint16_t vectorArcUp = 0;
uint16_t vectorArcDown = 0;

int16_t x = 0;
int16_t y = 0;

uint8_t com1 = 0;
uint8_t com2 = 0;
uint8_t com3 = 0;
uint8_t com4 = 0;
uint8_t com5 = 0;
uint8_t com6 = 0;
uint8_t com7 = 0;
uint8_t com8 = 0;
uint8_t com9 = 0;
uint8_t com10 = 0;
uint8_t com11 = 0;

uint8_t flagDate = RESET;

char date[16];

uint8_t  sec = 0;
uint8_t  min = 0;
uint8_t  hours = 0;

uint8_t setScrollIN = RESET;
uint8_t setScrollOUT = SET;
uint8_t setScrollUP = RESET;
uint8_t setScrollDOWN = RESET;


//ADDRESS OLED

#define ADDRESS 0b0111100



//Este es el corazon del programa donde se ejecuta todo
int main(void){

	inSystem();

	while(1){

	}
}


void inSystem (void){
	//Descripcion de la configuracion

		//BLINKY LED

		handlerLEDPin.pGPIOx = GPIOA;
		handlerLEDPin.GPIO_PinConfig.GPIO_PinAltFunMode = AF0;
		handlerLEDPin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		handlerLEDPin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
		handlerLEDPin.GPIO_PinConfig.GPIO_PinNumber = PIN_5;
		handlerLEDPin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDR_NOTHING;
		handlerLEDPin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEEDR_FAST;
		GPIO_Config(&handlerLEDPin);

		handlerLEDTim.ptrTIMx = TIM2;
		handlerLEDTim.TIMx_Config.TIMx_interruptEnable = 1;
		handlerLEDTim.TIMx_Config.TIMx_mode = BTIMER_MODE_UP;
		handlerLEDTim.TIMx_Config.TIMx_period = 2500;
		handlerLEDTim.TIMx_Config.TIMx_speed = BTIMER_SPEED_100us;
		BasicTimer_Config(&handlerLEDTim);

		startTimer(&handlerLEDTim);

		//Conversion del JOYSTICK
		handlerADCTim.ptrTIMx = TIM4;
		handlerADCTim.TIMx_Config.TIMx_interruptEnable = 1;
		handlerADCTim.TIMx_Config.TIMx_mode = BTIMER_MODE_UP;
		handlerADCTim.TIMx_Config.TIMx_period = 100;
		handlerADCTim.TIMx_Config.TIMx_speed = BTIMER_SPEED_100us;
		BasicTimer_Config(&handlerADCTim);


		handlerADCJoy.channelVector[0] = 0;
		handlerADCJoy.channelVector[1] = 1;
		handlerADCJoy.dataAlignment = ADC_ALIGNMENT_RIGHT;
		handlerADCJoy.resolution = ADC_RESOLUTION_12_BIT;
		handlerADCJoy.samplingPeriod = ADC_SAMPLING_PERIOD_28_CYCLES;
		ADC_ConfigMultichannel(&handlerADCJoy, 2);
}


// Callback para el blynky y el comando Scroll UP y DOWN
void BasicTimer2_Callback(void){
	GPIOxTooglePin(&handlerLEDPin);
	if (!(setScrollOUT)){

		if (setScrollIN){
			setScrollUP = SET;
		}else{
			setScrollDOWN = SET;
		}
	}else{
		__NOP();
	}
}
