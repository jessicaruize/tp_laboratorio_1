/*
 * EmpleadoSector.c
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */

#include "EmpleadoSector.h"

/*funcion que carga los datos el empleado y muestra los datos del sector
 * pEmpleado puntero del que vamos a cargar los datos
 * arraySector es el array que nos va a brindar los datos para que el usuario vea y elija el sector
 * TAM2 tamaño del arraySector
 * retorna -1 en caso de error y o si esta todo bien
 * */
int eConjuntos_cargarDatos(eEmpleado* pEmpleado, eSector arraySector[], int TAM2)
{
	int retorno = -1;
	int cantidadSector;
	int idMaximoSector;
	int indiceSector;
	if((pEmpleado != NULL) && (arraySector != NULL))
	{
		if(!utn_pedirAlfabetico(pEmpleado->nombre, MAX_CHARS_CADENAS, "\n\nIngrese nombre: ", "\nError.\n", 2) &&
		!utn_pedirAlfabetico(pEmpleado->apellido, MAX_CHARS_CADENAS, "\n\nIngrese apellido: ", "\nError.\n", 2) &&
		!utn_pedirFlotante(&pEmpleado->salario, "\nIngrese salario: \n", "\nError.\n", 0, 99999999, 2, 1) &&
		!eSector_mostrarTodos(arraySector, TAM2, &cantidadSector) &&
		!eSector_buscarIdMaximo(arraySector, TAM2, &idMaximoSector) &&
		!utn_pedirEntero(&pEmpleado->sector, "\nIngrese el ID del sector: \n", "\nError\n", 1, idMaximoSector, 2, 1) &&
		!eSector_buscarIndicePorId(arraySector, TAM2, pEmpleado->sector, &indiceSector))
		{
			 retorno = 0;
		}
	}
	return retorno;
}

/*funcion que da de alta una vez que el usuario confirma la accion
 * arrayEmpleados es el array en el que se va a cargar el alta
 * TAM1 tamaño del arrayEmpleados
 * arrayEmpleados es el array que se va mostrar para elegir el sector en el alta
 * TAM1 tamaño del arraySector
 * retorna -1 en caso de error, 0 si se dio de alta satisfactoriamente, 1 si se cancelo la operación
 * y -2 si el array esta lleno
 * */
int eConjuntos_alta(eEmpleado arrayEmpleados[], int TAM1, eSector arraySector[], int TAM2)
{
	int retorno = -1; //ERROR
	eEmpleado auxEmpleado;
	int indice;
	if(arrayEmpleados != NULL && TAM1 > 0 && arraySector != NULL && TAM2 > 0)
	{
		indice = eEmpleado_obtenerIndiceLibre(arrayEmpleados, TAM1);
		if (indice > -1)
		{
			if(!eConjuntos_cargarDatos(&auxEmpleado, arraySector, TAM2))
			{
				if(!utn_verificar("\n¿Desea guardar los cambios[s/n]?", "Error", 2))
				{
					auxEmpleado.id = eEmpleado_obtenerID();
					auxEmpleado.isEmpty = OCUPADO;
					if(!eEmpleado_agregarEmpleado(arrayEmpleados, indice, auxEmpleado) &&
					!eConjuntos_mostrarUno(&arrayEmpleados[indice], arraySector, TAM2))
					{
						retorno = 0; //se dio de alta satisfactoriamente
					}
				}
				else
				{
					retorno = 1; //Operacion cancelada
				}
			}
			else
			{
				puts("\nDatos mal ingresados.");
			}
		}
		else
		{
			if(indice == -2)
			{
				retorno = -2; //array lleno
			}
		}
	}

	return retorno;
}


/*funcion que muestra un empleado con los datos del sector
 * pEmpleado puntero que va brindar la informacion para mostrar
 * arraySector array que va brindar la informacion para mostrar
 * TAM2 tamaño del arraySector
 * retor -1 en caso de error y o si no hubo error.
 * */
int eConjuntos_mostrarUno(eEmpleado* pEmpleado, eSector arraySector[], int TAM2)
{
	int retorno = -1; //error.
	int indiceSector;
	if((pEmpleado != NULL) && (arraySector != NULL) && TAM2 > 0)
	{
		retorno = 0; //bien.
		eSector_buscarIndicePorId(arraySector, TAM2, pEmpleado->id, &indiceSector);

		printf("ID:%-4d \t nombre:%-15s \t apellido:%-15s \t salario:$%-.2f \t ID sector:%-4d \t sector:%-15s \n", pEmpleado->id,
																										 	 	   pEmpleado->nombre,
																												   pEmpleado->apellido,
																												   pEmpleado->salario,
																												   pEmpleado->sector,
																												   arraySector[indiceSector].descripcion);
	}
	return retorno;
}


/*funcion que muestra a todos los empleados con los datos del sector
 * pEmpleado puntero que va brindar la informacion para mostrar
 * TAM1 tamaño del arrayEmpleado
 * arraySector array que va brindar la informacion para mostrar
 * TAM2 tamaño del arraySector
 * retor -1 en caso de error y 0 si hay empleados para mostrar.
 * */
int eConjuntos_mostrarTodos(eEmpleado arrayEmpleado[], int TAM1, eSector arraySector[], int TAM2)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (arrayEmpleado != NULL && arraySector != NULL && TAM1 > 0 && TAM2 > 0)
	{
		for (i = 0; i < TAM1; i++)
		{
			if (arrayEmpleado[i].isEmpty == OCUPADO)
			{
				eConjuntos_mostrarUno(&arrayEmpleado[i], arraySector, TAM2);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		printf("\n\tTOTAL: %-4d.\n", contador);
		retorno = 0; //hay Empleado para mostrar.
	}

	return retorno;
}


/*funcion que realiza la baja logica una vez que el usuario confirma la acción
 * arrayEmpleado array en el que se va a modificar el cambio
 * TAM1 tamaño del arrayEmpleado
 * arrayEmpleado array en el que se va a modificar el cambio
 * TAM2 tamaño del arraySector
 * retorna -2 en caso de error, -1ID no existe, 0 baja exitosa, 1 empleado dado de baja, 2 operacion cancelada
 * */
int eConjuntos_baja(eEmpleado arrayEmpleado[], int TAM1, eSector arraySector[], int TAM2)
{
	int retorno = -2; //ERROR
	int idEmpleado;
	int indice;
	int idMaximo;
	int respuesta;
	eEmpleado buffer;

	int flag = 0;
	if (eConjuntos_mostrarTodos(arrayEmpleado, TAM1, arraySector, TAM2)==0)
	{
		flag = 1;
	}
	if (flag)
	{
		eEmpleado_buscarIdMaximo(arrayEmpleado, TAM1, &idMaximo);
		if(utn_pedirEntero(&idEmpleado, "\nIngrese el ID del Empleado que quiere dar de baja: \n", "\nError. \n", 1, idMaximo, 2, 1)==0)
		{
			respuesta = eEmpleado_buscarIndicePorId(arrayEmpleado, TAM1, idEmpleado, &indice);
			switch (respuesta)
			{
				case -2: //ERROR
					retorno = -2;
				break;
				case 0: //OCUPADO
					buffer = arrayEmpleado[indice];
					eConjuntos_mostrarUno(&buffer, arraySector, TAM2);
					if(utn_verificar("\n¿Desea dar de baja este Empleado [s/n]?", "\nError", 2)==0)
					{
						arrayEmpleado[indice].isEmpty = BAJA; //baja logica.
						retorno = 0; //BAJA CORRECTAMENTE.
					}
					else
					{
						retorno = 2; //cancelado
					}
				break;
				case 1: //BAJA
					retorno = 1; // Empleado YA DADO DE BAJA
				break;
			}
		}
		else
		{
			retorno = -1; // ID no existe.
		}
	}

	return retorno;
}

/*funcion que modifica el dato elegido por el usuario
 * pEmpleado puntero que a ser modificado
 * arraySector array que va a mostrar los sectores para que el usuario elija
 * TAM2 tamaño del arraySector
 * retorna -1 en caso de error, 0 modificacion exitosa
 * */
int eConjuntos_modificarUno(eEmpleado* pEmpleado, eSector arraySector[], int TAM2)
{
	int retorno = -1; //ERROR
	int idMaximoSector;
	int cantidadSector;
	int respuesta;
	int indiceSector;

	if(pEmpleado != NULL && arraySector != NULL && TAM2 > 0)
	{
		do
		{
			printf("\n\n\tMODIFICAR: \n\n1_Nombre.\n2_apellido.\n3_Salario \n4_Sector.\n5_Modificación terminada.");
			if(!utn_pedirEntero(&respuesta, "\n\nIngrese la opción que desea realizar: ", "\nError", 1, 6, 2, 1))
			{
				switch(respuesta)

				{
					case 1:
						if(!utn_pedirAlfabetico(pEmpleado->nombre, MAX_CHARS_CADENAS, "Ingrese la nombre: ", "Error", 2))
						{
							printf("Nombre modificado: %s", pEmpleado->nombre);
							retorno=0;
						}
					break;
					case 2:
						if(!utn_pedirAlfabetico(pEmpleado->apellido, MAX_CHARS_CADENAS, "Ingrese apellido: ", "Error", 2))
						{
							printf("Apellido modificado: %s", pEmpleado->apellido);
							retorno=0;
						}
					break;
					case 3:
						if(!utn_pedirFlotante(&pEmpleado->salario, "Ingrese salario: ", "Error", 0, 1000000, 2, 1))
						{
							printf("Salario modificado: %.2f", pEmpleado->salario);
							retorno = 0;
						}
					break;
					case 4:
						eSector_mostrarTodos(arraySector, TAM2, &cantidadSector);
						eSector_buscarIdMaximo(arraySector, TAM2, &idMaximoSector);
						if(!utn_pedirEntero(&pEmpleado->sector, "\nIngrese el ID del sector: \n", "\nError\n", 1, idMaximoSector, 2, 1))
						{
							if(!eSector_buscarIndicePorId(arraySector, TAM2, pEmpleado->sector, &indiceSector))
							{
								retorno = 0;
							}
							else
							{
								if(eSector_buscarIndicePorId(arraySector, TAM2, pEmpleado->sector, &indiceSector)== 1)
								{
									puts("\nSector dado de baja.");
								}
							}
						}
					break;
					case 5: // salir
						eConjuntos_mostrarUno(pEmpleado, arraySector, TAM2);
						if(!utn_verificar("\n¿Modificación terminada? [s/n]", "Error", 2))
						{
							retorno = 1;
						}
					break;
				}
			}

		}while(retorno != 1);
	}

	return retorno;
}

int eConjuntos_Modificacion(eEmpleado arrayEmpleado[], int TAM1, eSector arraySector[], int TAM2)
{
	int retorno = -2; //ERROR;
	int idEmpleado;
	int indice;
	int respuesta;
	int idMaximo;
	int flag = 0;
	eEmpleado auxiliar;
	if(arrayEmpleado != NULL && TAM1 > 0 && arraySector != NULL && TAM2 > 0)
	{
		if(!eConjuntos_mostrarTodos(arrayEmpleado, TAM1, arraySector, TAM2))
		{
			flag = 1;
		}
		if (flag)
		{
			eEmpleado_buscarIdMaximo(arrayEmpleado, TAM1, &idMaximo);
			if(!utn_pedirEntero(&idEmpleado, "\nIngrese el ID del Empleado que quiere modificar", "\nError", 1, idMaximo, 2, 1))
			{
				respuesta = eEmpleado_buscarIndicePorId(arrayEmpleado, TAM1, idEmpleado, &indice);
				switch (respuesta)
				{//////////////////////////////////////////////////////////////////////////////
					case -2: //ERROR
						retorno = -2;
					break;
					case 0: //OCUPADO
						auxiliar = arrayEmpleado[indice];
						eConjuntos_mostrarUno(&auxiliar, arraySector, TAM2);
						eConjuntos_modificarUno(&auxiliar, arraySector, TAM2);
						if(!utn_verificar("\n¿Desea confirmas la modificación?[s/n]?\n", "nError", 2))
						{
							arrayEmpleado[indice]= auxiliar;
							retorno = 0; //MODIFICADO CORRECTAMENTE.
						}
						else
						{
							retorno = -1; // MODIFICACION CANCELADA
						}
					break;
					case 1: //BAJA
						retorno = 1; // Empleado  DADO DE BAJA
					break;
				}
			}
			else
			{
				printf("ID no existe.");
			}
		}
	}
	return retorno;
}

int eConjuntos_SortSectorEmpleados(eSector listaSector[], int tamSector, eEmpleado listaEmpleados[], int tamEmpleados)
{
	int retorno = -1; //ERROR. o no hay empleados.
	int i;
	int j;
	if(listaEmpleados != NULL && listaSector != NULL && tamEmpleados > 0 && tamSector > 0 &&
	   !eEmpleado_isEmpty(listaEmpleados, tamEmpleados) &&
	   !eEmpleado_SortApellidos(listaEmpleados, tamEmpleados) &&
	   !eSector_SortSector(listaSector, tamSector))
	{
		retorno = 0; // ok
		for(i=0; i<tamSector; i++)
		{
			if(listaSector[i].isEmpty == OCUPADO)
			{
				printf("\n \t %-15s \n\n", listaSector[i].descripcion);
				for(j=0; j<tamEmpleados; j++)
				{
					if(listaEmpleados[j].sector == listaSector[i].idSector
					   && listaEmpleados[j].isEmpty == OCUPADO && listaSector[i].isEmpty == OCUPADO)
					{
						eConjuntos_mostrarUno(&listaEmpleados[j], listaSector, tamEmpleados);
					}
				}
			}
		}
	}
	return retorno;
}

