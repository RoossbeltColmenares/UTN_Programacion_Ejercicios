/*
 * auxFunction.h
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */

#ifndef AUXFUNCTION_H_
#define AUXFUNCTION_H_
#include "LinkedList.h"
#include "Employee.h"

void printMainMenu(void);

void printSortingMenu(void);

void printEditMenu(Employee *this);

int swap(Employee *Employee1, Employee *Employee2);

int saveEmployees(FILE *file, LinkedList *pArrayListEmployee);

#endif /* AUXFUNCTION_H_ */
