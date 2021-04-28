/*
 * ingresarDatos.c
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */
#include "ingresarDatos.h"
#include "../validacionDeDatos/validarDatos.h"

void ingresarIntR(int *numeroIntIngresado, char cadenaTexto[], char cadenaError[], int minimo, int maximo)
{
	int auxiliarValidacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	auxiliarValidacion = scanf("%d", numeroIntIngresado);
	while (auxiliarValidacion == 0 || validarRangoInt(*numeroIntIngresado, minimo, maximo) == 1)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		auxiliarValidacion = scanf("%d", numeroIntIngresado);
	}
}

void ingresarInt(int *numeroIntIngresado, char cadenaTexto[], char cadenaError[])
{
	int auxiliarValidacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	auxiliarValidacion = scanf("%d", numeroIntIngresado);
	while (auxiliarValidacion == 0)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		auxiliarValidacion = scanf("%d", numeroIntIngresado);
	}
}
void ingresarDoubleR(double *numeroDoubleIngresado, char cadenaTexto[], char cadenaError[], double minimo, double maximo)
{
	int auxiliarValidacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	auxiliarValidacion = scanf("%lf", numeroDoubleIngresado);
	while (auxiliarValidacion == 0 || validarRangoDouble(*numeroDoubleIngresado, minimo, maximo) == 1)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		auxiliarValidacion = scanf("%lf", numeroDoubleIngresado);
	}
}

void ingresarFloatR(float *numeroFloatIngresado, char cadenaTexto[], char cadenaError[], float minimo, float maximo)
{
	int auxiliarValidacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	auxiliarValidacion = scanf("%f", numeroFloatIngresado);
	while (auxiliarValidacion == 0 || validarRangoFloat(*numeroFloatIngresado, minimo, maximo) == 1)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		auxiliarValidacion = scanf("%f", numeroFloatIngresado);
	}
}

void ingresarFloat(float *numeroFloatIngresado, char cadenaTexto[], char cadenaError[])
{
	int auxiliarValidacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	auxiliarValidacion = scanf("%f", numeroFloatIngresado);
	while (auxiliarValidacion == 0)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		auxiliarValidacion = scanf("%f", numeroFloatIngresado);
	}
}

void ingresarChar(char *caracterCharIngresado, char cadenaTexto[], char cadenaError[])
{
	int auxiliarValidacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	auxiliarValidacion = scanf("%c", caracterCharIngresado);
	while (auxiliarValidacion == 0 || isalnum(*caracterCharIngresado) == 0)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		auxiliarValidacion = scanf("%c", caracterCharIngresado);
	}
}

void ingresarString(char cadenaStringIngresado[], char cadenaTexto[])
{
	printf("%s", cadenaTexto);
	fflush(stdin);
	scanf("%[^\n]", cadenaStringIngresado);
}

