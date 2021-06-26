
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pedir_valores.h"
#include "Menu.h"
#include "Controller.h"
static int idIncremental;
//******************************CARGAR DESDE LOS ARCHIVOS(TEXTO-BINARIO)******************************
/** \brief Carga los datos de los empleados desde el archivo modo texto.
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int retorna (0) si los datos fueron cargados con exito.
 * 					   (-1) en caso de error.
 * 					   (-2) si la operacion fue cancelada.
 * 					   (-3) si no se pude abrir el archivo o no existe.
 */
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
			continuar = parser_EmployeeFromText(pFile, pArrayListEmployee);
			if(!continuar)
			{
				retorno = 0; //datos cargados con exito.
			}
			else
			{
				if(continuar == -2)
				{
					retorno = -2; // Operacion cancelada.
				}
			}
			fclose(pFile);
		}
		else
		{
			retorno = -3; //Error al abrir el archivo
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde archivo modo binario.
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int retorna (0) si los datos fueron cargados con exito.
 * 					   (-1) en caso de error.
 * 					   (-2) si la operacion fue cancelada.
 * 					   (-3) si no se pude abrir el archivo o no existe.
 */
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
			continuar = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			if(!continuar)
			{
				retorno = 0; //datos cargados con exito.
			}
			else
			{
				if(continuar == -2)
				{
					retorno = -2; // Operacion cancelada.
				}
			}
			fclose(pFile);
		}
		else
		{
			retorno = -3; //Error al abrir el archivo
		}
	}
	return retorno;
}
//**********************************ALTA - MODIFICACION - BAJA(ABM)***********************************
/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*  puntero a la lista.
 * \return int (0) operacion realizada con exito.
 * 			   (-1) error al realizar la operación.
 * 			   (-2) operacion cancelada.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		empleado = employee_new();
		if(empleado != NULL)
		{
			idIncremental ++;
			if(!employee_setId(empleado, idIncremental) &&
			   !Employee_cargarDatos(empleado))
			{
				if(!utn_verificar("¿Desea guardar los datos? ", "Error, ingrese [s/n].\n", 2))
				{
					if(!ll_add(pArrayListEmployee, empleado))
					{
						retorno = 0; // salio bien.
						puts("Empleado cargado: ");
						puts("\n\tID\t   NOMBRE\t   HS. TRABAJADAS\t SUELDO");
						employee_mostrarUno(empleado);
						puts("");
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
 * \param pArrayListEmployee LinkedList*  puntero a la lista.
 * \return int. (0) operacion realizada con exito.
 * 				(-1) Error al realizar la operación.
 * 				(-2) ID invalido.
 * 				(-3) ID mal ingresado.
 * 				(-4) No hay elementos para editar.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error.
	int id;
	int indice;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			ll_sort(pArrayListEmployee, employee_compareBbyName, 1);
			puts("\n\n*************************LISTA ALFABETICA DE EMPLEADOS [A-Z]*************************");
			controller_mostrarTodos(pArrayListEmployee);
			puts("\n\n***********************************FIN DE LA LISTA***********************************");
			if(!utn_pedirEntero(&id, "Ingrese el ID del empleado que desea editar: ", "Error\n", 0, 0, 2, 0))
			{
				indice = controller_buscarPorId(pArrayListEmployee, id);
				if(indice > -1)
				{
					empleado = ll_get(pArrayListEmployee, indice);
					if(!employee_editEmployee(empleado))
					{
						ll_set(pArrayListEmployee, indice, empleado); //Para probar el set, no es necesario porq ya trabajo con punteros.
						retorno = 0;
						puts("Empleado guardado: \n");
						puts("\n\tID\t   NOMBRE\t   HS. TRABAJADAS\t SUELDO");
						employee_mostrarUno(empleado);
						puts("");
					}
				}
				else
				{
					if(indice == -2)
					{
						retorno = -2; //id invalido.
					}
				}
			}
			else
			{
				retorno = -3; // dato mal ingresado
			}
		}
		else
		{
			retorno = -4;// No hay elementos para editar.
		}
	}
    return retorno;
}

/** \brief elimina empleado
 * \param pArrayListEmployee LinkedList*  puntero a la lista.
 * \return int. (0) operacion realizada con exito.
 * 				(-1) Error al realizar la operación.
 * 				(-2) operacion cancelada.
 * 				(-3) ID no existe.
 * 				(-4) ID mal ingresado.
 * 				(-5) No hay elementos para eliminar.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error.
	int id;
	int indice;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			ll_sort(pArrayListEmployee, employee_compareBbyName, 1);
			puts("\n\n*************************LISTA ALFABETICA DE EMPLEADOS [A-Z]*************************");
			controller_mostrarTodos(pArrayListEmployee);
			puts("\n\n***********************************FIN DE LA LISTA***********************************");
			if(!utn_pedirEntero(&id, "Ingrese el ID del empleado que desea eliminar: ", "Error.\n", 0, 0, 2, 0))
			{
				indice = controller_buscarPorId(pArrayListEmployee, id);
				if(indice > -1)
				{

					empleado = ll_get(pArrayListEmployee, indice);
					puts("Empleado a eliminar: ");
					puts("\n\tID\t   NOMBRE\t   HS. TRABAJADAS\t SUELDO");
					employee_mostrarUno(empleado);
					puts("");
					if(!utn_verificar("¿Desea confirmar la operación? ", "Error, ingrese [s/n]\n", 2))
					{
						if(!ll_remove(pArrayListEmployee, indice) &&
						   !employee_delete(empleado))
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
				else
				{
					if(indice == -2)
					{
						retorno = -3; //ID no existe.
					}
				}
			}
			else
			{
				retorno = -4;//ID mal ingresado.
			}
		}
		else
		{
			retorno = -5; // no hay empleado el la lista para eliminar.
		}
	}
    return retorno;
}
//*****************************************LISTAR EMPLEADOS*******************************************
/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int. (0) operacion realizada con exito.
 * 				(1) No hay elementos para listar.
 * 				(-1) Error
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1; // error
	if(pArrayListEmployee != NULL)
	{
		puts("\n\n*********************************INICIO DE LA LISTA***********************************");
		retorno = controller_mostrarTodos(pArrayListEmployee);
		puts("\n\n***********************************FIN DE LA LISTA***********************************");
	}
    return retorno;
}

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int  (0) Operacion realizada con exito.
 * 				(-1) Error.
 * 				(-2) error al ingresar las opciones del menu.
 * 				(-3) lista vacia.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int criterio;
	int respuesta;
	if(pArrayListEmployee != NULL)
	{
		respuesta = ll_isEmpty(pArrayListEmployee);
		if(!respuesta)
		{
			do
			{
				respuesta = menu_sort(&opcion, &criterio);
				if(!respuesta)
				{

					switch(opcion)
					{
						case 1:
							retorno =ll_sort(pArrayListEmployee, employee_compareBbyName, criterio);
						break;
						case 2:
							retorno = ll_sort(pArrayListEmployee, employee_compareBbyId, criterio);
							break;
						case 3:
							retorno = ll_sort(pArrayListEmployee, employee_compareBbyHoras, criterio);
						break;
						case 4:
							retorno = ll_sort(pArrayListEmployee, employee_compareBbySueldo, criterio);
						break;
						case 5:
							retorno = 0;
							break;
					}
					if(opcion != 5)
					{
						puts("\n\n***********************************LISTA ORDENADA************************************");
						controller_mostrarTodos(pArrayListEmployee);
						puts("\n\n***********************************FIN DE LA LISTA***********************************");
					}
				}
				else
				{
					if(respuesta == -2)
					{
						retorno = -2; //error al ingreesar las opciones del menu.
					}
				}
			}while(opcion != 5);
		}
		else
		{
			if(respuesta == 1)
			{
				retorno = -3; //lista vacia.
			}
		}
	}
    return retorno;
}
//*********************************GUARDAR EN ARCHIVOS (TEXTO-BINARIO)********************************
/** \brief Guarda los datos de los empleados en el archivo modo texto.
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int  (0) operacion realizada con exito.
 * 				(-1) error
 * 				(-2) copia defectuosa.
 * 				(-3) operacion cancelada.
 * 				(-4) lista vacia.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1; //Error.
	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			ll_sort(pArrayListEmployee, employee_compareBbyName, 1);
			puts("\n\n*********************************INICIO DE LA LISTA***********************************");
			puts("\tEmpleados en la lista: ");
			controller_mostrarTodos(pArrayListEmployee);
			puts("\n\n***********************************FIN DE LA LISTA***********************************");
			if(!utn_verificar("¿Esta seguro de guardar la lista mostrada en el archivo de texto? ", "Error , ingrese [s/n]\n", 2))
			{
				pFile = fopen(path,"w");
				retorno = parser_EmployeeSaveAsText(pArrayListEmployee, pFile); // 0 ok - -2 copia defectuosa - -1error
				fclose(pFile);
			}
			else
			{
				retorno = -3; //operacion cancelada
			}
		}
		else
		{
			retorno = -4; // lista vacia.
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo modo binario.
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int  (0) operacion realizada con exito.
 * 				(-1) error
 * 				(-2) copia defectuosa.
 * 				(-3) operacion cancelada.
 * 				(-4) lista vacia.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			ll_sort(pArrayListEmployee, employee_compareBbyName, 1);
			puts("\n\n*********************************INICIO DE LA LISTA***********************************");
			puts("\tEmpleados en la lista: ");
			controller_mostrarTodos(pArrayListEmployee);
			puts("\n\n***********************************FIN DE LA LISTA***********************************");
			if(!utn_verificar("¿Esta seguro de guardar la lista mostrada en el archivo binario? ", "Error, ingrese [s/n]\n", 2))
			{
				pFile = fopen(path,"wb");
				if(pFile != NULL)
				{
					retorno = parser_EmployeeSaveAsBinary(pArrayListEmployee, pFile); // 0 ok - -2 copia defectuosa - -1 error
					fclose(pFile);
				}
			}
			else
			{
				retorno = -3; //operacion cancelada
			}
		}
		else
		{
			retorno = -4; // lista vacia.
		}
	}
    return retorno;
}
//****************************************************************************************************
/** \brief devuelve el indice del elemento buscandolo por el id.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int  (>-1) si devuelve el indice.
 * 				(-1) error
 * 				(-2) no se encontro el ID.
 */
int controller_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	Employee* empleado;
	int cantidad;
	int idEmpleado;
	if(pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		for(i=0; i<cantidad; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			employee_getId(empleado, &idEmpleado);
			if(idEmpleado == id)
			{
				retorno = i;//mayor que -1 si lo  encontro; retorna el indice.
				break;
			}
			else
			{
				retorno = -2;//no se encontro  ID;
			}
		}
	}
	return retorno;
}
/** \brief devuelve el id maximo encontrado en la lista.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int  (-1) error.
 * 				(>-1) si devuelve el id maximo.
 * 				(-1) error
 * 				(-2) no se encontro el ID.
 */
int controller_buscarIdMaximo(LinkedList* pArrayListEmployee)
{
	int i;
	Employee* empleado;
	int bandera = 0;
	int idMax = -1;
	int cantidad;
	int id;
	if(pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		for(i=0; i<cantidad; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			employee_getId(empleado, &id);
			if(bandera == 0 || id > idMax)
			{
				bandera = -1;
				idMax = id;
			}
		}
	}
	return idMax;
}
/** \brief lista todos los elementos de la lista.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 				(0) operación realizada con exito
 * 				(1) no hay elementos para lista
 */
int controller_mostrarTodos(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int cantidad;
	int i;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			cantidad= ll_len(pArrayListEmployee);
			puts("\n\tID\t   NOMBRE\t   HS. TRABAJADAS\t SUELDO");
			for(i=0; i<cantidad; i++)
			{
				empleado = ll_get(pArrayListEmployee, i);
				employee_mostrarUno(empleado);
			}
			printf("\n\t\tCantidad empleados: %d\n", cantidad);
			retorno = 0;
		}
		else
		{
			retorno = 1; //no hay elementos para listar.
		}
	}
	return retorno;
}

/** \brief lista todos los elementos de la lista.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 				(0) operación realizada con exito
 * 				(1) no hay elementos para lista
 */
int controller_clonarParteDeLista(LinkedList* pArrayListEmployee) //-----------------------------------------------------------------------------------
{
	int retorno = -1;
	int cantidad;
	int cuantos;
	LinkedList* listaNueva;
	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			cantidad= ll_len(pArrayListEmployee);
			controller_mostrarTodos(pArrayListEmployee);
			if(!utn_pedirEntero(&cuantos, "ingrese cuantos empleados quiere para a la nueva lista.", "error", 1, cantidad, 2, 1) && cantidad > cuantos)
			{
				listaNueva = ll_subList(pArrayListEmployee, 0, cuantos);
				if(listaNueva != NULL)
				{
					controller_mostrarTodos(listaNueva);
					if(ll_containsAll(pArrayListEmployee, listaNueva)==1)
					{
						puts("ConteinsAll y sublist funcionan bien.");
						retorno = 0;
					}
					ll_deleteLinkedList(listaNueva);
				}
			}
		}
	}
	return retorno;
}
/** \brief lista todos los elementos de la lista.
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 				(0) operación realizada con exito
 * 				(1) no hay elementos para lista
 */
int controller_clonarLista(LinkedList* pArrayListEmployee) //-----------------------------------------------------------------------------------
{
	int retorno = -1;
	LinkedList* listaNueva;
	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			puts("Lista a clonar.");
			controller_mostrarTodos(pArrayListEmployee);
			listaNueva = ll_clone(pArrayListEmployee);
			puts("ListaClonada");
			controller_mostrarTodos(listaNueva);
		}
	}
	return retorno;
}

/** \brief Corrobora si la lista esta vacia y si no lo esta realiza la opcion elegida por el usuario (borrarla o mantenerla).
 * \param pArrayListEmployee LinkedList* puntero a la lista.
 * \return int  (-1) error
 * 				(0) operacion realizada con exito.
 */
int controller_listaVacia(LinkedList* pArrayListEmployee)
{
	int retorno = -1; //error.
	int opcion;
	int cantidadElementos;
	int i = 0;
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))//devuelve 1 lista vacia- 0 si no esta vacia
		{
			puts("\n\n*********************************INICIO DE LA LISTA***********************************");
			controller_mostrarTodos(pArrayListEmployee);
			puts("\n\n***********************************FIN DE LA LISTA***********************************");
			if(!menu_listNotEmpty(&opcion))
			{
				switch(opcion)
				{
					case 1:
						retorno = 0;
					break;
					case 2:
						cantidadElementos = ll_len(pArrayListEmployee);
						for(i=cantidadElementos; i>-1; i--)
						{
							empleado = ll_get(pArrayListEmployee, i);
							if(empleado != NULL && !employee_delete(empleado))
							{
								retorno = 0;
							}
							ll_clear(pArrayListEmployee);
						}
					break;
					case 3:
						do{
							if(!controller_removeEmployee(pArrayListEmployee))
							{
								if(utn_verificar("¿Desea eliminar otro empleado?", "Error.\n", 2) == 1)
								{
									i = 1;
								}
							}
							else
							{
								puts("Ocurrio un error o no hay más empleados para eliminar.");
								i=1;
							}
						}while(!i);
						retorno = 0;
					break;
				}
			}
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}
//**************************************CONTROLAR ID***************************************************
/** \brief escribe un archivo en modo binario el ultimo id
 * \param numero. numero que va a ser escrito en el archivo
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int controller_saveLastID(int numero)
{
	int retorno = -1;
	int* idMax;
	FILE* pFile;
	idMax = (int*)malloc(sizeof(int));
	pFile = fopen("ultimoID.bin", "wb");
	if(pFile != NULL && idMax != NULL)
	{
		*idMax = numero;
		fwrite(idMax, sizeof(int), 1, pFile);
		fclose(pFile);
		retorno = 0;
	}
	free(idMax);
	return retorno;
}
/** \brief lee un archivo en modo binario que guarda el ultimo id y se lo copia a idIncremental.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int controller_loadId()
{
	int retorno = -1;
	int* idMax;
	FILE* pFile;
	idMax = (int*)malloc(sizeof(int));
	pFile = fopen("ultimoID.bin", "rb");
	if(pFile != NULL && idMax != NULL)
	{
		fread(idMax, sizeof(int), 1, pFile);
		fclose(pFile);
		idIncremental = *idMax;
		free(idMax);
		retorno = 0;
	}
	return retorno;
}
/** \brief escribe en un archivo en modo binario el ultimo id
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int controller_saveID()
{
	int retorno = -1;
	int* idMax;
	FILE* pFile;
	idMax = (int*)malloc(sizeof(int));
	*idMax = idIncremental;
	pFile = fopen("ultimoID.bin", "wb");
	if(pFile != NULL && idMax != NULL)
	{
		fwrite(idMax, sizeof(int), 1, pFile);
		fclose(pFile);
		free(idMax);
		retorno = 0;
	}
	return retorno;
}
