/*
 * ingresarDatos.h
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#ifndef DATAENTRY_INPUT_H_
#define DATAENTRY_INPUT_H_
#include "../dataValidation/validate.h"
#include "../dataValidation/charString.h"

/**
 * @brief requests a number of type int and validates it
 *
 * @param intNumberEntered, number to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 * @param min, minimum number to enter
 * @param max, maximum number to enter
 * @return,
 */
int inputIntR(int *intNumberEntered, char *textString, char *textStringError, int min, int max);

/**
 * @brief requests a number of type int and validates it
 *
 * @param intNumberEntered, number to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 */
int inputInt(int *intNumberEntered, char *textString, char *textStringError);

/**
 * @brief requests a number of type double and validates it
 *
 * @param doubleNumberEntered, number to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 * @param min, minimum number to enter
 * @param max, maximum number to enter
 */
int inputDoubleR(double *doubleNumberEntered, char *textString, char *textStringError, double min, double max);

/**
 * @brief requests a number of type float and validates it
 *
 * @param floatNumberEntered, number to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 * @param min, minimum number to enter
 * @param max, maximum number to enter
 */
int inputFloatR(float *floatNumberEntered, char *textString, char *textStringError, float min, float max);

/**
 * @brief requests a number of type float and validates it
 *
 * @param floatNumberEntered, number to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 */
int inputFloat(float *floatNumberEntered, char *textString, char *textStringError);

/**
 * @brief requests a char character and validates it
 *
 * @param charCharacterEntered, char to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 */
int inputChar(char *charCharacterEntered, char *textString, char *textStringError);

/**
 * @brief requests a char character string and validates it
 *
 * @param charStringEntered, character string to validate
 * @param textString, user instructions
 * @param textStringError, error warning
 */
int inputString(char *charStringEntered, char *textString, char *textStringError, int size);

#endif /* DATAENTRY_INPUT_H_ */
