/*
 * Yesid Colmenares - Ejercicio 17.3
 Realizar una función que reciba como parámetro un array de enteros, su tamaño, un valor entero y un índice.
 La función se encargará de insertar el valor entero en el índice especificado. El array deberá reestructurarse dinámicamente.
 */

#include "dataEntry/input.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 4

int function(int *array, int size, int valueInt, int index);

int addElements(int *array, int size);

int indexElement(int *array, int size, int index, int valueInt);

int printElements(int *array, int size);

int main(void)
{
	setbuf(stdout, NULL);

	int *pArray;

	pArray = (int*) malloc(sizeof(int) * SIZE);

	if (addElements(pArray, SIZE) == TRUE)
	{
		function(pArray, SIZE, 50, 3);
	}
}

int printElements(int *array, int size)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			printf("\n%d", *(array + i));
		}
		returnValue = TRUE;
	}

	return returnValue;
}

int indexElement(int *array, int size, int index, int valueInt)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		for (i = size; i > index; i--)
		{
			*(array + i) = *(array + i - 1);
		}
		*(array + i) = valueInt;
		returnValue = TRUE;
	}
	return returnValue;
}

int function(int *array, int size, int valueInt, int index)
{
	int returnValue;

	returnValue = FALSE;
	if (array != NULL)
	{
		array = (int*) realloc(array, (sizeof(int) * (SIZE + 1)));
		indexElement(array, size + 1, index, valueInt);
		printElements(array, size + 1);
		returnValue = TRUE;
	}

	return returnValue;
}

int addElements(int *array, int size)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			inputInt((array + i), "\nEnter: ", "\nError, enter: ");
		}
		returnValue = TRUE;
	}
	return returnValue;
}
