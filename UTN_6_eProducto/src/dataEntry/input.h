/*
 * ingresarDatos.h
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */


#ifndef DATAENTRY_INPUT_H_
#define DATAENTRY_INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include "../dataValidation/validate.h"

void inputIntR(int *intNumberEntered, char textString[], char textStringError[], int min, int max);

void inputInt(int *intNumberEntered, char textString[], char textStringError[]);

void inputDoubleR(double *doubleNumberEntered, char textString[], char textStringError[], double min, double max);

void inputFloatR(float *floatNumberEntered, char textString[], char textStringError[], float min, float max);

void inputFloat(float *floatNumberEntered, char textString[], char textStringError[]);

void inputChar(char *charCharacterEntered, char textString[], char textStringError[]);

void inputString(char charStringEntered[], char textString[], char textStringError[]);

#endif /* DATAENTRY_INPUT_H_ */
