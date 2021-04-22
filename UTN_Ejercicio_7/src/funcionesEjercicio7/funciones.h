/*
 * funciones.h
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#include "../IngresoDeDatos/ingresarDatos.h"

typedef struct // Campos o Atributos
{
    int EstadoProducto;
	int idProducto;
	char descripcion[50];
	char nacionalidad[50];
	char tipo[50];
	float precio;
} eProducto; // Tipo de dato

#ifndef FUNCIONESEJERCICIO7_FUNCIONES_H_
#define FUNCIONESEJERCICIO7_FUNCIONES_H_

void inicializarEstadoProductos(eProducto producto[], int tamanno);

void altaProducto(eProducto producto[], int tamanno);

void imprimirProductos(eProducto producto[], int tamanno);

int verificarPosicion(int numeroID, eProducto producto[], int *posicion, int tamanno);

void llenarUnProducto(int posicionLibre, eProducto producto[], int tamanno);

int comprobarEspacio(int *posicionLibre, eProducto producto[], int tamanno);

void bajaProducto(int opcionIDIngresado, eProducto producto[], int tamanno);

void modificarPrecio(int opcionIDIngresado, eProducto producto[], int tamanno);

void modificarTipo(int opcionIDIngresado, eProducto producto[], int tamanno);

void ordenarVector(eProducto producto[], int tamanno, int ordenDeOrdenamiento);

void vectorOriginal(eProducto producto[], int tamanno);

int verificarID(int numeroID, eProducto producto[], int *posicion, int tamanno);
#endif /* FUNCIONESEJERCICIO7_FUNCIONES_H_ */
