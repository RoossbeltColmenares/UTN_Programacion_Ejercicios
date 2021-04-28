/*
 * funciones.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "funcionesStructECurso.h"

#include <string.h>

void inicializarEstadosCursos(eCurso curso[], int tamanno)
{
	int i;

	for (i = 0; i < tamanno; i++)
	{
		curso[i].estaVacio = -2;
	}
}

void altaCurso(eCurso curso[], int tamanno)
{
	int posicionLibre;

	if (comprobarEspacioCursos(&posicionLibre, curso, tamanno) == 1)
	{
		pedirDatosCurso(posicionLibre, curso, tamanno);
	}
	else
	{
		printf("No hay mas espacio, por favor agregue mas cupos o elimine un curso/n");
	}
}

int verificarPosicionCurso(int numero, eCurso curso[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (curso[i].estaVacio == numero)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}

	}
	return valorRetorno;
}

void pedirDatosCurso(int posicionLibre, eCurso curso[], int tamanno)
{
	char nombreCurso[tamanno];
	float duracionCarrera;

	curso[posicionLibre].estaVacio = 1;
	curso[posicionLibre].idCurso = posicionLibre;

	ingresarString(nombreCurso, "Ingresa el nombre del curso: ");
	strcpy(curso[posicionLibre].descripcion, nombreCurso);

	ingresarFloat(&duracionCarrera, "Ingresa la duracion de la carrera: ", "Error, Ingresa la duracion de la carrera: ");
	curso[posicionLibre].duracion = duracionCarrera;
}

int comprobarEspacioCursos(int *posicionLibre, eCurso curso[], int tamanno)
{
	int valorRetorno;
	int posicion;

	valorRetorno = 0;
	if (verificarPosicionCurso(-2, curso, &posicion, tamanno) == 1)
	{
		*posicionLibre = posicion;
		valorRetorno = 1;
	}

	return valorRetorno;
}

void bajarCurso(int opcionIDIngresado, eCurso curso[], int tamanno)
{
	int posicion;
	if (verificarIDCurso(opcionIDIngresado, curso, &posicion, tamanno) == 1)
	{
		curso[posicion].estaVacio = -2;
	}
	else
	{
		printf("No hay ningun curso con el ID especificado");
	}
}

void modificarNombreCurso(int opcionIDIngresado, eCurso curso[], int tamanno)
{
	int posicion;
	char descripcion[50];

	if (verificarIDCurso(opcionIDIngresado, curso, &posicion, tamanno) == 1)
	{
		ingresarString(descripcion, "Ingresa el nombre de la materia: ");
		strcpy(curso[posicion].descripcion, descripcion);
	}
	else
	{
		printf("No hay ningun curso con el ID especificado");
	}
}

void modificarDuracionCurso(int opcionIDIngresado, eCurso curso[], int tamanno)
{
	int posicion;
	float duracionCarreraIngresada;

	if (verificarIDCurso(opcionIDIngresado, curso, &posicion, tamanno) == 1)
	{
		ingresarFloat(&duracionCarreraIngresada, "Ingresa la duracion del curso: ", "Error, Ingresa la duracion del curso: ");
		curso[posicion].duracion = duracionCarreraIngresada;
	}
	else
	{
		printf("No hay ningun curso con el ID especificado");
	}
}

void ordenarVectorCurso(eCurso curso[], int tamanno, int tipoDeOrdenamiento)
{
	int i;
	int j;
	eCurso auxiliar;

	if (tipoDeOrdenamiento == 1)
	{
		for (i = 0; i < tamanno - 1; i++)
		{
			for (j = i + 1; j < tamanno; j++)
			{
				if (curso[i].duracion > curso[j].duracion)
				{
					auxiliar = curso[j];
					curso[j] = curso[i];
					curso[i] = auxiliar;
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
				if (strcmp(curso[i].descripcion, curso[j].descripcion) > 0)
				{
					auxiliar = curso[j];
					curso[j] = curso[i];
					curso[i] = auxiliar;
				}
			}
		}
	}
}

void vectorOriginalCurso(eCurso curso[], int tamanno)
{
	int i;
	int j;
	eCurso auxiliar;

	for (i = 0; i < tamanno - 1; i++)
	{
		for (j = i + 1; j < tamanno; j++)
		{
			if (curso[i].idCurso > curso[j].idCurso)
			{
				auxiliar = curso[j];
				curso[j] = curso[i];
				curso[i] = auxiliar;
			}
		}
	}
}

int verificarIDCurso(int numeroID, eCurso curso[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (curso[i].idCurso == numeroID)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}
	}
	return valorRetorno;
}

void imprimirCursos(eCurso curso[], int tamannoCurso)
{
	int i;
	int comprobacion;

	comprobacion = 0;

	for (i = 0; i < tamannoCurso; i++)
	{
		if (curso[i].estaVacio > 0)
		{
			printf("\n%d     %s     %f", curso[i].idCurso, curso[i].descripcion, curso[i].duracion);
			comprobacion = 1;
		}
	}

	if (comprobacion == 0)
	{
		printf("No hay cursos, puede agregar cursos en la opcion 1");
	}
}

