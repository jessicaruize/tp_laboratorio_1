/*
 * aEmpleadoEmpleados.h
 *
 *  Created on: 11 may. 2021
 *      Author: jessica
 */

#ifndef aEmpleadoEMPLEADOS_H_
#define aEmpleadoEMPLEADOS_H_

#include "pedir_valores.h"
#include "operaciones_matematicas.h"

#define MAX_CHARS_CADENAS 51
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


typedef struct
{
	int id;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	float salario;
	int sector;
	int isEmpty;
}eEmpleado;


void eEmpleado_cargaAutomaticaEmpleado(eEmpleado aEmpleado[], int TAM);
int eEmpleado_inicializar(eEmpleado* aEmpleado, int TAM);
int eEmpleado_obtenerID();

int eEmpleado_agregarEmpleado(eEmpleado* lista, int indice, eEmpleado aux);

int eEmpleado_obtenerIndiceLibre(eEmpleado aEmpleado[], int TAM);
int eEmpleado_buscarIndicePorId(eEmpleado aEmpleado[], int TAM, int id, int* indiceEncontrado);
int eEmpleado_mostrarUno(eEmpleado* pEmpleados);
int eEmpleado_mostrarTodos(eEmpleado aEmpleado[], int TAM, int* cantidad);
int eEmpleado_isEmpty(eEmpleado aEmpleado[], int TAM);
int eEmpleado_buscarIdMaximo(eEmpleado miEmpleados[], int TAM, int* idMaximo);
int eEmpleado_Sort(eEmpleado aEmpleado[], int TAM, int criterio);
int eEmpleado_SortApellidos(eEmpleado listaEmpleados[], int tamEmpleados);
int eEmpleados_TotalPromedioSalario(eEmpleado listaEmpleados[], int tamEmpleado, float* totalSalarios, float* salarioPromedio, int* contadorEmpleadosSalProm);
int eEmpleados_SalarioPromedio(eEmpleado listaEmpleados[], int tamEmpleado, int salarioPromedio);


#endif /* aEmpleadoEMPLEADOS_H_ */
