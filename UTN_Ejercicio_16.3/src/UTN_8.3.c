/*
 * Ejercicio  16-3
 Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
 Realizar una funci�n que cargue un array de 3 estudiantes.
 Recibe un entero.
 Retorna el estudiante dado de alta y por par�metro 0 si funcion� correctamente -1 mal.
 Una vez devuelto el estudiante cargarlo en una posici�n del array. Al final mostrar el array cargado
 */

#include "dataEntry/input.h"
#include <stdlib.h>
#define T 3

typedef struct
{
	int id;
	char name[20];
	int age;
} eStudent;

void addStudent(eStudent *student, int valueInt);

void printStudents(eStudent *student);

int main(void)
{
	setbuf(stdout ,NULL);
	eStudent student[3];

	for (int i = 0; i < T; i++)
	{
		addStudent(student, i);
	}

	printStudents(student);
}

void printStudents(eStudent *student)
{
	for (int i = 0; i < T; i++)
	{
		printf("\nID: %d  AGE: %d  NAME: %s",(*(student + i)).id, (*(student+i)).age, (*(student+i)).name);
	}
}

void addStudent(eStudent *student, int valueInt)
{
	inputInt(&(*(student + valueInt)).id, "Enter ID:", "Error, enter ID: ");
	inputInt(&(*(student + valueInt)).age, "Enter AGE: ", "Error, enter AGE:");
	inputString((*(student + valueInt)).name, "Enter Name: ", "Error, enter Name:", 20);
}
