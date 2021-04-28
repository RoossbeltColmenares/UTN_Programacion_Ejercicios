/*
 * funciones.h
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#include "../IngresoDeDatos/ingresarDatos.h"

typedef struct
{
	int estaVacio;
	int idCurso;
	char descripcion[50];
	float duracion;
} eCurso;

#ifndef FUNCIONESMENUBASEDATOSCURSO_FUNCIONESSTRUCTECURSO_H_
#define FUNCIONESMENUBASEDATOSCURSO_FUNCIONESSTRUCTECURSO_H_

void inicializarEstadosCursos(eCurso curso[], int tamanno);

void altaCurso(eCurso curso[], int tamanno);

int verificarPosicionCurso(int numero, eCurso curso[], int *posicion, int tamanno);

void pedirDatosCurso(int posicionLibre, eCurso curso[], int tamanno);

int comprobarEspacioCursos(int *posicionLibre, eCurso curso[], int tamanno);

void bajarCurso(int opcionIDIngresado, eCurso curso[], int tamanno);

void modificarNombreCurso(int opcionIDIngresado, eCurso curso[], int tamanno);

void modificarDuracionCurso(int opcionIDIngresado, eCurso curso[], int tamanno);

void ordenarVectorCurso(eCurso curso[], int tamanno, int ordenDeOrdenamiento);

void vectorOriginalCurso(eCurso curso[], int tamanno);

int verificarIDCurso(int numeroID, eCurso curso[], int *posicion, int tamanno);

void imprimirCursos(eCurso curso[], int tamannoCurso);

#endif /* FUNCIONESMENUBASEDATOSCURSO_FUNCIONESSTRUCTECURSO_H_ */
