/*
 * funciones.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "../funcionesMenuPrincipal/funcionesMenuPrincipal.h"

void imprimirTipoProductos(eTipo tipo[], int tamannoTipo)
{
	int i;

	for (i = 0; i < tamannoTipo; i++)
	{
		printf("\n%d     %s", tipo[i].idTipoProducto, tipo[i].nombreTipo);
	}
}
