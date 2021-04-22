/*
 * funciones.c
 *
 *  Created on: 19 abr. 2021
 *      Author: Yesid
 */

#include "funciones.h"
#include <string.h>

void altaProducto(eProducto producto[], int tamanno)
{
	int posicionLibre;

	if (comprobarEspacio(&posicionLibre, producto, tamanno) == 1)
	{
		llenarUnProducto(posicionLibre, producto, tamanno);
	}
	else
	{
		printf("No hay mas espacio");
	}
}

void inicializarEstadoProductos(eProducto producto[], int tamanno)
{
	int i;

	for (i = 0; i < tamanno; i++)
	{
		producto[i].EstadoProducto = -2;
	}
}

int comprobarEspacio(int *posicionLibre, eProducto producto[], int tamanno)
{
	int valorRetorno;
	int posicion;

	valorRetorno = 0;
	if (verificarPosicion(-2, producto, &posicion, tamanno) == 1)
	{
		*posicionLibre = posicion;
		valorRetorno = 1;
	}

	return valorRetorno;
}

void llenarUnProducto(int posicionLibre, eProducto producto[], int tamanno)
{
	char descripcionProducto[50];
	char nacionalidadProducto[50];
	char tipoProducto[50];
	float precioProducto;

	producto[posicionLibre].EstadoProducto = 1;
	producto[posicionLibre].idProducto = posicionLibre;

	ingresarString(descripcionProducto, "Ingresa la descripcion del producto: ");
	strcpy(producto[posicionLibre].descripcion, descripcionProducto);

	ingresarString(nacionalidadProducto, "Ingresa la nacionalidad del Producto: ");
	strcpy(producto[posicionLibre].nacionalidad, nacionalidadProducto);

	ingresarString(tipoProducto, "Ingresa el tipo del producto: ");
	strcpy(producto[posicionLibre].tipo, tipoProducto);

	ingresarFloat(&precioProducto, "Ingresa el precio del producto: ", "Error, Ingresa el precio del producto: ");
	producto[posicionLibre].precio = precioProducto;
}

void bajaProducto(int opcionIDIngresado, eProducto producto[], int tamanno)
{
	int posicion;
	if (verificarID(opcionIDIngresado, producto, &posicion, tamanno) == 1)
	{
		producto[posicion].EstadoProducto = -1;
	}
	else
	{
		printf("No hay ningun producto con el ID especificado");
	}
}

int verificarPosicion(int numero, eProducto producto[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (producto[i].EstadoProducto == numero)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}

	}
	return valorRetorno;
}

int verificarID(int numeroID, eProducto producto[], int *posicion, int tamanno)
{
	int valorRetorno;
	int i;

	valorRetorno = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (producto[i].idProducto == numeroID)
		{
			valorRetorno = 1;
			*posicion = i;
			break;
		}
	}
	return valorRetorno;
}

void imprimirProductos(eProducto producto[], int tamanno)
{
	int i;
	int comprobacion;

	comprobacion = 0;

	for (i = 0; i < tamanno; i++)
	{
		if (producto[i].EstadoProducto > 0)
		{
			printf("\n%d     %s     %s     %s     %.2f", producto[i].idProducto, producto[i].descripcion, producto[i].nacionalidad, producto[i].tipo, producto[i].precio);
			comprobacion = 1;
		}
	}

	if (comprobacion == 0)
	{
		printf("No hay alumnos en la lista");
	}
}

void modificarPrecio(int opcionIDIngresado, eProducto producto[], int tamanno)
{
	int posicion;
	float precioProducto;

	if (verificarID(opcionIDIngresado, producto, &posicion, tamanno) == 1)
	{
		ingresarFloat(&precioProducto, "Ingresa el precio del producto: ", "Error, Ingresa el precio del producto: ");
		producto[posicion].precio = precioProducto;
	}
	else
	{
		printf("No hay ningun producto con el ID especificado");
	}
}

void modificarTipo(int opcionIDIngresado, eProducto producto[], int tamanno)
{
	int posicion;
	char tipoProducto[50];

	if (verificarID(opcionIDIngresado, producto, &posicion, tamanno) == 1)
	{
		ingresarString(tipoProducto, "Ingresa el tipo del producto: ");
		strcpy(producto[posicion].tipo, tipoProducto);
	}
	else
	{
		printf("No hay ningun producto con el ID especificado");
	}
}

void ordenarVector(eProducto producto[], int tamanno, int tipoDeOrdenamiento)
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
				if (producto[i].precio > producto[j].precio)
				{
					auxiliar = producto[j];
					producto[j] = producto[i];
					producto[i] = auxiliar;
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
				if (strcmp(producto[i].descripcion, producto[j].descripcion) > 0)
				{
					auxiliar = producto[j];
					producto[j] = producto[i];
					producto[i] = auxiliar;
				}
			}
		}
	}
}

void vectorOriginal(eProducto producto[], int tamanno)
{
	int i;
	int j;
	eProducto auxiliar;

	for (i = 0; i < tamanno - 1; i++)
	{
		for (j = i + 1; j < tamanno; j++)
		{
			if (producto[i].idProducto > producto[j].idProducto)
			{
				auxiliar = producto[j];
				producto[j] = producto[i];
				producto[i] = auxiliar;
			}
		}
	}

}

