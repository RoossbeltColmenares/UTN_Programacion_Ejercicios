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

#include "funcionesMenuPrincipal/funcionesMenuPrincipal.h"
#define tamanno 12
#define tamannoTipo 5

int main(void)
{
	setbuf(stdout, NULL);
	eProducto vectorProducto[tamanno];
	eTipo tipo[tamannoTipo] =
	{
	{ 1000, "Iphone" },
	{ 1001, "Ipad" },
	{ 1002, "Imac" },
	{ 1003, "Accesorios" } };
	int opcionIngresada;
	int opcionIDIngresado;

	inicializarEstadoProductos(vectorProducto, tamanno);

	do
	{
		printf("\n-------------------Bienvenidos a nuestros sistema de datos--------------------");
		printf("\n1. Alta Producto");
		printf("\n2. Baja Producto");
		printf("\n3. Modificacion precio");
		printf("\n4. Listado Productos");
		printf("\n5. Listado ordenado por precio");
		printf("\n6. Listado ordenado por descripcion");
		printf("\n7. El/Los productos mas caros son:");
		printf("\n8. Precio promedio por tipo de producto:");
		printf("\n9. Salir");
		ingresarIntR(&opcionIngresada, "\nIngresa la opcion: ", "\nError, ingresa la opcion: ", 1, 9);

		switch (opcionIngresada)
		{
			case 1:
				system("cls");
				altaProducto(vectorProducto, tipo, tamanno, tamannoTipo);
				break;

			case 2:
				system("cls");
				ingresarIntR(&opcionIDIngresado, "\nIngrese el numero ID: ", "\nError, ingresa el numero ID: ", 0, tamanno);
				bajaProducto(opcionIDIngresado, vectorProducto, tamanno);
				break;

			case 3:
				system("cls");
				ingresarIntR(&opcionIDIngresado, "Ingrese 1 si quieres modificar el precio: ", "Error, Ingrese 1 si quieres modificar el precio: ", 1, 1);
				system("cls");
				ingresarInt(&opcionIDIngresado, "\nIngresa el ID a modificar: ", "\nError, Ingresa el ID a modificar: ");
				modificarPrecio(opcionIDIngresado, vectorProducto, tamanno);

				break;

			case 4:
				system("cls");
				imprimirProductos(vectorProducto, tipo, tamanno, tamannoTipo);
				break;

			case 5:
				system("cls");
				ordenarVector(vectorProducto, tamanno, 1);
				imprimirProductos(vectorProducto, tipo, tamanno, tamannoTipo);
				vectorOriginal(vectorProducto, tamanno);
				break;

			case 6:
				system("cls");
				ordenarVector(vectorProducto, tamanno, 0);
				imprimirProductos(vectorProducto, tipo, tamanno, tamannoTipo);
				vectorOriginal(vectorProducto, tamanno);
				break;

			case 7:
				system("cls");
				productoMasCaro(vectorProducto, tipo, tamanno, tamannoTipo);
				break;

			case 8:
				system("cls");
				precioPromedioPorTipo(vectorProducto, tamanno);
				break;

			case 9:
				system("cls");
				opcionIngresada = 9;
				break;
		}
	} while (opcionIngresada != 9);
}
