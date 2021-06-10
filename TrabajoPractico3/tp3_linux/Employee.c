#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
	Employee* empleado;
	empleado = (Employee*)malloc(sizeof(Employee));
	return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado;
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		empleado = (Employee*)malloc(sizeof(Employee));
		if(empleado != NULL)
		{
			(*(empleado)).id = atoi(idStr);
			strncpy((*(empleado)).nombre, nombreStr, TAM_NOMBRE);
			(*(empleado)).horasTrabajadas = atoi(horasTrabajadasStr);
			(*(empleado)).sueldo = atoi(sueldoStr);
		}
	}
	return empleado;
}


int employee_delete(Employee* this)//agregue el parametro
{
	int retorno =-1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > -1)
	{
		(*this).id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_setIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	int aux;
	if(this != NULL && id != NULL)
	{
		aux = (char)id;
		if(utn_esEntero(id, TAM_OTROS)== 1)
		{
			aux= atoi(id);
			if(aux > -1)
			{
				(*this).id = aux;
			}
		}
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = (*this).id;
		retorno = 0;
	}
	//printf("id %d", *id);
	return retorno;
}

int employee_getIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id, "%d", (*this).id);
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(utn_esAlfabetico(nombre, TAM_NOMBRE)==1)
		{
			strncpy((*this).nombre, nombre, TAM_NOMBRE);
			retorno = 0;
		}
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre, (*this).nombre, TAM_NOMBRE);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0)
	{
		(*this).horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = (*this).horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > 0)
	{
		(*this).sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = (*this).sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_compareBbyName(void* elemento1, void* elemento2)
{
	int cmp;
	Employee* empleado1;
	Employee* empleado2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleado1 = (Employee*)elemento1;
		empleado2 = (Employee*)elemento2;
		cmp = strcmp(empleado1->nombre, empleado2->nombre);
	}
	return cmp;
}

int employee_compareBbyId(void* elemento1, void* elemento2)
{
	int cmp = 0; //error
	Employee* empleado1;
	Employee* empleado2;
	int id1;
	int id2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleado1 = (Employee*)elemento1;
		empleado2 = (Employee*)elemento2;
		employee_getId(empleado1, &id1);
		employee_getId(empleado2, &id2);
		if(id1>id2)
		{
			cmp = 1; // id 1 mayor
		}
		else
		{
			if(id2>id1)
			{
				cmp = -1; //id2 mayor
			}
		}
	}
	return cmp;
}

//crear funcion mostrar empleados
