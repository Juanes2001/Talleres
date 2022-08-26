/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: ALEJANDRA MARIA
 */

#include <stdint.h>

//Definicion de variables

//variable de 8 bits

unsigned char siempreUsarCamelCase = 0;

uint8_t diasDeLaSemana = 7; //variable creada por nosotros que no es propio del lenguaje


char miPrimerCaracter = 'J'; //variable signada donde asignamos el valor definido numero para la letra J

int8_t miPrimerNumeroNegativo = -12; //Variable signada creada por nosotros

unsigned short diasAnuales=365; //variable no signada de 16 bits

uint16_t diasAnuales9 = 365; //Variable de 16 bits creada por nosotros

unsigned int x, y, z; //definicion de varias variables sin signo y sin asignacion de valor

int a=1,b=2,c=3;
unsigned int d=1; int j; long k;


//ARREGLOS

char miPrimerArreglo[5] = "LINUX"; //Arreglo de 5 espacios tipo char numericas asociadas a caracteres con su propio codigo numerico en 8 bits

uint32_t miSegundoArreglo[3] = {29902,789223,8}; // Los datos se incertan en un arreglo entre llaves

int main(void){

	// Comprobaremos el tamaño de variables en diferentes compiladores
	char edad =21;

	char sizeChar =sizeof(edad);
	char sizeShort = sizeof(char);
	char sizedInt = sizeof(int);
	char sizedLongInt = sizeof(long int);
	char sizedLongLongInt = sizeof (long long int);

}


/*
 * += # aumenta intrementa en el numero que se asigne
 * ++ aumenta en uno
 */
