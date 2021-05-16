/*
 * aEmpleadoEmpleados.c
 *
 *  Created on: 11 may. 2021
 *      Author: jessica
 */

#include "ArrayEmpleados.h"



static int Empleado_idIncremental =  5;

/*funcion que carga datos para probar el codigo
 * aEmpleado es el array a cargar datos.
 * Tam tamaño del array
 * */
void eEmpleado_cargaAutomaticaEmpleado(eEmpleado aEmpleado[], int TAM)
{
	int id []= {1,2,3,4,5};
	char nombre[][MAX_CHARS_CADENAS]={"ana", "pepe", "luca", "dario", "maria"};
	char apellido[][MAX_CHARS_CADENAS]={"gomez", "bianchet", "martinez", "lopez", "suares"};
	float salario []= {90000, 20000, 150000, 190000, 300000};
	int sector []= {1,1,5,5,5};

	int i;
	if(aEmpleado != NULL && TAM > 0)
	{
		for(i=0; i<TAM; i++)
		{
			aEmpleado[i].id = id[i];
			strcpy(aEmpleado[i].nombre, nombre[i]);
			strcpy(aEmpleado[i].apellido, apellido[i]);
			aEmpleado[i].salario = salario[i];
			aEmpleado[i].sector = sector[i];
			aEmpleado[i].isEmpty = OCUPADO;
		}
	}
}

/*funcion que inicializa con libre el array de empleados.
 * aEmpleado puntero que recibe la funcion para inicializar.
 * TAM tamaño del array.
 * retorna -1 en caso de error y 0 si no hay error.
 * */
int eEmpleado_inicializar(eEmpleado* aEmpleado, int TAM)
{
	int retorno = -1;
	int i;

	if (aEmpleado != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			aEmpleado[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

/*funcion que incrementa el ID cada vez que es invocada
 * retorna el ID incrementado.
 * */
int eEmpleado_obtenerID()
{
	return Empleado_idIncremental += 1;
}

/*funcion que da un indice libre del array que recibe
 * aEmpleado, array que recibe la funcion para buscar su primer indice libre
 * TAM tamaño del array aEmpleado
 * retorna -1 si hubo un error, -2 si el array esta lleno y si devuelve mayor a cero es el indice encontrado.
 * */
int eEmpleado_obtenerIndiceLibre(eEmpleado aEmpleado[], int TAM)
{
	int retorno = -1; //ERROR
	int i;
	if (aEmpleado != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (aEmpleado[i].isEmpty == LIBRE) {
				retorno = i;// retorna indice libre.
				break;
			}
			retorno = -2; //aEmpleado lleno
		}
	}
	return retorno;
}


/*funcion que recibe como parametro a la lista de empleados y todos los datos a cargar
 *lista, puntero recibido que se devuelve cargado de los datos recibidos
 *indice, representa al indice de la lista que va a ser cargado
 *id, dato decibido para cargar
 *nombre cadena decibida para cargar
 *apellido cadena decibida para cargar
 *salario dato decibido para cargar
 *sector dato decibido para cargar
 *  retorna -1 en caso de error y 0 si no hay error.
 * */
int eEmpleado_agregarEmpleado(eEmpleado* lista, int indice, int id, char nombre[], char apellido[], float salario, int sector)
{
	int retorno=-1;
	if(lista != NULL && nombre != NULL && apellido != NULL && indice > 0 && salario > 0 && sector > 0)
	{
		lista[indice].id = id;
		strncpy(lista[indice].nombre, nombre, MAX_CHARS_CADENAS);
		strncpy(lista[indice].apellido, apellido, MAX_CHARS_CADENAS);
		lista[indice].salario = salario;
		lista[indice].sector = sector;
		lista[indice].isEmpty = OCUPADO;
		retorno = 0;
	}
	return retorno;
}

/*funcion que busca en indice por el ID recibido
 * aEmpleado array recibido en el que se va a buscar el ID para encontrar el indice
 * TAM tamaño del array aEmpleado
 * id ID recibido que va a ser comparado
 * indiceEncontrado puntero en cual va a indicar el indice encontrado.
 * retorna -2 en caso de error, -1 si no se encuentra ningun indice con ese ID ,
 * 0 si se encontro el indice con el espacio isEmpty ocupado y 1 si se encontro el indice con un empleado dado de baja.
 * */
int eEmpleado_buscarIndicePorId(eEmpleado aEmpleado[], int TAM, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (aEmpleado != NULL && TAM > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Empleados con ese ID
		for (i = 0; i < TAM; i++)
		{
			if (aEmpleado[i].id == id && aEmpleado[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Empleados ocupado
				break;
			}
			else
			{
				if(aEmpleado[i].id == id && aEmpleado[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Empleados dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

/*funcion que muestra un empleado
 * pEmpleado recibe el puntero empleado del cual va a tomar los datos a mostrar.
 * retorna -1 si hubo error y 0 si no hubo error.
 * */
int eEmpleado_mostrarUno(eEmpleado* pEmpleado)
{
	int retorno = -1; //error.
	if(pEmpleado != NULL)
	{
		retorno = 0; //bien.

		printf("ID:#%-4d nombre:%-15s apellido:%-15s salario:%-.2f  --  ID sector:#%-4d \n", pEmpleado->id,
																						     pEmpleado->nombre,
																						     pEmpleado->apellido,
																						     pEmpleado->salario,
																						     pEmpleado->sector);
	}
	return retorno;
}

/*funcion que muestra todos los empleados
 * aEmpleado array en el que se va a buscar los indices con el isEmpty ocupado para mostrar
 * TAM tamaño del array
 * cantidad puntero que va a guardar la cantidad de empleados que hay en total en actividad
 * retorna -1 si no hay nada mara mostrar y 0 si hay para mostrar.
 *
 * */
int eEmpleado_mostrarTodos(eEmpleado aEmpleado[], int TAM, int* cantidad)//_DUDA_//
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aEmpleado != NULL && TAM > 0 && cantidad != NULL)
	{
		for (i = 0; i < TAM; i++)
		{
			if (aEmpleado[i].isEmpty == OCUPADO)
			{
				eEmpleado_mostrarUno(&aEmpleado[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (contador > 0) ///////////-------DUDA *------///////////////////////////
	{
		retorno = 0; //hay Empleados para mostrar.
	}

	return retorno;
}

/*funcion que busca ID maximo de los indices con isEmpty ocupado
 * miEmpleado array en el que se va a buscar el ID maximo
 * TAM tamaño del array
 * idMaximo puntero que va a guarda el id maximo encontrado.
 * */
int eEmpleado_buscarIdMaximo(eEmpleado miEmpleado[], int TAM, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(miEmpleado != NULL && idMaximo !=NULL)
	{
		for(i=0; i<TAM; i++)
		{
			if((i == 0 || miEmpleado[i].id > *idMaximo) && miEmpleado[i].isEmpty == OCUPADO)
			{
				*idMaximo = miEmpleado[i].id;
				retorno= 0;
			}
		}
	}
	return retorno;
}

/*funcion que va a ordenar a los empleados con el apellido de forma alfabetica
 * listaEmpleados es el array que va a ser ordenado
 * tamEmpleado tamaño del array
 * retorna -1 en caso de error y 0 si no hubo error
 * */
int eEmpleado_SortApellidos(eEmpleado listaEmpleados[], int tamEmpleados)
{
	int retorno = -1;
	int i;
	int j;
	eEmpleado auxiliar;

	if(listaEmpleados != NULL && tamEmpleados > 0)
	{
		retorno = 0;
		for(i=0; i<tamEmpleados-1; i++)
		{
			for(j=i+1; j<tamEmpleados; j++)
			{
				if(strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido)>0)
				{
					auxiliar= listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliar;
				}
			}
		}
	}
	return retorno;
}

//Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
/*funcion que va a realizar el calculo del salario promedio y total de salario,
 * listaEmpleados array del que se toman los datos
 * tamEmpleado tamaño del array
 * totalSalarios puntero que guarda el total de los salarios
 * salarioPromedio puntero que va a guardar el salario promedio
 * contadorEmpleadosSalProm cuenta la cantidad de empleados que superan el salario promedio
 * retorna -1 en caso de error y
 * */
int eEmpleados_TotalPromedioSalario(eEmpleado listaEmpleados[], int tamEmpleado, float* totalSalarios, float* salarioPromedio, int* contadorEmpleadosSalProm)
{
	int retorno = -1;
	int contador = 0;
	float acumulador=0;
	int i;
	if(listaEmpleados != NULL && totalSalarios !=NULL && salarioPromedio != NULL && contadorEmpleadosSalProm != NULL && tamEmpleado >0)
	{
		for(i=0; i<tamEmpleado; i++)
		{
			if(listaEmpleados[i].isEmpty == OCUPADO)
			{
				acumulador += listaEmpleados[i].salario;
				contador ++;
			}
		}
		*salarioPromedio = acumulador/contador;
		printf("acumulador %f --- %d\n", acumulador, contador);
		*totalSalarios = acumulador;

		*contadorEmpleadosSalProm = eEmpleados_SalarioPromedio(listaEmpleados, tamEmpleado, *salarioPromedio);
	}
	return retorno;
}

/*funcion  que va a contar los empleados que superan el salario promedio
 * listaEmpleados array en que se va a realizar la busqueda,
 * tamEmplead tamaño del array
 * salarioPromedio salario a comparar con el salario de todos los empleados activos
 * */
int eEmpleados_SalarioPromedio(eEmpleado listaEmpleados[], int tamEmpleado, int salarioPromedio)
{
	int i;
	int contadorEmpleadosSalarioPromedio=0;

	if(listaEmpleados != NULL && tamEmpleado >0)
	{
		for(i=0;i<tamEmpleado;i++)
		{
			if(listaEmpleados[i].salario>salarioPromedio)
			{
				contadorEmpleadosSalarioPromedio ++;
			}
		}
	}
	return contadorEmpleadosSalarioPromedio;
}



