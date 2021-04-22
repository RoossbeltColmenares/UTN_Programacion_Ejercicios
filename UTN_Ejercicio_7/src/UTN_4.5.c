/*
 * Yesid Colmenares
 * ESTRUCTURAS
 Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
 idProducto (numerico)
 descripcion (alfanumérico)
 nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
 precio (numérico decimal)
 Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
 ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
 BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
 MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
 LISTADO Productos.
 LISTADO ordenado por precio.
 LISTADO ordenado por descripción.
 */

#include "funcionesEjercicio7/funciones.h"
#define tamanno 12

int main(void)
{
	setbuf(stdout, NULL);
	eProducto producto[12];
	int opcionIngresada;
	int opcionIDIngresado;

	inicializarEstadoProductos(producto, tamanno);
	do
	{
		printf("\n-------------------Bienvenidos a nuestros sistema de datos--------------------");
		printf("\n1. Alta Producto");
		printf("\n2. Baja Producto");
		printf("\n3. Modificacion precio o tipo del Producto");
		printf("\n4. Listado Productos");
		printf("\n5. Listado ordenado por precio");
		printf("\n6. Listado ordenado por descripcion");
		printf("\n7. Salir");
		ingresarIntR(&opcionIngresada, "\nIngresa la opcion: ", "\nError, ingresa la opcion: ", 1, 7);

		switch (opcionIngresada)
		{
			case 1:
				system("cls");
				altaProducto(producto, tamanno);
				break;

			case 2:
				system("cls");
				ingresarIntR(&opcionIDIngresado, "\nIngrese el numero ID: ", "\nError, ingresa el numero ID: ", 0, tamanno);
				bajaProducto(opcionIDIngresado, producto, tamanno);
				break;

			case 3:
				system("cls");
				ingresarIntR(&opcionIDIngresado, "Ingrese 1 si quieres modificar el precio, \n ingrese 2 si quieres modificar el tipo de producto: ",
						"Error, Ingrese 1 si quieres modificar el precio, \n ingrese 2 si quieres modificar el tipo de producto: ", 1, 2);
				if (opcionIDIngresado == 1)
				{
					system("cls");
					ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
					modificarPrecio(opcionIDIngresado, producto, tamanno);
				}
				else
				{
					system("cls");
					ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
					modificarTipo(opcionIDIngresado, producto, tamanno);
				}
				break;

			case 4:
				system("cls");
				imprimirProductos(producto, tamanno);
				break;

			case 5:
				system("cls");
				ordenarVector(producto, tamanno, 1);
				imprimirProductos(producto, tamanno);
				vectorOriginal(producto, tamanno);
				break;

			case 6:
				system("cls");
				ordenarVector(producto, tamanno, 0);
				imprimirProductos(producto, tamanno);
				vectorOriginal(producto, tamanno);
				break;

			case 7:
				system("cls");
				opcionIngresada = 7;
				break;
		}
	} while (opcionIngresada != 7);
}
