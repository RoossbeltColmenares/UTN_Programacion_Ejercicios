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

#include "../nexo/nexo.h"

int main(void)
{
	setbuf(stdout, NULL);
	eProduct listP[SIZE_P];
	eAuxiliary auxiliary[SIZE_A];

	eType listT[SIZE_T] =
	{
	{ 1000, "IPHONE" },
	{ 1001, "IPAD" },
	{ 1002, "IMAC" },
	{ 1003, "ACCESSORIES" } };

	eNationality listN[SIZE_N] =
	{
	{ 1, "EEUU" },
	{ 2, "CHINA" },
	{ 3, "OTRO" } };

	int optionEntered;
	int returnValue;
	int returnValueId;
	int WhileCondition;

	initializeStatusProduct(listP, SIZE_P);
	do
	{
		initializeStatusAuxiliary(auxiliary, SIZE_A);
		printf("\n-------------------WELCOM TO OUR DATA SYSTEM--------------------");
		printf("\n1. Add");
		printf("\n2. Remove");
		printf("\n3. Modification");
		printf("\n4. Products list");
		printf("\n5. List organized by price");
		printf("\n6. List organized by description");
		printf("\n7. The most expensive products");
		printf("\n8. Average price by product type");
		printf("\n9. Products list with type description");
		printf("\n10. Products list by type");
		printf("\n11. The types of products with most products manufactured");
		printf("\n12. Exit");

		inputIntR(&optionEntered, "\nEnter option: ", "\nError, enter option: ", 1, 12);
		switch (optionEntered)
		{
			case 1:
				system("cls");
				if (addProduct(listP, SIZE_P, listT, SIZE_T, listN, SIZE_N) == TRUE)
				{

					system("cls");
					printf("! DATA UPLOADED SUCCESSFULLY !\n");
				}
				else
				{
					system("cls");
					printf("! There is no space available to store more products !\n");
				}
				break;

			case 2:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printProducts(listP, SIZE_P, listT, listN, auxiliary);
					inputInt(&returnValue, "\nEnter the ID to unsubscribe: ", "\nError, enter the ID to unsubscribe: ");

					if (removeProduct(listP, SIZE_P, returnValue) == TRUE)
					{
						system("cls");
						printf("! DATA ELIMINATED SUCCESSFULLY !\n");
					}
					else
					{
						system("cls");
						printf("! The specified ID does not exist !\n");
					}
				}
				else
				{
					printf("\n! There are no products in the database !\n");
				}
				break;

			case 3:
				system("cls");
				inputIntR(&returnValue, "Enter 1 to modify the price,\nEnter 2 to modify the type: ", "Error, enter 1 to modify the price,\nError, Enter 2 to modify the type: ", 1, 2);

				switch (returnValue)
				{
					case 1:
						if (thereAreProducts(listP, SIZE_P) == FALSE)
						{
							printProducts(listP, SIZE_P, listT, listN, auxiliary);
							inputInt(&returnValueId, "\nEnter the ID to modify: ", "\nError, enter the ID to modify: ");

							if (modificationProduct(listP, SIZE_P, listT, SIZE_T, returnValueId, returnValue) == TRUE)
							{
								system("cls");
								printf("! SUCCESSFULLY UPDATED !\n");
							}
							else
							{
								system("cls");
								printf("! The specified ID does not exist !\n");
							}
						}
						else
						{
							printf("\n! There are no products in the database !\n");
						}
						break;

					case 2:
						if (thereAreProducts(listP, SIZE_P) == TRUE)
						{
							printProducts(listP, SIZE_P, listT, listN, auxiliary);
							inputInt(&returnValueId, "\nEnter the ID to modify: ", "\nError, enter the ID to modify: ");

							if (modificationProduct(listP, SIZE_P, listT, SIZE_T, returnValueId, returnValue) == TRUE)
							{
								system("cls");
								printf("! MODIFICATED SUCCESSFULLY !\n");
							}
							else
							{
								system("cls");
								printf("! The specified ID does not exist !\n");
							}
						}
						else
						{
							printf("\n! There are no products in the database !\n");
						}
						break;
				}
				break;

			case 4:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printf(" PRODUCTS LIST\n");
					printProducts(listP, SIZE_P, listT, listN, auxiliary);
				}
				else
				{
					printf("\n! There are no products in the database !\n");
				}
				break;

			case 5:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printf(" LIST ORGANIZED BY PRICE\n");
					priceLowToHighProduct(listP, SIZE_P);
					printProducts(listP, SIZE_P, listT, listN, auxiliary);
					originalOrderProducts(listP, SIZE_P);
				}
				else
				{
					printf("\n! There are no products in the database !\n");
				}
				break;

			case 6:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printf(" LIST ORGANIZED BY DESCRIPTION\n");
					sortByDescriptionProduct(listP, SIZE_P);
					printProducts(listP, SIZE_P, listT, listN, auxiliary);
					originalOrderProducts(listP, SIZE_P);
				}
				else
				{
					printf("\n! There are no products in the database !\n");
				}
				break;

			case 7:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printf(" THE MOST EXPENSIVE PRODUCTS\n");
					int sizeMostExpensiveProducts;
					mostExpensiveProducts(listP, SIZE_P, auxiliary, &sizeMostExpensiveProducts);
					printMostExpensiveProducts(listP, listT, listN, auxiliary, sizeMostExpensiveProducts);
				}
				else
				{
					printf("! There are no products in the database !\n");
				}
				break;

			case 8:
				system("cls");
				if (averagePriceByTypes(listP, SIZE_P, listT, SIZE_T, listN, SIZE_N, auxiliary, SIZE_A) == FALSE)
				{
					printf("! There are no products in the database !\n");
				}
				break;

			case 9:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printf(" PRODUCTS LIST WITH TYPE DESCRIPTION\n");
					printProductsWithDescription(listP, SIZE_P, listT, listN, auxiliary);
				}
				else
				{
					printf("\n! There are no products in the database !\n");
				}
				break;

			case 10:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					printf(" PRODUCT LIST BY TYPE");
					printProductsByType(listP, SIZE_P, listT, SIZE_T, listN, auxiliary);
				}
				else
				{
					printf("\n\n! There are no products in the database !\n");
				}
				break;

			case 11:
				system("cls");
				if (thereAreProducts(listP, SIZE_P) == TRUE)
				{
					moreElaborateTypes(listP, SIZE_P, listT, SIZE_T, auxiliary, SIZE_A);
				}
				else
				{
					printf("! There are no products in the database !\n");
				}
				break;

			case 12:
				system("cls");
				WhileCondition = 12;
				break;
		}
	} while (WhileCondition != 12);
}
