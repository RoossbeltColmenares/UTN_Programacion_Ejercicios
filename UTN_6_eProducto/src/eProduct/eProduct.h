/*
 * eProductMainMenu.h
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#ifndef EPRODUCT_EPRODUCT_H_
#define EPRODUCT_EPRODUCT_H_
#define SIZE_P 5
#define VOID -1
#define OCCUPIED 1
#define TRUE 1
#define FALSE 0

#include <string.h>
#include "../eAuxiliary/eAuxiliary.h"

typedef struct
{
	int isEmpty;
	int id;
	int idProductType;
	char description[50];
	int idNationality;
	float price;
} eProduct;

void initializeStatusProduct(eProduct listP[], int sizeP);

int removeProduct(eProduct listP[], int sizeP, int id);

int searchIsEmptyProduct(eProduct listP[], int sizeP, int *position);

int compareIdProduct(eProduct listP[], int sizeP, int *position, int id);

int priceLowToHighProduct(eProduct listP[], int sizeP);

int priceHighToLowProduct(eProduct listP[], int sizeP);

int sortByDescriptionProduct(eProduct listP[], int sizeP);

int thereAreProducts(eProduct listP[], int sizeP);

int originalOrderProducts(eProduct listP[], int sizeP);

int mostExpensivePrice(eProduct listP[], int sizeP, float *priceMostExpensive);

int occupiedProduct(eProduct listP[], int sizeP, eAuxiliary auxiliary[], int *sizeA);

int repeatedProductsByPrice(eProduct listP[], int sizeP, eAuxiliary positions[], int *sizeA, float price);

void mostExpensiveProducts(eProduct listP[], int sizeP, eAuxiliary auxiliary[], int *sizeA);

#endif /* EPRODUCT_EPRODUCT_H_ */
