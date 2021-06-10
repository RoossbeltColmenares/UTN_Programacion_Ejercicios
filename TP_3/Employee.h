#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "stdio.h"
typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}Employee;

Employee* employee_new();//OKKKKKKKKKKK
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);//OKKKKKKKKKKK
void employee_delete();
void employee_show(Employee *this); //OKKKKKKKKKKK

int employee_setId(Employee* this,int id);//OKKKKKKKKKKK
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);//OKKKKKKKKKKK
int employee_getNombre(Employee* this,char* nombre);//OKKKKKKKKKKK

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);//OKKKKKKKKKKK
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);//OKKKKKKKKKKK
int employee_getSueldo(Employee* this,int* sueldo);

int sortByName(void *Employee1, void *Employee2);
int sortById(void *Employee1, void *Employee2);
int sortBySalary(void *Employee1, void *Employee2);
int sortByHoursWorked(void *Employee1, void *Employee2);

#endif // employee_H_INCLUDED
