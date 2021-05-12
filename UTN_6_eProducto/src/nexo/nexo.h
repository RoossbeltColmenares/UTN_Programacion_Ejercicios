/*
 * nexo.h
 *
 *  Created on: 8 may. 2021
 *      Author: Yesid
 */

#ifndef NEXO_NEXO_H_
#define NEXO_NEXO_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../dataEntry/input.h"
#include "../eAuxiliary/eAuxiliary.h"
#include "../eNationality/eNationality.h"
#include "../eProduct/eProduct.h"
#include "../eType/eType.h"

int addProduct(eProduct listP[], int sizeP, eType listT[], int sizeT, eNationality listN[], int sizeN);

void fillProduct(eProduct listP[], eType listT[], int sizeT, eNationality listN[], int sizeN, int freePosition);

void printProducts(eProduct listP[], int sizeP, eType listT[], eNationality listN[], eAuxiliary auxiliary[]);

void printMostExpensiveProducts(eProduct listP[], eType listT[], eNationality listN[], eAuxiliary auxiliary[], int sizeA);

void printProductsWithDescription(eProduct listP[], int sizeP, eType listT[], eNationality listN[], eAuxiliary auxiliary[]);

void printProductsByType(eProduct listP[], int sizeP, eType listT[], int sizeT, eNationality listN[], eAuxiliary auxiliary[]);

int modificationProduct(eProduct listP[], int sizeP, eType listT[], int sizeT, int id, int option);

int totalPricesByTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA);

int averagePriceByTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eNationality listN[], int sizeN, eAuxiliary auxiliary[], int sizeA);

int moreElaborateTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA);

int totalTypes(eProduct listP[], int sizeP, eType listT[], int sizeT, eAuxiliary auxiliary[], int sizeA);

int mostRepeatedType(eAuxiliary auxiliary[], int sizeA, int *moreRepeated);

int repeatedTypes(eAuxiliary auxiliary[], int sizeA, int moreRepeated);

void printMoreElaborateTypes(eType listT[], eAuxiliary auxiliary[], int sizeA);

#endif /* NEXO_NEXO_H_ */
