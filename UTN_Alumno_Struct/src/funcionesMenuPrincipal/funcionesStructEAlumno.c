/*
 * funciones.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "funcionesStructEAlumno.h"

#include <string.h>

void altaEstudiantes(eAlumno alumno[], int tamanno)
{
	int posicionLibre;

	if (comprobarEspacioAlumnos(&posicionLibre, alumno, tamanno) == 1)
	{
		pedirDatosAlumno(posicionLibre, alumno);
	}
	else
	{
		printf("No hay mas espacio, por favor agregue mas cupos o elimine un alumno/n");
	}
}

void inicializarEstadosAlumnos(eAlumno alumno[], int tamanno)
{
	int i;

	for (i = 0; i < tamanno; i++)
	{
		alumno[i].estaVacio = -2;
	}
}


int comprobarEspacioAlumnos(int *posicionLibre, eAlumno alumno[], int tamanno)
{
	int valorRetorno;
	int posicion;

	valorRetorno = 0;
	if (verificarPosicion(-2, alumno, &posicion, tamanno) == 1)
	{
		*posicionLibre = posicion;
		valorRetorno = 1;
	}

	return valorRetorno;
}

void pedirDatosAlumno(int posicionLibre, eAlumno alumno[])
{
	char nombreAlumno[50];
	float notaIngresadaUno;
	float notaIngresadaDos;

	alumno[posicionLibre].estaVacio = 1;
	alumno[posicionLibre].legajo = posicionLibre;

	ingresarString(nombreAlumno, "Ingresa el nombre del alumno: ");
	strcpy(alumno[posicionLibre].nombre, nombreAlumno);

	ingresarFloat(&notaIngresadaUno, "Ingresa la primer nota del alumno: ", "Error, Ingresa la primer nota del alumno: ");
	alumno[posicionLibre].nota1 = notaIngresadaUno;

	ingresarFloat(&notaIngresadaDos, "Ingresa la segunda nota del alumno: ", "Error, Ingresa la segunda nota del alumno: ");
	alumno[posicionLibre].nota2 = notaIngresadaDos;

	alumno[posicionLibre].promedio = (float) (notaIngresadaUno + notaIngresadaDos) / 2;
}

void bajarEstudiante(int opcionIDIngresado, eAlumno alumno[], int tamanno)
{
	int posicion;
	if (verificarID(opcionIDIngresado, alumno, &posicion, tamanno) == 1)
	{
		alumno[posicion].estaVacio = -2;
	}
	else
	{
		printf("No hay ningun alumno con el ID especificado");
	}
}

int verificarPosicion(int numero, eAlumno alumno[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (alumno[i].estaVacio == numero)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}

	}
	return valorRetorno;
}

int verificarID(int numeroID, eAlumno alumno[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (alumno[i].legajo == numeroID)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}
	}
	return valorRetorno;
}

void imprimirAlumnos(eAlumno alumno[], int tamanno)
{
	int i;
	int comprobacion;

	comprobacion = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (alumno[i].estaVacio > 0)
		{
			printf("\n%d     %s     %d     %d     %.2f", alumno[i].legajo, alumno[i].nombre, alumno[i].nota1, alumno[i].nota2, alumno[i].promedio);
			comprobacion = 1;
		}
	}

	if (comprobacion == 0)
	{
		printf("No hay alumnos en la lista");
	}
}

void modificarNombre(int opcionIDIngresado, eAlumno alumno[], int tamanno)
{
	int posicion;
	char nombreAlumno[50];

	if (verificarID(opcionIDIngresado, alumno, &posicion, tamanno) == 1)
	{
		ingresarString(nombreAlumno, "Ingresa el nombre del alumno: ");
		strcpy(alumno[posicion].nombre, nombreAlumno);
	}
	else
	{
		printf("No hay ningun alumno con el ID especificado");
	}
}

void modificarNotaUno(int opcionIDIngresado, eAlumno alumno[], int tamanno)
{
	int posicion;
	float notaIngresada;

	if (verificarID(opcionIDIngresado, alumno, &posicion, tamanno) == 1)
	{
		ingresarFloat(&notaIngresada, "Ingresa la primer nota del alumno: ", "Error, Ingresa la primer nota del alumno: ");
		alumno[posicion].nota1 = notaIngresada;
	}
	else
	{
		printf("No hay ningun alumno con el ID especificado");
	}
}

void modificarNotaDos(int opcionIDIngresado, eAlumno alumno[], int tamanno)
{
	int posicion;
	float notaIngresada;

	if (verificarID(opcionIDIngresado, alumno, &posicion, tamanno) == 1)
	{
		ingresarFloat(&notaIngresada, "Ingresa la segunda nota del alumno: ", "Error, Ingresa la segunda nota del alumno: ");
		alumno[posicion].nota2 = notaIngresada;
	}
	else
	{
		printf("No hay ningun alumno con el ID especificado");
	}
}

void ordenarVector(eAlumno alumno[], int tamanno, int tipoDeOrdenamiento)
{
	int i;
	int j;
	eAlumno auxiliar;

	if (tipoDeOrdenamiento == 1)
	{
		for (i = 0; i < tamanno - 1; i++)
		{
			for (j = i + 1; j < tamanno; j++)
			{
				if (alumno[i].promedio > alumno[j].promedio)
				{
					auxiliar = alumno[j];
					alumno[j] = alumno[i];
					alumno[i] = auxiliar;
				}
			}
		}
	}
	else
	{
		for (i = 0; i < tamanno - 1; i++)
		{
			for (j = i + 1; j < tamanno; j++)
			{
				if (strcmp(alumno[i].nombre, alumno[j].nombre) > 0)
				{
					auxiliar = alumno[j];
					alumno[j] = alumno[i];
					alumno[i] = auxiliar;
				}
			}
		}
	}
}

void vectorOriginal(eAlumno alumno[], int tamanno)
{
	int i;
	int j;
	eAlumno auxiliar;

	for (i = 0; i < tamanno - 1; i++)
	{
		for (j = i + 1; j < tamanno; j++)
		{
			if (alumno[i].legajo > alumno[j].legajo)
			{
				auxiliar = alumno[j];
				alumno[j] = alumno[i];
				alumno[i] = auxiliar;
			}
		}
	}
}

