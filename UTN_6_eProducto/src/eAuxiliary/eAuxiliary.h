/*
 * eProductAuxiliary.h
 *
 *  Created on: 7 may. 2021
 *      Author: Yesid
 */

#ifndef EAUXILIARY_EAUXILIARY_H_
#define EAUXILIARY_EAUXILIARY_H_
#define SIZE_A SIZE_P
#include <stdio.h>

typedef struct
{
	int isEmpty;
	int id;
	int idType;
	float price;
	int accountant;
} eAuxiliary;

void initializeStatusAuxiliary(eAuxiliary listA[], int sizeA);

void printAuxiliary(eAuxiliary listA[], int sizeA);

#endif /* EAUXILIARY_EAUXILIARY_H_ */
