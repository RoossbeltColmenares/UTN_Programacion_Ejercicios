/*
 * eProductNationality.h
 *
 *  Created on: 1 may. 2021
 *      Author: Yesid
 */

#ifndef ENATIONALITY_ENATIONALITY_H_
#define ENATIONALITY_ENATIONALITY_H_
#include <stdio.h>
#define SIZE_N 3
#define TRUE 1
#define FALSE 0

typedef struct
{
	int idNationality;
	char nameNationality[10];
} eNationality;

void printNationality(eNationality listN[], int sizeN);

int compareIdNationality(eNationality listN[], int sizeN, int id);

#endif /* ENATIONALITY_ENATIONALITY_H_ */
