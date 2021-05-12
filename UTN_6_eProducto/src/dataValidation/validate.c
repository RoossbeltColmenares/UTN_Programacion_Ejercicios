/*
 * validate.c
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#include "validate.h"

int validateRangeDouble(double value, double min, double max)
{
	int returnValue;

	returnValue = 0;

	if (value < min || value > max)
	{
		returnValue = 1;
	}

	return returnValue;
}

int validateRangeInt(int value, int min, int max)
{
	int returnValue;

	returnValue = 0;

	if (value < min || value > max)
	{
		returnValue = 1;
	}

	return returnValue;
}

int validateRangeFloat(float value, float min, float max)
{
	int returnValue;

	returnValue = 0;

	if (value < min || value > max)
	{
		returnValue = 1;
	}

	return returnValue;
}

