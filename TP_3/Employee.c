#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include "auxFunction.h"
#include "dataValidation/charString.h"

#define FALSE 0
#define TRUE 1

int employee_getNombre(Employee *this, char *nombre)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->name);
		returnValue = TRUE;
	}

	return returnValue;
}
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->hoursWorked = horasTrabajadas;
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_setId(Employee *this, int id)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->id = id;
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_setNombre(Employee *this, char *nombre)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->name, nombre);
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_setSueldo(Employee *this, int sueldo)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		returnValue = TRUE;
		this->salary = sueldo;
	}

	return returnValue;
}

void employee_show(Employee *this)
{
	printf("%2d %15s %14d %11d\n", this->id, this->name, this->hoursWorked, this->salary);
}

Employee* employee_new()
{
	Employee *pReturn;
	pReturn = (Employee*) malloc(sizeof(Employee));
	return pReturn;
}

void employee_delete()
{

}

Employee* employee_newParametros(char *idStr, char *nombreStr, char *horasTrabajadasStr)
{
	Employee *newEmployee;
	newEmployee = employee_new();

	if (newEmployee != NULL)
	{
		newEmployee->id = atoi(idStr);
		strcpy(newEmployee->name, nombreStr);
		newEmployee->hoursWorked = atoi(horasTrabajadasStr);
	}
	return newEmployee;
}

int sortByHoursWorked(void *Employee1, void *Employee2)
{
	int returnValue;
	int hoursWorked1 = ((Employee*) Employee1)->hoursWorked;
	int hoursWorked2 = ((Employee*) Employee2)->hoursWorked;

	returnValue = 0;
	if (Employee1 != NULL && Employee2 != NULL)
	{
		if (hoursWorked1 < hoursWorked2)
		{
			swap(Employee1, Employee2);
			returnValue = 1;
		}
		else
		{
			if (hoursWorked1 < hoursWorked2)
			{
				swap(Employee1, Employee2);
				returnValue = -1;
			}
		}
	}

	return returnValue;
}

int sortBySalary(void *Employee1, void *Employee2)
{
	int returnValue;
	int salary1 = ((Employee*) Employee1)->salary;
	int salary2 = ((Employee*) Employee2)->salary;

	returnValue = 0;
	if (Employee1 != NULL && Employee2 != NULL)
	{
		if (salary1 < salary2)
		{
			swap(Employee1, Employee2);
			returnValue = 1;
		}
		else
		{
			if (salary1 < salary2)
			{
				swap(Employee1, Employee2);
				returnValue = -1;
			}
		}
	}

	return returnValue;
}

int sortById(void *Employee1, void *Employee2)
{
	int returnValue;
	int number1 = ((Employee*) Employee1)->id;
	int number2 = ((Employee*) Employee2)->id;

	returnValue = 0;
	if (Employee1 != NULL && Employee2 != NULL)
	{
		if (number1 < number2)
		{
			swap(Employee1, Employee2);
			returnValue = 1;
		}
		else
		{
			if (number1 > number2)
			{
				swap(Employee1, Employee2);
				returnValue = -1;
			}
		}
	}

	return returnValue;
}

int sortByName(void *Employee1, void *Employee2)
{
	int returnValue;
	char *name1 = ((Employee*) Employee1)->name;
	char *name2 = ((Employee*) Employee2)->name;

	returnValue = 0;
	if (Employee1 != NULL && Employee2 != NULL)
	{
		if (strcasecmp(name1, name2) < 0)
		{
			swap(Employee1, Employee2);
			returnValue = 1;
		}
		else
		{
			if (strcasecmp(name1, name2) > 0)
			{
				swap(Employee1, Employee2);
				returnValue = -1;
			}
		}
	}
	return returnValue;
}
