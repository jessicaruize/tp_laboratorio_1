#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "pedir_valores.h"
#include "Menu.h"

#define TAM_NOMBRE 128
#define TAM_OTROS 30
typedef struct
{
    int id;
    char nombre[TAM_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



int employee_compareBbyName(void* elemento1, void* elemento2);
int employee_compareBbyId(void* elemento1, void* elemento2);
int employee_compareBbyHoras(void* elemento1, void* elemento2);
int employee_compareBbySueldo(void* elemento1, void* elemento2);

int employee_set(Employee* empleado, int id, char* nombre, int horasTrabajadas, int sueldo);
int Employee_cargarDatos(Employee* empleado);
int employee_mostrarUno(Employee* empleado);
int employee_editName(Employee* empleado);
int employee_editWorkingHours(Employee* empleado);
int employee_editSalary(Employee* empleado);
int employee_saveEdit(Employee* empleado);
int employee_editEmployee(Employee* empleado);

#endif // employee_H_INCLUDED
