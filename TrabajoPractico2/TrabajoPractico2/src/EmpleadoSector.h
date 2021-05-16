/*
 * EmpleadoSector.h
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */

#ifndef EMPLEADOSECTOR_H_
#define EMPLEADOSECTOR_H_

#include "Sector.h"
#include "ArrayEmpleados.h"

int eConjuntos_cargarDatos(eEmpleado* pEmpleado, eSector arraySector[], int TAM2);
int eConjuntos_alta(eEmpleado arrayEmpleados[], int TAM1, eSector arraySector[], int TAM2);
int eConjuntos_mostrarUno(eEmpleado* pEmpleado, eSector arraySector[], int TAM2);
int eConjuntos_mostrarTodos(eEmpleado arrayEmpleado[], int TAM1, eSector arraySector[], int TAM2);
int eConjuntos_baja(eEmpleado arrayEmpleado[], int TAM1, eSector arraySector[], int TAM2);
int eConjuntos_modificarUno(eEmpleado* pEmpleado, eSector arraySector[], int TAM2);
int eConjuntos_Modificacion(eEmpleado arrayEmpleado[], int TAM1, eSector arraySector[], int TAM2);
int eConjuntos_Sort(eEmpleado array[], int TAM, int criterio);

int eConjuntos_SortSectorEmpleados(eSector listaSector[], int tamSector, eEmpleado listaEmpleados[], int tamEmpleados);

#endif /* EMPLEADOSECTOR_H_ */
