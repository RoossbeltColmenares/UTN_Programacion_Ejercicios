/*
 * eProductoAuxiliary.c
 *
 *  Created on: 7 may. 2021
 *      Author: Yesid
 */
#include "eAuxiliary.h"
#define VOID 0

void initializeStatusAuxiliary(eAuxiliary listA[], int sizeA)
{
	int i;
	for (i = 0; i < sizeA; i++)
	{
		listA[i].id = VOID;
		listA[i].isEmpty = VOID;
		listA[i].price = VOID;
		listA[i].accountant = VOID;
	}
}

void printAuxiliary(eAuxiliary listA[], int sizeA)
{
	int i;
	for (i = 0; i < sizeA; i++)
	{
		printf("\n%d", listA[i].id);
	}
}

