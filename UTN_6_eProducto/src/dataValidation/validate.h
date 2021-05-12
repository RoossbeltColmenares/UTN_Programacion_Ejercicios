/*
 * validate.h
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */


#ifndef DATAVALIDATION_VALIDATE_H_
#define DATAVALIDATION_VALIDATE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * @brief valida un numero Decimal o Entero y retorna un 0 o un 1 dependiendo si cumple la condicion
 *
 * @param value, es el numero a validar el rango
 * @param min, es el value min que se acepta
 * @param max, es el value max que se acepta
 * @return retorna 1 si esta fuera del rango, de lo contrario retorna un 0
 */
int validateRangeDouble(double value, double min, double max);

int validateRangeInt(int value, int min, int max);

int validateRangeFloat(float value, float min, float max);

int validateRangeChar(char character, char characterMin, char characterMax);

#endif /* DATAVALIDATION_VALIDATE_H_ */
