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
	int idTipoProducto;
	char nombreTipo[50];
} eTipo;

#ifndef FUNCIONESTIPOPRODUCTO_FUNCIONESTIPOPRODUCTO_H_
#define FUNCIONESTIPOPRODUCTO_FUNCIONESTIPOPRODUCTO_H_

void imprimirTipoProductos(eTipo tipo[], int tamannoTipo);

#endif /* FUNCIONESTIPOPRODUCTO_FUNCIONESTIPOPRODUCTO_H_ */
