/*
 * ingresarDatos.h
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef INGRESODEDATOS_INGRESARDATOS_H_
#define INGRESODEDATOS_INGRESARDATOS_H_

void ingresarIntR(int *numeroIntIngresado, char cadenaTexto[], char cadenaError[], int minimo, int maximo);

void ingresarInt(int *numeroIntIngresado, char cadenaTexto[], char cadenaError[]);

void ingresarDoubleR(double *numeroDoubleIngresado, char cadenaTexto[], char cadenaError[], double minimo, double maximo);

void ingresarFloatR(float *numeroFloatIngresado, char cadenaTexto[], char cadenaError[], float minimo, float maximo);

void ingresarFloat(float *numeroFloatIngresado, char cadenaTexto[], char cadenaError[]);

void ingresarChar(char *caracterCharIngresado, char cadenaTexto[], char cadenaError[]);

void ingresarString(char cadenaStringIngresado[], char cadenaTexto[]);

#endif /* INGRESODEDATOS_INGRESARDATOS_H_ */
