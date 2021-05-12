/*
 * input.c
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */
#include "input.h"

void inputIntR(int *intNumberEntered, char textString[], char textStringError[], int min, int max)
{
	int auxiliaryValidation;

	printf("%s", textString);
	fflush(stdin);
	auxiliaryValidation = scanf("%d", intNumberEntered);
	while (auxiliaryValidation == 0 || validateRangeInt(*intNumberEntered, min, max) == 1)
	{
		printf("%s", textStringError);
		fflush(stdin);
		auxiliaryValidation = scanf("%d", intNumberEntered);
	}
}

void inputInt(int *intNumberEntered, char textString[], char textStringError[])
{
	int auxiliaryValidation;

	printf("%s", textString);
	fflush(stdin);
	auxiliaryValidation = scanf("%d", intNumberEntered);
	while (auxiliaryValidation == 0)
	{
		printf("%s", textStringError);
		fflush(stdin);
		auxiliaryValidation = scanf("%d", intNumberEntered);
	}
}
void inputDoubleR(double *doubleNumberEntered, char textString[], char textStringError[], double min, double max)
{
	int auxiliaryValidation;

	printf("%s", textString);
	fflush(stdin);
	auxiliaryValidation = scanf("%lf", doubleNumberEntered);
	while (auxiliaryValidation == 0 || validateRangeDouble(*doubleNumberEntered, min, max) == 1)
	{
		printf("%s", textStringError);
		fflush(stdin);
		auxiliaryValidation = scanf("%lf", doubleNumberEntered);
	}
}

void inputFloatR(float *floatNumberEntered, char textString[], char textStringError[], float min, float max)
{
	int auxiliaryValidation;

	printf("%s", textString);
	fflush(stdin);
	auxiliaryValidation = scanf("%f", floatNumberEntered);
	while (auxiliaryValidation == 0 || validateRangeFloat(*floatNumberEntered, min, max) == 1)
	{
		printf("%s", textStringError);
		fflush(stdin);
		auxiliaryValidation = scanf("%f", floatNumberEntered);
	}
}

void inputFloat(float *floatNumberEntered, char textString[], char textStringError[])
{
	int auxiliaryValidation;

	printf("%s", textString);
	fflush(stdin);
	auxiliaryValidation = scanf("%f", floatNumberEntered);
	while (auxiliaryValidation == 0)
	{
		printf("%s", textStringError);
		fflush(stdin);
		auxiliaryValidation = scanf("%f", floatNumberEntered);
	}
}

void inputChar(char *charCharacterEntered, char textString[], char textStringError[])
{
	int auxiliaryValidation;

	printf("%s", textString);
	fflush(stdin);
	auxiliaryValidation = scanf("%c", charCharacterEntered);
	while (auxiliaryValidation == 0 || isalnum(*charCharacterEntered) == 0)
	{
		printf("%s", textStringError);
		fflush(stdin);
		auxiliaryValidation = scanf("%c", charCharacterEntered);
	}
}

void inputString(char charStringEntered[], char textString[], char textStringError[])
{
	printf("%s", textString);
	fflush(stdin);
	scanf("%[^\n]", charStringEntered);
	while (strcmp(charStringEntered, "\0") == 0)
	{
		printf("%s", textStringError);
		fflush(stdin);
		scanf("%[^\n]", charStringEntered);
	}
}

