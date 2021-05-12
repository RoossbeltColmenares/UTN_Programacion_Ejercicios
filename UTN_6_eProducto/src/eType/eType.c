/*
 * eProductType.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "eType.h"

void printTypeProduct(eType listT[], int sizeT)
{
	int i;
	for (i = 0; i < sizeT; i++)
	{
		printf("\n%d     %s", listT[i].idProductType, listT[i].nameType);
	}
}

void printAverageByType(eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA)
{
	int i;
	printf(" AVERAGE PRICE BY PRODUCT TYPE");
	printf("\n        TYPE           PRICE");
	for (i = 0; i < sizeA; i++)
	{
		if (auxiliary[i].isEmpty == OCCUPIED)
		{
			printf("\n%12s %15.2f", listT[i].nameType, (auxiliary[i].price / auxiliary[i].accountant));
		}
	}
}
