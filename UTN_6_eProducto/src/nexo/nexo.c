/*
 * nexo.c
 *
 *  Created on: 8 may. 2021
 *      Author: Yesid
 */

#include "nexo.h"

int addProduct(eProduct listP[], int sizeP, eType listT[], int sizeT, eNationality listN[], int sizeN)
{
	int freePosition;
	int returnValue;

	returnValue = FALSE;
	if (searchIsEmptyProduct(listP, sizeP, &freePosition) == TRUE)
	{
		fillProduct(listP, listT, sizeT, listN, sizeN, freePosition);
		returnValue = TRUE;
	}

	return returnValue;
}

void fillProduct(eProduct listP[], eType listT[], int sizeT, eNationality listN[], int sizeN, int freePosition)
{
	listP[freePosition].isEmpty = OCCUPIED;
	listP[freePosition].id = freePosition;

	inputString(listP[freePosition].description, "Enter product description: ", "Error, enter product description: ");

	printNationality(listN, sizeN);
	inputIntR(&listP[freePosition].idNationality, "\n\nEnter the ID of the nationality: ", "Error, enter the ID of the nationality: ", listN[0].idNationality, listN[sizeN - 1].idNationality);

	printTypeProduct(listT, sizeT);
	inputIntR(&listP[freePosition].idProductType, "\n\nEnter the ID of the product type: ", "Error, enter the ID of the product type: ", listT[0].idProductType, listT[sizeT - 1].idProductType);
	inputFloat(&listP[freePosition].price, "Enter the price of the product: ", "Error, enter the price of the product: ");
}

int modificationProduct(eProduct listP[], int sizeP, eType listT[], int sizeT, int id, int option)
{
	int returnValue;
	int position;

	returnValue = FALSE;

	if (compareIdProduct(listP, sizeP, &position, id) == TRUE)
	{
		switch (option)
		{
			case 1:
				inputFloat(&listP[position].price, "\nEnter product price: ", "\nError, enter product price: ");
				break;
			case 2:
				printTypeProduct(listT, sizeT);
				inputIntR(&listP[position].idProductType, "\nEnter the ID of the product type: ", "Error, enter the ID of the product type: ", listT[0].idProductType, listT[sizeT - 1].idProductType);
				break;
		}
		returnValue = TRUE;
	}

	return returnValue;
}

void printProducts(eProduct listP[], int sizeP, eType listT[], eNationality listN[], eAuxiliary auxiliary[])
{
	int i;
	int sizeProductsOccupied;

	occupiedProduct(listP, sizeP, auxiliary, &sizeProductsOccupied);

	printf(" ID        DESCRIPTION   NATIONALITY          TYPE        PRICE");
	for (i = 0; i < sizeProductsOccupied; i++)
	{
		printf("\n%3d %18s %13s %13s %12.2f", listP[auxiliary[i].id].id, listP[auxiliary[i].id].description, listN[listP[auxiliary[i].id].idNationality - 1].nameNationality, listT[listP[auxiliary[i].id].idProductType - 1000].nameType,
				listP[auxiliary[i].id].price);
	}
}

void printMostExpensiveProducts(eProduct listP[], eType listT[], eNationality listN[], eAuxiliary auxiliary[], int sizeA)
{
	int i;

	printf(" ID        DESCRIPTION   NATIONALITY          TYPE        PRICE");
	for (i = 0; i < sizeA; i++)
	{
		printf("\n%3d %18s %13s %13s %12.2f", listP[auxiliary[i].id].id, listP[auxiliary[i].id].description, listN[listP[auxiliary[i].id].idNationality - 1].nameNationality, listT[listP[auxiliary[i].id].idProductType - 1000].nameType,
				listP[auxiliary[i].id].price);
	}
}

void printProductsWithDescription(eProduct listP[], int sizeP, eType listT[], eNationality listN[], eAuxiliary auxiliary[])
{
	int i;
	int sizeProductsOccupied;

	occupiedProduct(listP, sizeP, auxiliary, &sizeProductsOccupied);

	printf(" ID        DESCRIPTION          TYPE");
	for (i = 0; i < sizeProductsOccupied; i++)
	{
		printf("\n%3d %18s %13s", listP[auxiliary[i].id].id, listP[auxiliary[i].id].description, listT[listP[auxiliary[i].id].idProductType - 1000].nameType);
	}
}

void printProductsByType(eProduct listP[], int sizeP, eType listT[], int sizeT, eNationality listN[], eAuxiliary auxiliary[])
{
	int i;
	int j;
	int sizeProductsOccupied;

	occupiedProduct(listP, sizeP, auxiliary, &sizeProductsOccupied);

	for (j = 0; j < sizeT; j++)
	{
		printf("\n----------------------------------------------------------------");
		printf("\n%s\n", listT[j].nameType);
		printf(" ID        DESCRIPTION   NATIONALITY        PRICE");
		for (i = 0; i < sizeProductsOccupied; i++)
		{
			if (listP[auxiliary[i].id].idProductType == listT[j].idProductType)
			{
				printf("\n%3d %18s %13s %12.2f", listP[auxiliary[i].id].id, listP[auxiliary[i].id].description, listN[listP[auxiliary[i].id].idNationality - 1].nameNationality, listP[auxiliary[i].id].price);
			}
		}
	}
}

int averagePriceByTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eNationality listN[], int sizeN, eAuxiliary auxiliary[], int sizeA)
{
	int returnValue;

	returnValue = FALSE;

	if (totalPricesByTypes(listP, sizeP, listT, sizeT, auxiliary, sizeA) == TRUE)
	{
		printAverageByType(listT, sizeT, auxiliary, sizeA);
		returnValue = TRUE;
	}

	return returnValue;
}

int totalPricesByTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA)
{
	int i;
	int j;
	int returnValue;

	if (occupiedProduct(listP, sizeP, auxiliary, &sizeA) == TRUE)
	{
		for (i = 0; i < sizeA; i++)
		{
			for (j = 0; j < sizeT; j++)
			{
				if (listP[auxiliary[i].id].idProductType == listT[j].idProductType)
				{
					auxiliary[j].price += listP[auxiliary[i].id].price;
					auxiliary[j].accountant++;
					auxiliary[j].isEmpty = OCCUPIED;
					returnValue = TRUE;
				}
			}
		}
	}
	return returnValue;
}

int moreElaborateTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA)
{
	int returnValue;
	int moreRepeated;

	if (totalTypes(listP, sizeP, listT, sizeT, auxiliary, sizeA) == TRUE)
	{
		mostRepeatedType(auxiliary, sizeA, &moreRepeated);
		repeatedTypes(auxiliary, sizeA, moreRepeated);
		printMoreElaborateTypes(listT, auxiliary, sizeA);
		returnValue = TRUE;
	}

	return returnValue;
}

int totalTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA)
{
	int i;
	int j;
	int returnValue;

	if (occupiedProduct(listP, sizeP, auxiliary, &sizeA) == TRUE)
	{
		for (i = 0; i < sizeA; i++)
		{
			for (j = 0; j < sizeT; j++)
			{
				if (listP[auxiliary[i].id].idProductType == listT[j].idProductType)
				{
					auxiliary[j].accountant++;
					returnValue = TRUE;
				}
			}
		}
	}
	return returnValue;
}

int mostRepeatedType(eAuxiliary auxiliary[], int sizeA, int *moreRepeated)
{
	int i;
	int returnValue;

	returnValue = FALSE;

	for (i = 0; i < sizeA; i++)
	{
		if (*moreRepeated < auxiliary[i].accountant || returnValue == 0)
		{
			*moreRepeated = auxiliary[i].accountant;
			returnValue = TRUE;
		}
	}
	return returnValue;
}

int repeatedTypes(eAuxiliary auxiliary[], int sizeA, int moreRepeated)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	for (i = 0; i < sizeA; i++)
	{
		if (moreRepeated == auxiliary[i].accountant)
		{
			moreRepeated = auxiliary[i].accountant;
			auxiliary[i].id = i;
			auxiliary[i].isEmpty = OCCUPIED;
			returnValue = TRUE;
		}
	}
	return returnValue;
}

void printMoreElaborateTypes(eType listT[], eAuxiliary auxiliary[], int sizeA)
{
	int i;

	printf("CANT        TYPE");
	for (i = 0; i < sizeA; i++)
	{
		if (auxiliary[i].isEmpty == OCCUPIED)
		{
			printf("\n%d    %s", auxiliary[i].accountant, listT[auxiliary[i].id].nameType);
		}
	}
}

