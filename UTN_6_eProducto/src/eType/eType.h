/*
 * eProductType.h
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#ifndef ETYPE_ETYPE_H_
#define ETYPE_ETYPE_H_
#define SIZE_T 4
#define OCCUPIED 1

#include <stdio.h>
#include "../eAuxiliary/eAuxiliary.h"

typedef struct
{
	int idProductType;
	char nameType[50];
} eType;

void printTypeProduct(eType listT[], int sizeT);

void printAverageByType(eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA);

#endif /* ETYPE_ETYPE_H_ */
