#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char id[TAM_OTROS];
	char nombre[TAM_NOMBRE];
	char horasTrabajadas[TAM_OTROS];
	char sueldo[TAM_OTROS];
	char aux[300];
	Employee* empleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%s\n",aux);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo)==4)
			{
				empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(empleado != NULL)
				{
					if(!ll_add(pArrayListEmployee, empleado))//usar get-----------------------------------------------------------------------------------
					{
						retorno=0;
						printf("%d,%s,%d,%d\n", (*empleado).id, (*empleado).nombre, (*empleado).horasTrabajadas, (*empleado).sueldo);
					}
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error
	Employee* empleado;
	int cantidad;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		fread(empleado, sizeof(Employee), cantidad, pFile);
		if(!ll_add(pArrayListEmployee, empleado))//usar get--------------------------------------------------------------------------------------------
		{
			retorno = 0;
			printf("%d,%s,%d,%d\n", (*(empleado)).id, (*(empleado)).nombre, (*(empleado)).horasTrabajadas, (*(empleado)).sueldo);
		}
	}
    return retorno;
}
