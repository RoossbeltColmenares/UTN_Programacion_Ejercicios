/*
 * funciones.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "funcionesMenuPrincipal.h"

#include <string.h>

void altaProducto(eProducto vectorProductos[], eTipo tipo[], int tamanno, int tamannoTipo)
{
	int posicionLibre;

	if (comprobarEspacio(&posicionLibre, vectorProductos, tamanno) == 1)
	{
		llenarUnProducto(posicionLibre, tipo, vectorProductos, tamannoTipo);
	}
	else
	{
		printf("No hay mas espacio");
	}
}

void inicializarEstadoProductos(eProducto vectorProductos[], int tamanno)
{
	int i;

	for (i = 0; i < tamanno; i++)
	{
		vectorProductos[i].EstadoProducto = -2;
	}
}

int comprobarEspacio(int *posicionLibre, eProducto vectorProductos[], int tamanno)
{
	int valorRetorno;
	int posicion;

	valorRetorno = 0;
	if (verificarPosicion(-2, vectorProductos, &posicion, tamanno) == 1)
	{
		*posicionLibre = posicion;
		valorRetorno = 1;
	}

	return valorRetorno;
}

void llenarUnProducto(int posicionLibre, eTipo tipo[], eProducto vectorProductos[], int tamannoTipo)
{
	char descripcionProducto[50];
	char nacionalidadProducto[50];
	float precioProducto;
	int opcionIngresada;

	vectorProductos[posicionLibre].EstadoProducto = 1;
	vectorProductos[posicionLibre].idVectorProducto = posicionLibre;

	ingresarString(descripcionProducto, "Ingresa la descripcion del producto: ");
	strcpy(vectorProductos[posicionLibre].descripcion, descripcionProducto);

	ingresarString(nacionalidadProducto, "Ingresa la nacionalidad del Producto: ");
	strcpy(vectorProductos[posicionLibre].nacionalidad, nacionalidadProducto);

	imprimirTipoProductos(tipo, tamannoTipo);
	ingresarIntR(&opcionIngresada, "\nIngresa el Id del tipo de producto: ", "Error, ingresa el Id del tipo de producto: ", 1000,1003);
	vectorProductos[posicionLibre].idTipoProducto = opcionIngresada;

	ingresarFloat(&precioProducto, "Ingresa el precio del producto: ", "Error, Ingresa el precio del producto: ");
	vectorProductos[posicionLibre].precio = precioProducto;
}

void bajaProducto(int opcionIDIngresado, eProducto vectorProductos[], int tamanno)
{
	int posicion;
	if (verificarID(opcionIDIngresado, vectorProductos, &posicion, tamanno) == 1)
	{
		vectorProductos[posicion].EstadoProducto = -2;
	}
	else
	{
		printf("No hay ningun producto con el ID especificado");
	}
}

int verificarPosicion(int numero, eProducto vectorProductos[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (vectorProductos[i].EstadoProducto == numero)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}

	}
	return valorRetorno;
}

int verificarID(int numeroID, eProducto vectorProductos[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (vectorProductos[i].idVectorProducto == numeroID)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}
	}
	return valorRetorno;
}

void imprimirProductos(eProducto vectorProductos[], eTipo tipo[], int tamanno, int tamannoTipo)
{
	int i;
	int j;
	int comprobacion;

	comprobacion = 0;

	for (i = 0; i < tamannoTipo; i++)
	{
		printf("\n%d      %s", tipo[i].idTipoProducto, tipo[i].nombreTipo);
		for (j = 0; j < tamanno; j++)
		{
			if (vectorProductos[j].EstadoProducto > 0)
			{
				if (vectorProductos[j].idTipoProducto == tipo[i].idTipoProducto)
				{
					printf("\n%d     %s     %s      %.2f", vectorProductos[j].idVectorProducto, vectorProductos[j].descripcion, vectorProductos[j].nacionalidad, vectorProductos[j].precio);
					comprobacion = 1;
				}
			}
		}
	}

	if (comprobacion == 0)
	{
		printf("No hay alumnos en la lista");
	}
}

void modificarPrecio(int opcionIDIngresado, eProducto vectorProductos[], int tamanno)
{
	int posicion;
	float precioProducto;

	if (verificarID(opcionIDIngresado, vectorProductos, &posicion, tamanno) == 1)
	{
		ingresarFloat(&precioProducto, "Ingresa el precio del producto: ", "Error, Ingresa el precio del producto: ");
		vectorProductos[posicion].precio = precioProducto;
	}
	else
	{
		printf("No hay ningun producto con el ID especificado");
	}
}

void ordenarVector(eProducto vectorProductos[], int tamanno, int tipoDeOrdenamiento)
{
	int i;
	int j;
	eProducto auxiliar;

	if (tipoDeOrdenamiento == 1)
	{
		for (i = 0; i < tamanno - 1; i++)
		{
			for (j = i + 1; j < tamanno; j++)
			{
				if (vectorProductos[i].precio > vectorProductos[j].precio)
				{
					auxiliar = vectorProductos[j];
					vectorProductos[j] = vectorProductos[i];
					vectorProductos[i] = auxiliar;
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
				if (strcmp(vectorProductos[i].descripcion, vectorProductos[j].descripcion) > 0)
				{
					auxiliar = vectorProductos[j];
					vectorProductos[j] = vectorProductos[i];
					vectorProductos[i] = auxiliar;
				}
			}
		}
	}
}

void vectorOriginal(eProducto vectorProductos[], int tamanno)
{
	int i;
	int j;
	eProducto auxiliar;

	for (i = 0; i < tamanno - 1; i++)
	{
		for (j = i + 1; j < tamanno; j++)
		{
			if (vectorProductos[i].idVectorProducto > vectorProductos[j].idVectorProducto)
			{
				auxiliar = vectorProductos[j];
				vectorProductos[j] = vectorProductos[i];
				vectorProductos[i] = auxiliar;
			}
		}
	}
}

void productoMasCaro(eProducto vectorProductos[], eTipo tipo[], int tamanno, int tamannoTipo)
{
	int i;
	int j;
	int l;
	eProducto auxiliarProductoMasCaro[tamanno];

//Inicializo con el primer valor de productos
	inicializarEstadoProductos(auxiliarProductoMasCaro, tamanno);
	auxiliarProductoMasCaro[0] = vectorProductos[0];
	auxiliarProductoMasCaro[0].EstadoProducto = 1;

	j = 0;
	l = 0;

//Encuentro el valor mas grande de todos los productos
	for (i = 1; i < tamanno; i++)
	{
		if (auxiliarProductoMasCaro[0].precio < vectorProductos[i].precio && vectorProductos[i].EstadoProducto == 1)
		{
			auxiliarProductoMasCaro[0] = vectorProductos[i];
			auxiliarProductoMasCaro[0].EstadoProducto = 1;
			l++;
		}
	}

//Ahora encuentro si hay mas productos con ese precio mayor encontrado para tambien guardarlo
	for (i = l; i < tamanno; i++)
	{
		if (auxiliarProductoMasCaro[0].precio == vectorProductos[i].precio && vectorProductos[i].EstadoProducto == 1)
		{
			auxiliarProductoMasCaro[j] = vectorProductos[i];
			auxiliarProductoMasCaro[j].EstadoProducto = 1;
			j++;
		}
	}

	imprimirProductos(auxiliarProductoMasCaro, tipo, tamanno, tamannoTipo);
}

void precioPromedioPorTipo(eProducto vectorProductos[], int tamanno)
{
	int i;

	for (i = 0; i < tamanno; i++)
	{

	}
}

