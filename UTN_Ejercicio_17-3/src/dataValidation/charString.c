/*
 * string.c
 *
 *  Created on: 15 may. 2021
 *      Author: Yesid
 */
#include "charString.h"

char* stringToUpper(char *charStringEntered)
{
	int i;

	for (i = 0; charStringEntered[i] != '\0'; i++)
	{
		charStringEntered[i] = toupper(charStringEntered[i]);
	}

	return charStringEntered;
}

char* stringToLower(char *charStringEntered)
{
	int i;

	for (i = 0; charStringEntered[i] != '\0'; i++)
	{
		charStringEntered[i] = tolower(charStringEntered[i]);
	}

	return charStringEntered;
}

int isSymbol_Number(char character)
{
	int returnValue;

	returnValue = FALSE;
	if ((32 < (int) character && 65 > (int) character) || (90 < (int) character && 97 > (int) character) || (122 < (int) character && 127 > (int) character))
	{
		returnValue = TRUE;
	}

	return returnValue;
}

