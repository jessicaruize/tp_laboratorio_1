
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pedir_valores.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
//1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//Error.
	FILE* pFile;
	int continuar = 1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(!ll_isEmpty(pArrayListEmployee))//devuelve 1 lista vacia- 0 si no esta vacia
			{
				printf("Ya se ha cargado la lista o hay datos en ella, si continua perdera los datos ya guardados.");
				if(utn_verificar("¿Desea continuar? [s/n]", "Error.", 2) == 1) //1=no
				{
					continuar = 0;
					retorno = -2; //operación cancelada.
				}
			}
			if(continuar)
			{
				ll_clear(pArrayListEmployee);
				if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
				{
					retorno = 0; //datos cargados con exito.
				}
			}
			fclose(pFile);
		}
		else
		{
			retorno = -3; //No existe el archivo
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
//2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;//Error.
	FILE* pFile;
	int continuar = 1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			if(!ll_isEmpty(pArrayListEmployee))//devuelve 1 lista vacia- 0 si no esta vacia
			{
				printf("Ya se ha cargado la lista o hay datos en ella, si continua perdera los datos ya guardados.");
				if(utn_verificar("¿Desea continuar? [s/n]", "Error.", 2) == 1)
				{
					continuar = 0;
					retorno = -2; //operación cancelada.
				}
			}
			if(continuar)
			{
				ll_clear(pArrayListEmployee);
				if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
				{
					retorno = 0; //datos cargados con exito.
				}
			}
			fclose(pFile);
		}
		else
		{
			retorno = -3; //No existe el archivo
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
// 3. Alta de empleado
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error
	int idMaximo;
	Employee* empleado;
	char nombre[TAM_NOMBRE];
	int sueldo;
	int horasTrabajadas;
	idMaximo = controller_buscarIdMaximo(pArrayListEmployee);
	idMaximo ++;
	if(pArrayListEmployee != NULL)
	{
		empleado =employee_new();
		if(empleado != NULL)
		{
			if(!utn_pedirAlfabetico(nombre, TAM_NOMBRE, "Ingrese el nombre del empleado", "Error.", 2) &&
			!utn_pedirEntero(&horasTrabajadas, "Ingrese las horas trabajadas del empleado.", "Error.", 0, 300, 2, 1) &&
			!utn_pedirEntero(&sueldo, "Ingrese el sueldo del empleado.", "Error.", 0, 1000000, 2, 1) &&
			!employee_setId(empleado, idMaximo) &&
			!employee_setNombre(empleado, nombre) &&
			!employee_setHorasTrabajadas(empleado, horasTrabajadas) &&
			!employee_setSueldo(empleado, sueldo))
			{
				if(!utn_verificar("¿Desea guardar los datos?", "Error.", 2))
				{
					if(!ll_add(pArrayListEmployee, empleado))
					{
						retorno = 0; // salio bien.
						puts("\nEmpleado cargado: ");
						printf("ID: %d \t Nombre: %s \t Hs.Trabajadas: %d \t Sueldo: %d\n", (*empleado).id, (*empleado).nombre, (*empleado).horasTrabajadas, (*empleado).sueldo);
					}
				}
				else
				{
					retorno = -2;//operación cancelada.
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) //usar func ll_set
{
	int retorno = -1;
	int respuesta;
	int id;
	int idMax;
	int indice;
	Employee* empleado;
	char nombre[TAM_NOMBRE];
	int hsTrabajadas;
	int sueldo;
	if(pArrayListEmployee != NULL)
	{
		idMax = controller_buscarIdMaximo(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_pedirEntero(&id, "Ingrese el ID del empleado que desea editar.", "Error", 0, idMax, 2, 1))
		{
			indice = controller_buscarPorId(pArrayListEmployee, id);
			if(indice > -1)
			{
				empleado = ll_get(pArrayListEmployee, indice);
				do
				{
					printf("\nEmpleado seleccionado: %d,%s,%d,%d\n", (*empleado).id, (*empleado).nombre, (*empleado).horasTrabajadas, (*empleado).sueldo);
					puts("\nEDITAR: \n1_Nombre.\n2_Horas trabajadas.\n3_Sueldo.\n4_Salir");
					if(!utn_pedirEntero(&respuesta, "Ingrese el número correspondiente al dato que desea realizar.", "Error", 1, 4, 2, 1))
					{
						switch(respuesta)
						{
							case 1:
								utn_pedirAlfabetico(nombre, TAM_NOMBRE, "Ingrese el nombre:", "Error.", 2);
								if(!utn_verificar("¿Desea guardar los cambios?", "Error", 2))
								{
									employee_setNombre(empleado, nombre);
								}
								break;
							case 2:
								utn_pedirEntero(&hsTrabajadas, "Ingrese las horas trabajadas:", "Error", 0, 300, 2, 1);
								if(!utn_verificar("¿Desea guardar los cambios?", "Error", 2))
								{
									employee_setHorasTrabajadas(empleado, hsTrabajadas);
								}
								break;
							case 3:
								utn_pedirEntero(&sueldo, "Ingrese el sueldo:", "Error.", 0, 1000000, 2, 1);
								if(!utn_verificar("¿Desea guardar los cambios?", "Error", 2))
								{
									employee_setSueldo(empleado, sueldo);
								}
								break;
							case 4:
								puts("El empleado elegido se guardara con estos datos: ");
								printf("%d,%s,%d,%d\n", (*empleado).id, (*empleado).nombre, (*empleado).horasTrabajadas, (*empleado).sueldo);
								if(!utn_verificar("¿Desea cambiar algún dato?", "Error.", 2))
								{
									respuesta = 1;
								}
								break;
						}
					}
				}while(respuesta != 4);
				retorno = 0;
			}
		}
		else
		{
			retorno = -2;
			//ID invalido
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error.
	int idMax;
	int id;
	int indice;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		idMax = controller_buscarIdMaximo(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_pedirEntero(&id, "Ingrese el ID del empleado que desea eliminar.", "Error", 0, idMax, 2, 1))
		{
			indice = controller_buscarPorId(pArrayListEmployee, id);
			if(indice > -1)
			{
				empleado = ll_pop(pArrayListEmployee, indice);
				printf("%d,%s,%d,%d\n", (*empleado).id, (*empleado).nombre, (*empleado).horasTrabajadas, (*empleado).sueldo);
				if(!utn_verificar("¿Desea eliminar al empleado?", "Error", 2))
				{
					if(!employee_delete(empleado))
					{
						retorno = 0;//empleado eliminado
					}
				}
				else
				{
					ll_push(pArrayListEmployee, indice, empleado);
					retorno = -2; //operacion cancelada
				}
			}
		}
		else
		{
			retorno = -3;//ID no existe.
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)//crear funciones mostrar todos, mostrar 1. ll_set para mostrar
{
	int retorno = -1;
	int i;
	int j;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		i = ll_len(pArrayListEmployee);
		printf("ID, nombre, horas trabajadas, sueldo\n");
		for(j=0; j<i+1; j++)
		{
			empleado = ll_get(pArrayListEmployee, j);
			if(empleado != NULL)
			{
				retorno = 0;
				printf("%d,%s,%d,%d\n", (*empleado).id, (*empleado).nombre, (*empleado).horasTrabajadas, (*empleado).sueldo);
			}
		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	LinkedList* clone;
	if(pArrayListEmployee != NULL)
	{
		clone = ll_clone(pArrayListEmployee);
		ll_sort(clone, employee_compareBbyName, 1);
		puts("Lista ordenada por nombre: ");
		//crear funcion mostrar todos.
		ll_sort(clone, employee_compareBbyId, 1);
		puts("Lista ordenada por ID: ");
		//mostrar .
		retorno = 0;

	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int i;
	int cantidad;
	Employee* empleado;
	int id;
	int hsTrabajadas;
	int sueldo;
	char nombre[TAM_NOMBRE];
	if(path != NULL && pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			retorno = 0;
			fprintf(pFile, "ID, nombre, horas trabajadas, sueldo\n");
			for(i=0; i<cantidad+1; i++)
			{
				empleado = ll_get(pArrayListEmployee, i);//hacerfuncion.--------------Guardarentexto-----------------------------------------------------------------------------------------
				if(!employee_getId(empleado, &id) &&
				   !employee_getNombre(empleado, nombre) &&
				   !employee_getHorasTrabajadas(empleado, &hsTrabajadas) &&
				   !employee_getSueldo(empleado, &sueldo))

				if(fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, hsTrabajadas, sueldo)<4)
				{

						retorno = -2; //copia defectuosa.
						break;
				}
					printf("%d,%s,%d,%d\n", id, nombre, hsTrabajadas, sueldo);

			}
			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int i;
	int cantidad;
	int cantidadEscrita;
	Employee* empleado;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		//if(!ll_isEmpty(pArrayListEmployee))
		//{
			pFile = fopen(path,"wb");
			if(pFile != NULL)
			{
				retorno = 0;
				cantidad = ll_len(pArrayListEmployee);
				fprintf(pFile, "ID, nombre, horas trabajadas, sueldo");
				for(i=0; i<cantidad+1; i++)
				{
					empleado = ll_get(pArrayListEmployee, i);
					fwrite(empleado, sizeof(Employee), 1, pFile);
					if(cantidadEscrita < 1)
					{
						retorno = -3;//copia mala
						break;
					}
				}
				fclose(pFile);
			}
		//}
		/*else
		{
			retorno = -2;//lista vacia.
		}*/
	}
	printf("retorno %d", retorno);
    return retorno;
}

int controller_menu(int* opcion)
{
	int retorno = -1;
	if(opcion != NULL)
	{
		puts("MENU:");
		puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
		puts("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
		puts("3. Alta de empleado.");
		puts("4. Modificar datos de empleado.");
		puts("5. Baja de empleado.");
		puts("6. Listar empleados.");
		puts("7. Ordenar empleados.");
		puts("8. Guardar los datos de los empleados en el archivo datatxt.csv (modo texto).");
		puts("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).");
		puts("10. Salir.");
		if(!utn_pedirEntero(opcion, "Ingrese una opción.", "Error.", 1, 10, 2, 1))
		{
			retorno = 0;
		}
		else
		{
			puts("Ingreso un número errroneo.");
		}
	}
	return retorno;
}

//devuelve el indice del empleado que tiene el id pasado por parametro o -1 en caso de error
int controller_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee)+1; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			if((*empleado).id == id)
			{
				retorno = i;//mayor que -1 si lo  encontro;
				break;
			}
		}
	}
	return retorno;
}

//devuelve el id maximo o -1 en caso de error.
int controller_buscarIdMaximo(LinkedList* pArrayListEmployee)
{
	int i;
	Employee* empleado;
	int bandera = 0;
	int idMax = -1;
	if(pArrayListEmployee != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			if(bandera == 0 || (*empleado).id > idMax)
			{
				bandera = -1;
				idMax = (*empleado).id;
			}
		}
	}
	return idMax;
}

