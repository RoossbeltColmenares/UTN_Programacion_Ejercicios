/*
 * string.h
 *
 *  Created on: 15 may. 2021
 *      Author: Yesid
 */

#ifndef DATAVALIDATION_CHARSTRING_H_
#define DATAVALIDATION_CHARSTRING_H_
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

/**
 * @brief converts a character string to uppercase
 *
 * @param charStringEntered, character string
 * @return, returns the uppercase character string
 */
char* stringToUpper(char *charStringEntered);

/**
 * @brief converts a character string to lowercase
 *
 * @param charStringEntered, character string
 * @return, returns the lowercase character string
 */

char* stringToLower(char *charStringEntered);

/**
 * @brief detects if there is a symbol or number in the character entered
 *
 * @param character, character entered
 * @return,1 if it is correct or 2 if there is an error
 */
int isSymbol_Number(char character);
#endif /* DATAVALIDATION_CHARSTRING_H_ */
