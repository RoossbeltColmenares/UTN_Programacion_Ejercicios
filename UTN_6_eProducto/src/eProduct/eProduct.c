/*
 * eProductMainMenu.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "eProduct.h"

void initializeStatusProduct(eProduct listP[], int sizeP)
{
	int i;

	for (i = 0; i < sizeP; i++)
	{
		listP[i].isEmpty = VOID;
	}
}

int removeProduct(eProduct listP[], int sizeP, int id)
{
	int returnValue;
	int position;

	returnValue = FALSE;
	if (compareIdProduct(listP, sizeP, &position, id) == TRUE)
	{
		listP[position].isEmpty = VOID;
		listP[position].id = VOID;
		returnValue = TRUE;
	}
	return returnValue;
}

int searchIsEmptyProduct(eProduct listP[], int sizeP, int *position)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	*position = sizeP;
	for (i = 0; i < sizeP; i++)
	{
		if (listP[i].isEmpty == VOID)
		{
			*position = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int compareIdProduct(eProduct listP[], int sizeP, int *position, int id)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeP; i++)
	{
		if (listP[i].id == id)
		{
			*position = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int priceLowToHighProduct(eProduct listP[], int sizeP)
{
	int returnValue;
	int i;
	int j;
	eProduct auxiliary;

	returnValue = FALSE;

	for (i = 0; i < sizeP - 1; i++)
	{
		for (j = i + 1; j < sizeP; j++)
		{
			if (listP[i].price > listP[j].price)
			{
				auxiliary = listP[j];
				listP[j] = listP[i];
				listP[i] = auxiliary;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

int originalOrderProducts(eProduct listP[], int sizeP)
{
	int returnValue;
	int i;
	int j;
	eProduct auxiliary;

	returnValue = FALSE;

	for (i = 0; i < sizeP - 1; i++)
	{
		for (j = i + 1; j < sizeP; j++)
		{
			if (listP[i].id > listP[j].id)
			{
				auxiliary = listP[j];
				listP[j] = listP[i];
				listP[i] = auxiliary;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

int priceHighToLowProduct(eProduct listP[], int sizeP)
{
	int returnValue;
	int i;
	int j;
	eProduct auxiliary;

	returnValue = FALSE;

	for (i = 0; i < sizeP - 1; i++)
	{
		for (j = i + 1; j < sizeP; j++)
		{
			if (listP[i].price < listP[j].price)
			{
				auxiliary = listP[j];
				listP[j] = listP[i];
				listP[i] = auxiliary;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

int sortByDescriptionProduct(eProduct listP[], int sizeP)
{
	int returnValue;
	int i;
	int j;
	eProduct auxiliary;

	returnValue = FALSE;

	for (i = 0; i < sizeP - 1; i++)
	{
		for (j = i + 1; j < sizeP; j++)
		{
			if (strcmp(listP[i].description, listP[j].description) > 0)
			{
				auxiliary = listP[j];
				listP[j] = listP[i];
				listP[i] = auxiliary;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

int thereAreProducts(eProduct listP[], int sizeP)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeP; i++)
	{
		if (listP[i].isEmpty == OCCUPIED)
		{
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int mostExpensivePrice(eProduct listP[], int sizeP, float *priceMostExpensive)
{
	int i;
	int returnValue;
	int sizeA;
	eAuxiliary auxiliary[sizeP];

	occupiedProduct(listP, sizeP, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA; i++)
	{
		if (*priceMostExpensive < listP[auxiliary[i].id].price || returnValue == FALSE)
		{
			*priceMostExpensive = listP[auxiliary[i].id].price;
			returnValue = TRUE;
		}
	}
	return returnValue;
}

int occupiedProduct(eProduct listP[], int sizeP, eAuxiliary auxiliary[], int *sizeA)
{
	int returnValue;
	int i;
	int j;

	returnValue = FALSE;

	j = 0;
	for (i = 0; i < sizeP; i++)
	{
		if (listP[i].isEmpty == OCCUPIED)
		{
			auxiliary[j].id = i;
			j++;
			returnValue = TRUE;
		}
	}
	*sizeA = j;
	return returnValue;
}

int repeatedProductsByPrice(eProduct listP[], int sizeP, eAuxiliary positions[], int *sizeA, float price)
{
	int returnValue;
	int i;
	int j;

	returnValue = FALSE;

	j = 0;
	for (i = 0; i < sizeP; i++)
	{
		if (price == listP[i].price)
		{
			positions[j].id = i;
			j++;
			returnValue = TRUE;
		}
	}
	*sizeA = j;
	return returnValue;
}

void mostExpensiveProducts(eProduct listP[], int sizeP, eAuxiliary auxiliary[], int *sizeA)
{
	float priceMostExpensive;
	int sizeMostExpensive;

	mostExpensivePrice(listP, sizeP, &priceMostExpensive);
	repeatedProductsByPrice(listP, sizeP, auxiliary, &sizeMostExpensive , priceMostExpensive);

	*sizeA = sizeMostExpensive;

}
