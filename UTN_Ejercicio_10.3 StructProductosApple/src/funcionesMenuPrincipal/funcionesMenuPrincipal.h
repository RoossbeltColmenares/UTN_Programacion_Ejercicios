/*
 * funciones.h
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#include "../IngresoDeDatos/ingresarDatos.h"
#include "../funcionesTipoProducto/funcionesTipoProducto.h"

typedef struct // Campos o Atributos
{
    int EstadoProducto;
	int idVectorProducto;
	int idTipoProducto;
	char descripcion[50];
	char nacionalidad[50];
	float precio;
} eProducto; // Tipo de dato


#ifndef FUNCIONESMENUPRINCIPAL_FUNCIONESMENUPRINCIPAL_H_
#define FUNCIONESMENUPRINCIPAL_FUNCIONESMENUPRINCIPAL_H_

void inicializarEstadoProductos(eProducto vectorProductos[], int tamanno);

void altaProducto(eProducto vectorProductos[], eTipo tipo[], int tamanno, int tamannoTipo);

void imprimirProductos(eProducto vectorProductos[], eTipo tipo[], int tamanno, int tamannoTipo);

int verificarPosicion(int numeroID, eProducto vectorProductos[], int *posicion, int tamanno);

void llenarUnProducto(int posicionLibre, eTipo tipo[], eProducto vectorProductos[], int tamannoTipo);

int comprobarEspacio(int *posicionLibre, eProducto vectorProductos[], int tamanno);

void bajaProducto(int opcionIDIngresado, eProducto vectorProductos[], int tamanno);

void modificarPrecio(int opcionIDIngresado, eProducto vectorProductos[], int tamanno);

void ordenarVector(eProducto vectorProductos[], int tamanno, int ordenDeOrdenamiento);

void vectorOriginal(eProducto vectorProductos[], int tamanno);

int verificarID(int numeroID, eProducto vectorProductos[], int *posicion, int tamanno);

void productoMasCaro(eProducto vectorProductos[], eTipo tipo[], int tamanno, int tamannoTipo);

void precioPromedioPorTipo(eProducto vectorProductos[], int tamanno);
#endif /* FUNCIONESMENUPRINCIPAL_FUNCIONESMENUPRINCIPAL_H_ */
