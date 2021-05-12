/*
 * eProductNationality.c
 *
 *  Created on: 1 may. 2021
 *      Author: Yesid
 */

#include "eNationality.h"

void printNationality(eNationality listN[], int sizeN)
{
	int i;

	for (i = 0; i < sizeN; i++)
	{
		printf("\n%d     %s", listN[i].idNationality, listN[i].nameNationality);
	}
}

int compareIdNationality(eNationality listN[], int sizeN, int id)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeN; i++)
	{
		if (listN[i].idNationality == id)
		{
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}
