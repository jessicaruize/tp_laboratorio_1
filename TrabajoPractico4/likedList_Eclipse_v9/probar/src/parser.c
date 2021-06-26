#include "parser.h"
/** \brief Guarda los datos los datos de los empleados desde el archivo modo texto a la lista de memoria dinamica.
 * \param File* pFile puntero al archivo.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error
	char id[TAM_OTROS];
	char nombre[TAM_NOMBRE];
	char horasTrabajadas[TAM_OTROS];
	char sueldo[TAM_OTROS];
	char aux[300];
	Employee* empleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(!controller_listaVacia(pArrayListEmployee))
		{
			fscanf(pFile,"%s\n",aux);
			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo)==4)
				{
					empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
					if(empleado != NULL)
					{
						if(!employee_setNombre(empleado, nombre) &&
						   !ll_add(pArrayListEmployee, empleado))
						{
							retorno=0;//Se guardo con exito
						}
					}
				}
			}while(!feof(pFile));
		}
	}
    return retorno;
}

/** \brief Guarda los datos los datos de los empleados desde el archivo modo binario a la lista de memoria dinamica.
 * \param File* pFile puntero al archivo.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error
	Employee* empleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(!controller_listaVacia(pArrayListEmployee))
		{
			do
			{
				empleado = employee_new();
				if(fread(empleado, sizeof(Employee), 1, pFile) == 1 &&
				   !ll_add(pArrayListEmployee, empleado))
				{
					retorno = 0;
				}
			}while(!feof(pFile));
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados de la lista de memoria dinamica al archivo modo texto.
 * \param File* pFile puntero al archivo.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_EmployeeSaveAsText(LinkedList* pArrayListEmployee, FILE* pFile)
{
	int retorno = -1;
	int i;
	int cantidad;
	Employee* empleado;
	int id;
	int hsTrabajadas;
	int sueldo;
	char nombre[TAM_NOMBRE];
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		fprintf(pFile, "ID, nombre, horas trabajadas, sueldo\n");
		for(i=0; i<cantidad; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			if(!employee_getId(empleado, &id) &&
			   !employee_getNombre(empleado, nombre) &&
			   !employee_getHorasTrabajadas(empleado, &hsTrabajadas) &&
			   !employee_getSueldo(empleado, &sueldo))
			{
				if(fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, hsTrabajadas, sueldo)<4)
				{
					retorno = -2; //copia defectuosa. intentar de nuevo
					break;
				}
			}
		}
		if(retorno != -2)
		{
			retorno = 0;//se guardo con exito.
		}
	}
	return retorno;
}
/** \brief Guarda los datos de los empleados de la lista de memoria dinamica al archivo modo binario.
 * \param File* pFile puntero al archivo.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_EmployeeSaveAsBinary(LinkedList* pArrayListEmployee, FILE* pFile)
{
	int retorno = -1;
	int cantidad;
	int cantidadImpresa;
	int i;
	Employee* empleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		cantidad = ll_len(pArrayListEmployee);
		for(i=0; i<cantidad; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			cantidadImpresa = fwrite(empleado,sizeof(Employee), 1, pFile);
			if (cantidadImpresa != 1)
			{
				retorno = -2; //copia defectuosa
				break;
			}
		}
	}

	return retorno;
}
