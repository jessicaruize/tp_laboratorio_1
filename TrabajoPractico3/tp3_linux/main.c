#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"

int main()
{
	LinkedList* listaEmpleados;
	int opcion;
	int respuesta;
	char archivo[TAM_NOMBRE];
	listaEmpleados = ll_newLinkedList();
	//**************CARGA EL ARCHIVO ultimoID.bin CON EL ULTIMO ID QUE SE ENCUENTA EN EL ARCHIVO data.csv*********************
	//int numero;
	//numero = 1000;
	//controller_saveLastID(numero);
	//************************************************************************************************************************
	controller_loadId();
	do{
		if(!menu_principal(&opcion))
		{
			switch(opcion)
			{
				case 1:
					if(!utn_pedirAlfanumerico(archivo, TAM_NOMBRE, "Ingrese el nombre del archivo de texto: ", "Error.", 2))
					{
						strncat(archivo, ".csv", TAM_NOMBRE);
						respuesta = controller_loadFromText(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -3:
								puts("Error al abrir el archivo, asegurese que exista.");
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
					}
					break;
				case 2:
					if(!utn_pedirAlfanumerico(archivo, TAM_NOMBRE, "Ingrese el nombre del archivo binario: ", "Error.", 2))
					{
						strncat(archivo, ".bin", TAM_NOMBRE);
						respuesta = controller_loadFromBinary(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -3:
								puts("Error al abrir el archivo, asegurese que exista.");
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
					}
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
					puts("Aguarde por favor...");
					respuesta = controller_editEmployee(listaEmpleados);
					switch(respuesta)
					{
						case -4:
							puts("No hay elementos para editar.");
							break;
						case (-3 || -2):
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
					puts("Aguarde por favor...");
					respuesta = controller_removeEmployee(listaEmpleados);
					switch(respuesta)
					{
						case -5:
							puts("No hay empleados el la lista para eliminar.");
							break;
						case (-3 || -4):
							puts("ID no existe.");
							break;
						case -2:
							puts("Operación cancelada.");
							break;
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Empleado eliminado.");
							break;
					}
				break;
				case 6:
					respuesta = controller_ListEmployee(listaEmpleados);
					switch(respuesta)
					{
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Fin de la lista.");
							break;
						case 1:
							puts("No hay empleados para mostrar.");
							break;
					}
				break;
				case 7:
					respuesta = controller_sortEmployee(listaEmpleados);
					switch (respuesta)
					{
						case -3:
							puts("Lista vacia.");
							break;
						case -2:
							puts("Error al ingresar las opciones del menu.");
							break;
						case -1:
							puts("Error al realizar la operación.");
							break;
						case 0:
							puts("");
							break;
					}
				break;
				case 8:
					if(!utn_pedirAlfanumerico(archivo, TAM_NOMBRE, "Ingrese el nombre del archivo de texto: ", "Error.", 2))
					{
						strncat(archivo, ".csv", TAM_NOMBRE);
						puts("Aguarde por favor...");
						respuesta = controller_saveAsText(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -4:
								puts("Lista vacia. No se guardara nada.");
								break;
							case -3:
								puts("Operacion cancelada.");
								break;
							case -2:
								puts("Copia defectuosa. intente nuevamente.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Empleados cargados en el archivos de texto con exito.");
								break;
						}
					}
				break;
				case 9:
					if(!utn_pedirAlfanumerico(archivo, TAM_NOMBRE, "Ingrese el nombre del archivo binario: ", "Error.", 2))
					{
						strncat(archivo, ".bin", TAM_NOMBRE);
						puts("Aguarde por favor...");
						respuesta = controller_saveAsBinary(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -4:
								puts("Lista vacia. No se guardara nada.");
								break;
							case -3:
								puts("Operacion cancelada.");
								break;
							case -2:
								puts("Copia defectuosa. intente nuevamente.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Empleados cargados en el archivos binario con exito.");
								break;
						}
					}
				break;
				case 10:
					respuesta = menu_salir();
					if(!respuesta)
					{
						opcion = 1;
					}
					else
					{
						if(respuesta == -1)
						{
							opcion = 1;
							puts("Error al responder. Intente nuevamente.");
						}
					}
					puts("Gracias");
				break;
			}
		}
	}while(opcion != 10);
	controller_saveID();
    return 0;
}//FIN MAIN
