/*
 * funciones.h
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#include "../IngresoDeDatos/ingresarDatos.h"
#include "../funcionesMenuBaseDatosCurso/funcionesStructECurso.h"

#ifndef FUNCIONESMENUPRINCIPAL_FUNCIONESSTRUCTEALUMNO_H_
#define FUNCIONESMENUPRINCIPAL_FUNCIONESSTRUCTEALUMNO_H_

typedef struct
{
	int estaVacio;
	int legajo;
	int nota1;
	int nota2;
	float promedio;
	char nombre[25];
	int idCurso;
} eAlumno;

void inicializarEstadosAlumnos(eAlumno alumno[], int tamanno);

void altaEstudiantes(eAlumno alumno[], eCurso curso[], int tamannoAlumno, int tamnanoCurso);

void imprimirAlumnos(eAlumno alumno[], eCurso curso[], int tamannoAlumno, int tamannoCurso);

void imprimirAlumnosCurso(eAlumno alumno[], eCurso curso[], int tamannoAlumno, int tamannoCurso);

int verificarPosicion(int numeroID, eAlumno alumno[], int *posicion, int tamanno);

void pedirDatosAlumno(int posicionLibre, eAlumno alumno[], eCurso curso[], int tamannoCurso);

int comprobarEspacioAlumnos(int *posicionLibre, eAlumno alumno[], int tamanno);

void bajarEstudiante(int opcionIDIngresado, eAlumno alumno[], int tamanno);

void modificarNombre(int opcionIDIngresado, eAlumno alumno[], int tamanno);

void modificarNotaUno(int opcionIDIngresado, eAlumno alumno[], int tamanno);

void modificarNotaDos(int opcionIDIngresado, eAlumno alumno[], int tamanno);

void ordenarVector(eAlumno alumno[], int tamanno, int ordenDeOrdenamiento);

void vectorOriginal(eAlumno alumno[], int tamanno);

int verificarID(int numeroID, eAlumno alumno[], int *posicion, int tamanno);

#endif /* FUNCIONESMENUPRINCIPAL_FUNCIONESSTRUCTEALUMNO_H_ */
