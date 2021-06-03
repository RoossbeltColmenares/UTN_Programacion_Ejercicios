/*
 * Yesid Colmenares - Ejercicio 17.2
 Realizar una función que reciba como parámetro un array de enteros,
 su tamaño y un entero. La función se encargará de buscar el valor entero
 y borrará la primera ocurrencia del mismo. El array deberá reestructurarse dinámicamente.
 */

#include "dataEntry/input.h"
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define T 5

int function(int *array, int *pSize, int value);

int removeElement(int *array, int index, int *pSize);

int addElements(int *array, int *pSize);

int printElements(int *array, int *pSize);

int decreaseSize(int *pSize, int size);

int main(void)
{
	setbuf(stdout, NULL);

	int *array;
	int *pSize;

	int value;
	int size;

	size = 10;
	pSize = &size;

	value = 4;
	array = (int*) malloc(sizeof(int) * (*pSize));

	printf("Before list\n");
	addElements(array, pSize);
	if (!function(array, pSize, value))
	{
		printf("\nThe number does not exist\n");
	}
	else
	{
		printf("\nAfter list");
		printElements(array, pSize);
	}

}

int decreaseSize(int *pSize, int size)
{
	int returnValue;

	returnValue = FALSE;
	if (pSize != NULL)
	{
		*pSize = *pSize - size;
		returnValue = TRUE;
	}
	return returnValue;
}

int printElements(int *array, int *pSize)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		returnValue = TRUE;
		for (i = 0; i < *pSize; i++)
		{
			printf("\nValue: %d", *(array + i));
		}
	}
	return returnValue;
}

int addElements(int *array, int *pSize)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		for (i = 0; i < *pSize; i++)
		{
			inputInt((array + i), "Enter: ", "Error, enter: ");
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int removeElement(int *array, int index, int *pSize)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		for (i = index; i < *pSize; i++)
		{
			*(array + i) = *(array + (i + 1));
		}
		decreaseSize(pSize, 1);
		returnValue = TRUE;
	}
	return returnValue;
}

int function(int *array, int *pSize, int value)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		for (i = 0; i < *pSize; i++)
		{
			if (*(array + i) == value)
			{
				removeElement(array, i, pSize);
				array = (int*) realloc(array, sizeof(int) * (*pSize));
				decreaseSize(&i, 1);
				returnValue = TRUE;
			}
		}
	}

	return returnValue;
}
