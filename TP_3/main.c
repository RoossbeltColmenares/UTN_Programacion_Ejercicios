#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "auxFunction.h"
#include "dataEntry/input.h"
#define SIZEPATH 50

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main()
{
	int whileCondition;
	int optionMenu;
	char path[SIZEPATH];
	setbuf(stdout, NULL);

	LinkedList *pArrayListEmployee = ll_newLinkedList();

	do
	{
		printMainMenu();
		inputIntR(&optionMenu, "\nEnter option: ", "\nError, enter option: ", 1, 10);
		switch (optionMenu)
		{
			case 1:
				system("cls");
				inputString(path, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
				if (controller_loadFromText(path, pArrayListEmployee))
				{
					system("cls");
					printf("%s file uploaded successfully", path);
				}
				else
				{
					system("cls");
					printf("! Error loading %s file !", path);
				}
				break;

			case 2:
				system("cls");
				inputString(path, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
				if (controller_loadFromBinary(path, pArrayListEmployee))
				{
					system("cls");
					printf("%s file uploaded successfully", path);
				}
				else
				{
					system("cls");
					printf("! Error loading %s file !", path);
				}
				break;

			case 3:
				system("cls");
				if (controller_addEmployee(pArrayListEmployee))
				{
					system("cls");
					printf("Successfully registered employee");
				}
				else
				{
					system("cls");
					printf("! Error registering employee or the Linked List is NULL ! ");
				}
				break;

			case 4:
				system("cls");
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (controller_editEmployee(pArrayListEmployee))
					{
						system("cls");
						printf("Employee successfully modified");
					}
					else
					{
						system("cls");
						printf("! Error modifying employee or the Linked List is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 5:
				system("cls");
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (controller_removeEmployee(pArrayListEmployee))
					{
						printf("Employee removed successfully");
					}
					else
					{
						system("cls");
						printf("! Error, employee ID does not exist or the Linked List is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 6:
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (!controller_ListEmployee(pArrayListEmployee))
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 7:
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (!controller_sortEmployee(pArrayListEmployee))
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 8:
				system("cls");
				if (!ll_isEmpty(pArrayListEmployee))
				{
					inputString(path, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
					if (controller_saveAsText(path, pArrayListEmployee))
					{
						system("cls");
						printf("\nSuccessfully saved");

					}
					else
					{
						system("cls");
						printf("\nError saving file");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 9:
				system("cls");
				if (!ll_isEmpty(pArrayListEmployee))
				{
					inputString(path, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
					if (controller_saveAsBinary(path, pArrayListEmployee))
					{
						system("cls");
						printf("\nSuccessfully saved");
					}
					else
					{
						system("cls");
						printf("\nError saving file");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;
			case 10:
				system("cls");
				whileCondition = 10;
				break;
		}
	} while (whileCondition != 10);
	return 0;
}

