#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

//llama a funciones de la biblioteca controller.

int main()
{
	LinkedList* listaEmpleados;
	int opcion = 1;
	int respuesta;

	listaEmpleados = ll_newLinkedList();
	do{
		if(!controller_menu(&opcion))
		{
			switch(opcion)
			{
				case 1:
					respuesta = controller_loadFromText("data.csv", listaEmpleados);
					switch (respuesta)
					{
						case -3:
							puts("No existe el archivo.");
							break;
						case -2:
							puts("Operación cancelada.");
							break;
						case -1:
							puts("Error al realizar la operación.");
							break;
						case 0:
							puts("Operación realizada con exito.");
							break;
					}
					break;
				case 2:
					controller_loadFromBinary("data.bin", listaEmpleados);
				break;
				case 3:
					respuesta = controller_addEmployee(listaEmpleados);
					switch (respuesta)
					{
						case -2:
							puts("Operación cancelada.");
							break;
						case -1:
							puts("Error al realizar la operación.");
							break;
						case 0:
							puts("Operación realizada con exito.");
							break;
					}
				break;
				case 4:
					respuesta = controller_editEmployee(listaEmpleados);
					switch(respuesta)
					{
						case -2:
							puts("ID invalido.");
							break;
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Operación exitosa.");
							break;
					}
				break;
				case 5:
					respuesta = controller_removeEmployee(listaEmpleados);
					switch(respuesta)
					{
						case -3:
							puts("ID no existe");
							break;
						case -2:
							puts("Operacion cancelada");
							break;
						case -1:
							puts("Error al procesar la operación");
							break;
						case 0:
							puts("Empleado eliminado.");
							break;
					}
				break;
				case 6:
					if(!controller_ListEmployee(listaEmpleados))
					{
						puts("\n Fin lista de empleados.");
					}
					else
					{
						puts("\n Error al listar empleados.");
					}
				break;
				case 7:
					controller_sortEmployee(listaEmpleados);
				break;
				case 8:
					if(!controller_saveAsText("datatxt.csv", listaEmpleados))
					{
						puts("Datos guardados con exito.");
					}
				break;
				case 9:
					if(!controller_saveAsBinary("data.bin", listaEmpleados))
					{
						puts("Datos guardados con exito.");
					}
				break;
				case 10:
					puts("Gracias");
				break;
			}
		}
	}while(opcion != 10);
    return 0;
}
