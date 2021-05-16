/*
 ============================================================================
 Author      : Ruiz Jessica
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "Sector.h"
#include "ArrayEmpleados.h"
#include "EmpleadoSector.h"

#define TAM_EMPLEADO 1000
#define TAM_SECTOR 10

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	//int criterioDeOrdenamiento;
	int bufferRespuestas;
	float totalSalarios;
	float promedioSalarios;
	int EmpleadosSalariosPromedio;

	eSector Sector[TAM_SECTOR];
	eSector_inicializar(Sector, TAM_SECTOR);
	eSector_cargaAutomaticaSector(Sector, 5);

	eEmpleado Empleado[TAM_EMPLEADO];
	eEmpleado_inicializar(Empleado, TAM_EMPLEADO);
	eEmpleado_cargaAutomaticaEmpleado(Empleado, 5);

	do {
		printf("\nMENU: \n1_Alta.\n2_Baja.\n3_Modificación\n4_Listado productos\n0_Salir.\n");
		if(!utn_pedirEntero(&opcion, "\nIngrese el numero correstpondiente a la acción que desea realizar: \n", "Error.\n", 0, 7, 2, 1))
		{
			printf("\nOpción elegida: %d\n", opcion);
			switch (opcion)
			{
				case 0:
					bufferRespuestas = utn_verificar("¿Desea salir [s/n]?", "Error.\n", 2);
					if(bufferRespuestas == 0)
					{
						opcion = 50; //si
					}
					break;
				case 1:
					//ALTA
					bufferRespuestas = eConjuntos_alta(Empleado, TAM_EMPLEADO, Sector, TAM_SECTOR);
					switch (bufferRespuestas)
					{
					case -2:
						puts("No hay espacio para guardar otro Empleado.\n");
					break;
					case -1:
						puts("Error.\n");
					break;
					case 0:
						puts("\nAlta exitosa.\n");
						eConjuntos_mostrarTodos(Empleado, TAM_EMPLEADO, Sector, TAM_SECTOR);
					break;
					case 1:
						puts("Operacion cancelada con exito.\n");
					break;
					}
				break;
				case 2:
					//BAJA
					bufferRespuestas = eConjuntos_baja(Empleado, TAM_EMPLEADO, Sector, TAM_SECTOR);
					switch (bufferRespuestas)
					{
					case -2:
						printf("5656");
						puts("Error.\n");
					break;
					case -1:
						bufferRespuestas = utn_verificar("ID no existe.\n¿Desea salir?\n [s/n]", "Error.\n", 2);
						if(bufferRespuestas == 1)
						{
							opcion = 50; //si
						}
					break;
					case 0:
						puts("Baja exitosa.\n");
					break;
					case 1:
						puts("Empleado ya dado de baja.\n");
					break;
					case 2:
						printf("\nBaja cancelada \n\n.");
					break;
					}

				break;
				case 3: //MODIFICACION
					opcion = eConjuntos_Modificacion(Empleado, TAM_EMPLEADO, Sector, TAM_SECTOR);
					switch(opcion)
					{
						case -2:
							printf("\nError.");
						break;
						case -1:
							printf("\nModificación cancelada.");
						break;
						case 0:
							printf("\nModificación exitosa.");
						break;
						case 1:
							printf("\nEmpleado dado de baja, no se puede modificar.");
						break;
					}
				break;
				case 4: //ordenado por apellido y sector
					puts("LISTAS: \n1_Empleados por apellido.\n2_Empleados por sector.\n3_Información salarios");
					utn_pedirEntero(&bufferRespuestas, "Ingrese el número correspondiente a la opción que desea realizar: ", "Error.", 1, 5, 2, 1);
					switch(bufferRespuestas)
					{
						case 1:
							eEmpleado_SortApellidos(Empleado, TAM_EMPLEADO);
							eConjuntos_mostrarTodos(Empleado, TAM_EMPLEADO, Sector, TAM_SECTOR);
						break;
						case 2:
							eConjuntos_SortSectorEmpleados(Sector, TAM_SECTOR, Empleado, TAM_EMPLEADO);

						break;
						case 3:
							eEmpleados_TotalPromedioSalario(Empleado, TAM_EMPLEADO, &totalSalarios, &promedioSalarios, &EmpleadosSalariosPromedio);
							//Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
							printf("El total de los salarios es: $%.2f.\nEl promedio de los salarios es: $%.2f.\nLos empleados que superan el salario peromedio son: %d",totalSalarios, promedioSalarios, EmpleadosSalariosPromedio);
					}
				break;
			}
		}
	}while(opcion != 50);
	printf("Gracias.");
	return EXIT_SUCCESS;
}
