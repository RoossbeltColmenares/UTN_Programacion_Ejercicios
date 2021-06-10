/*
 * input.c
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */
#include "input.h"
#include "stdio.h"
#define TRUE 1
#define FALSE 0

int inputIntR(int *intNumberEntered, char *textString, char *textStringError, int min, int max)
{
	int returnValue;

	returnValue = FALSE;
	if (intNumberEntered != NULL)
	{
		printf(textString, min,max);
		fflush(stdin);

		while (scanf("%d", intNumberEntered) == FALSE || validateRangeInt(*intNumberEntered, min, max) == TRUE)
		{
			printf(textStringError, min,max);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int inputInt(int *intNumberEntered, char *textString, char *textStringError)
{
	int returnValue;

	returnValue = FALSE;
	if (intNumberEntered != NULL)
	{
		printf("%s", textString);
		fflush(stdin);
		while (scanf("%d", intNumberEntered) == FALSE)
		{
			printf("%s", textStringError);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}
int inputDoubleR(double *doubleNumberEntered, char *textString, char *textStringError, double min, double max)
{
	int returnValue;

	returnValue = FALSE;
	if (doubleNumberEntered != NULL)
	{
		printf("%s", textString);
		fflush(stdin);

		while (scanf("%lf", doubleNumberEntered) == FALSE || validateRangeDouble(*doubleNumberEntered, min, max) == TRUE)
		{
			printf("%s", textStringError);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int inputFloatR(float *floatNumberEntered, char *textString, char *textStringError, float min, float max)
{
	int returnValue;

	if (floatNumberEntered != NULL)
	{
		printf("%s", textString);
		fflush(stdin);

		while (scanf("%f", floatNumberEntered) == FALSE || validateRangeFloat(*floatNumberEntered, min, max) == TRUE)
		{
			printf("%s", textStringError);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int inputFloat(float *floatNumberEntered, char *textString, char *textStringError)
{
	int returnValue;

	returnValue = FALSE;
	if (floatNumberEntered != NULL)
	{
		printf("%s", textString);
		fflush(stdin);
		while (scanf("%f", floatNumberEntered) == FALSE)
		{
			printf("%s", textStringError);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int inputChar(char *charCharacterEntered, char *textString, char *textStringError)
{
	int returnValue;

	returnValue = FALSE;
	if (charCharacterEntered != NULL)
	{
		printf("%s", textString);
		fflush(stdin);

		while (scanf("%c", charCharacterEntered) == FALSE || isalnum(*charCharacterEntered) == FALSE)
		{
			printf("%s", textStringError);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int inputString(char *charStringEntered, char *textString, char *textStringError, int size)
{
	int returnValue;

	returnValue = FALSE;
	if (charStringEntered != NULL)
	{
		printf(textString, size+1);
		fflush(stdin);
		while (scanf("%[^\n]", charStringEntered) == FALSE || validationString(charStringEntered, size) == FALSE|| removeSpaces(charStringEntered) == FALSE)
		{
			printf(textStringError, size+1);
			fflush(stdin);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

