/*
 * Sector.c
 *
 *  Created on: 14 may. 2021
 *      Author: jessica
 */



#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "Sector.h"

static int Sector_idIncremental =  5;

void eSector_cargaAutomaticaSector(eSector arraySector[], int TAM)
{
	char descripcion[][MAX_CHARS_CADENAS]={"Informatica", "Administración", "Logística", "Abastecimiento", "Dirección"};
	int id []= {1,2,3,4,5};

	int i;
	if(arraySector != NULL && TAM > 0)
	{
		for(i=0; i<TAM; i++)
		{
			strcpy(arraySector[i].descripcion , descripcion[i]);
			arraySector[i].idSector = id[i];
			arraySector[i].isEmpty = OCUPADO;
		}
	}
}

void eSector_inicializar(eSector arraySector[], int TAM)
{
	int i;
	if (arraySector != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			arraySector[i].isEmpty = LIBRE;
		}
	}
}

int eSector_obtenerID()
{
	return Sector_idIncremental += 1;
}

int eSector_obtenerIndiceLibre(eSector arraySector[], int TAM)
{
	int retorno = -1; //ERROR
	int i;
	if (arraySector != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arraySector[i].isEmpty == LIBRE) {
				retorno = i;// retorna indice libre.
				break;
			}
			retorno = -2; //array lleno
		}
	}
	return retorno;
}

int eSector_buscarIndicePorId(eSector arraySector[], int TAM, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (arraySector != NULL && TAM > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Sector con ese ID
		for (i = 0; i < TAM; i++)
		{
			if (arraySector[i].idSector == id && arraySector[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Sector ocupado
				break;
			}
			else
			{
				if(arraySector[i].idSector == id && arraySector[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Sector dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

int eSector_mostrarUno(eSector* pSector)
{
	int retorno = -1; //error.
	if(pSector != NULL)
	{
		retorno = 0; //bien.
		printf("Descripción:%-20s ID:%-4d\n", pSector->descripcion,
										       pSector->idSector);
	}
	return retorno;
}

int eSector_mostrarTodos(eSector arraySector[], int TAM, int* cantidad)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (arraySector != NULL && TAM > 0 && cantidad != NULL)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arraySector[i].isEmpty == OCUPADO)
			{
				eSector_mostrarUno(&arraySector[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (contador > 0)
	{
		retorno = 0; //hay Sector para mostrar.
	}

	return retorno;
}

int eSector_mostrarDadosDeBaja(eSector array[], int TAM, int* cantidad)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	puts("\n\t> LISTADO Sector");
	if (array != NULL && TAM > 0 && cantidad != NULL)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == BAJA)
			{
				eSector_mostrarUno(&array[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (cantidad > 0)
	{
		retorno = 0; //hay Sector dado de baja para mostrar.
	}

	return retorno;
}

int eSector_buscarIdMaximo(eSector miSector[], int TAM, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(miSector != NULL && idMaximo !=NULL)
	{
		for(i=0; i<TAM; i++)
		{
			if((i == 0 || miSector[i].idSector > *idMaximo) && miSector[i].isEmpty == OCUPADO)
			{
				*idMaximo = miSector[i].idSector;
				retorno= 0;
			}
		}
	}
	return retorno;
}


int eSector_cargarDatos(eSector* pArray)
{
	int retorno = -1;
	if(pArray != NULL)
	{

		if(!utn_pedirAlfabetico(pArray->descripcion, MAX_CHARS_CADENAS, "Ingrese nombre: ", "Error.\n", 2))
		{
			 retorno = 0;
		}
	}
	return retorno;
}

int eSector_modificarUno(eSector* Sector)
{
	int retorno = -1;
	int respuesta;
	do
	{
		printf("\n\n\tMODIFICAR: \n\n1_Descripción.\n2_Nacionalidad.\n3_Tipo \n4_Precio.\n5_Modificar otro dato.\n6_Salir.");
		if(!utn_pedirEntero(&respuesta, "\n\nIngrese la opción que desea realizar: ", "\nError", 1, 2, 2, 1))
		{
			retorno = 0;
			switch(respuesta)

			{
				case 1: //Descripcion
					utn_pedirAlfabetico(Sector->descripcion, MAX_CHARS_CADENAS, "Ingrese la descripcion: ", "Error", 2);
				break;
				case 2: // salir
					if(!utn_verificar("¿Desea salir? [s/n]", "Error", 2))
					{
						retorno = 2;
					}
				break;
			}
		}

	}while(retorno != 2);

	return retorno;
}


int eSector_alta(eSector arraySector[], int TAM)
{
	int retorno = -1; //ERROR
	eSector auxSector;
	int indice;
	if(arraySector != NULL && TAM > 0)
	{
		indice = eSector_obtenerIndiceLibre(arraySector, TAM);

		if (indice > -1 && (!eSector_cargarDatos(&auxSector)))
		{

			if(utn_verificar("¿Desea guardar los cambios[s/n]?", "Error", 2) == 0)
			{
				auxSector.idSector = eSector_obtenerID();
				auxSector.isEmpty = OCUPADO;
				arraySector[indice] = auxSector;
				retorno = 0; //se dio de alta satisfactoriamente
			}
			else
			{
				retorno = 1; //Operacion cancelada
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

int eSector_baja(eSector arraySector[], int TAM)
{
	int retorno = -2; //ERROR
	int idSector;
	int indice;
	int cantidadAltas;
	int idMaximo;
	int respuesta;
	eSector buffer;

	int flag = 0;
	if (eSector_mostrarTodos(arraySector, TAM, &cantidadAltas)==0)
	{
		flag = 1;
	}
	if (flag)
	{
		eSector_buscarIdMaximo(arraySector, TAM, &idMaximo);
		if(utn_pedirEntero(&idSector, "\nIngrese el ID del Sector que quiere dar de baja: \n", "\nError. \n", 1, idMaximo, 2, 1)==0)
		{

			respuesta = eSector_buscarIndicePorId(arraySector, TAM, idSector, &indice);
			switch (respuesta)
			{
				case -2: //ERROR
					retorno = -2;
				break;
				case 0: //OCUPADO
					buffer = arraySector[indice];
					eSector_mostrarUno(&buffer);
					if(utn_verificar("\n¿Desea dar de baja este Sector [s/n]?", "\nError", 2)==0)
					{
						arraySector[indice].isEmpty = BAJA; //baja logica.
						retorno = 0; //BAJA CORRECTAMENTE.
					}
					else
					{
						retorno = 2;
					}
				break;
				case 1: //BAJA
					retorno = 1; // Sector YA DADO DE BAJA
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

int eSector_Modificacion(eSector arraySector[], int TAM)
{
	int retorno = -2; //ERROR;
	int idSector;
	int indice;
	int cantidadSector;
	int respuesta;
	int idMaximo;
	int flag = 0;
	eSector auxiliar;
	if(arraySector != NULL && TAM > 0)
	{
		eSector_mostrarTodos(arraySector, TAM, &cantidadSector);
		if (cantidadSector>0)
		{
			flag = 1;
		}
		if (flag)
		{
			eSector_buscarIdMaximo(arraySector, TAM, &idMaximo);
			if(!utn_pedirEntero(&idSector, "\ningrese el ID del Sector que quiere modificar", "\nError", 1, idMaximo, 2, 1))
			{
				respuesta = eSector_buscarIndicePorId(arraySector, TAM, idSector, &indice);
				switch (respuesta)
				{
					case -2: //ERROR
						retorno = -2;
					break;
					case 0: //OCUPADO
						auxiliar = arraySector[indice];
						eSector_mostrarUno(&auxiliar);
						eSector_modificarUno(&auxiliar);
						if(!utn_verificar("\n¿Desea confirmas la modificación?[s/n]?\n", "nError", 2))
						{
							arraySector[indice]= auxiliar;
							retorno = 0; //MODIFICADO CORRECTAMENTE.
						}
						else
						{
							retorno = -1; // modificacion cancelada
						}
					break;
					case 1: //BAJA
						retorno = 1; // Sector  DADO DE BAJA
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

//descripcion alfabeticamente
int eSector_SortSector(eSector listaSector[] , int tamSector)
{
	int retorno = -1;
	int i;
	int j;
	eSector auxiliar;

	if(listaSector != NULL && tamSector > 0)
	{
		retorno = 0;
		for(i=0; i<tamSector-1; i++)
		{
			for(j=i+1; j<tamSector; j++)
			{
				if(strcmp(listaSector[i].descripcion, listaSector[j].descripcion)>0)
				{
					auxiliar= listaSector[i];
					listaSector[i] = listaSector[j];
					listaSector[j] = auxiliar;
				}
			}
		}
	}
	return retorno;
}
