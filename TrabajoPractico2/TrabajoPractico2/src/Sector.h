/*
 * Sector.h
 *
 *  Created on: 14 may. 2021
 *      Author: jessica
 */


#ifndef SECTOR_H_
#define SECTOR_H_

#include "pedir_valores.h"
#include "operaciones_matematicas.h"

#define MAX_CHARS_CADENAS 51
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


typedef struct
{
	int idSector;
	char descripcion[MAX_CHARS_CADENAS];
	int isEmpty;
}eSector;


void eSector_cargaAutomaticaSector(eSector arraySector[], int TAM);
void eSector_inicializar(eSector arraySector[], int TAM);
int eSector_obtenerID();
int eSector_obtenerIndiceLibre(eSector arraySector[], int TAM);
int eSector_buscarIndicePorId(eSector arraySector[], int TAM, int id, int* indiceEncontrado);
int eSector_mostrarUno(eSector* pSector);
int eSector_mostrarTodos(eSector arraySector[], int TAM, int* cantidad);
int eSector_mostrarDadosDeBaja(eSector arraySector[], int TAM, int* cantidad);
int eSector_buscarIdMaximo(eSector miSector[], int TAM, int* idMaximo);
int eSector_cargarDatos(eSector* pArray);
int eSector_modificarUno(eSector* Sector);
int eSector_alta(eSector arraySector[], int TAM);
int eSector_baja(eSector arraySector[], int TAM);
int eSector_Modificacion(eSector arraySector[], int TAM);
int eSector_SortSector(eSector listaSector[] , int tamSector);

#endif /* SECTOR_H_ */
