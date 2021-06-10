/*
 * auxFunction.c
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxFunction.h"
#include "Employee.h"
#include "dataValidation/charString.h"

#define TRUE 1
#define FALSE 0

int swap(Employee *Employee1, Employee *Employee2)
{
	int returnValue;
	Employee *Employee;

	returnValue = FALSE;
	if (Employee1 != NULL && Employee2 != NULL)
	{
		Employee = Employee1;
		Employee1 = Employee2;
		Employee2 = Employee;
		returnValue = TRUE;
	}
	return returnValue;
}

int saveEmployees(FILE *file, LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	Employee *newEmployee;

	if (pArrayListEmployee != NULL)
	{
		fprintf(file, "id,name,hrsWorked,salary\n");

		for (i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			newEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fprintf(file, "%d,%s,%d,%d\n", newEmployee->id, newEmployee->name, newEmployee->hoursWorked, newEmployee->salary);
		}
	}
	return returnValue;
}

void printMainMenu()
{
	printf("\n------------------ WELCOME TO THE SYSTEM ------------------");
	printf("\n1. Load employee data from data.csv file (text mode)");
	printf("\n2. Load employee data from data.csv file (binary mode)");
	printf("\n3. Employee registration");
	printf("\n4. Modify employee data");
	printf("\n5. Employee retirement");
	printf("\n6. List employees");
	printf("\n7. Sort employees");
	printf("\n8. Save employee data in data.csv file (text mode)");
	printf("\n9. Save employee data to data.csv file (binary mode)");
	printf("\n10. Exit");
}

void printSortingMenu()
{
	printf("\n--------------------- PRINT EMPLOYEES ---------------------");
	printf("\n1. Sort by name");
	printf("\n2. Sort by hours worked ");
	printf("\n3. Sort by salary");
	printf("\n4. Exit");
}

void printEditMenu(Employee *this)
{
	printf("ID            NAME      HRSWORKED      SALARY");
	employee_show(this);
	printf("\n-----------------------------------------------------------");
	printf("\n---------------------- EDIT EMPLOYEES ---------------------");
	printf("\n1. Name");
	printf("\n2. Hours Worked");
	printf("\n3. Salary");
	printf("\n4. Exit");
}
