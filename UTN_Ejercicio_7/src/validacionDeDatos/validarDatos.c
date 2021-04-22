/*
 * validarDatos.c
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#include "validarDatos.h"

int validarRangoDouble(double valor, double minimo, double maximo)
{
	int valorRetorno;

	valorRetorno = 0;

	if (valor < minimo || valor > maximo)
	{
		valorRetorno = 1;
	}

	return valorRetorno;
}

int validarRangoInt(int valor, int minimo, int maximo)
{
	int valorRetorno;

	valorRetorno = 0;

	if (valor < minimo || valor > maximo)
	{
		valorRetorno = 1;
	}

	return valorRetorno;
}

int validarRangoFloat(float valor, float minimo, float maximo)
{
	int valorRetorno;

	valorRetorno = 0;

	if (valor < minimo || valor > maximo)
	{
		valorRetorno = 1;
	}

	return valorRetorno;
}

