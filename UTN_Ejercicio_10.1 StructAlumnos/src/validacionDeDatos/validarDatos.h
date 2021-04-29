/*
 * validarDatos.h
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef VALIDACIONDEDATOS_VALIDARDATOS_H_
#define VALIDACIONDEDATOS_VALIDARDATOS_H_

/**
 * @brief valida un numero Decimal o Entero y retorna un 0 o un 1 dependiendo si cumple la condicion
 *
 * @param valor, es el numero a validar el rango
 * @param minimo, es el valor minimo que se acepta
 * @param maximo, es el valor maximo que se acepta
 * @return retorna 1 si esta fuera del rango, de lo contrario retorna un 0
 */
int validarRangoDouble(double valor, double minimo, double maximo);

int validarRangoInt(int valor, int minimo, int maximo);

int validarRangoFloat(float valor, float minimo, float maximo);

int validarRangoChar(char caracter, char caracterMinimo, char caracterMaximo);

#endif /* VALIDACIONDEDATOS_VALIDARDATOS_H_ */
