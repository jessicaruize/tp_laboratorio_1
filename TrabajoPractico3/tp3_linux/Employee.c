#include "Employee.h"

/** \brief crea un nuevo empleado en memoria dinamica.
 * \return int retorna la direccion del empleado si es que se creo o NULL.
 */
Employee* employee_new()
{
	Employee* empleado;
	empleado = (Employee*)malloc(sizeof(Employee));
	return empleado;
}
/** \brief crea un empleado y lo carga con los parametros..
 * \param char* idStr id a cargar en el empleado.
 * \param   char* nombreStr nombre a cargar en el empleado.
 * param   char* horasTrabajadasStr horas trabajadas a cargar en el empleado
 * param   char* sueldoStr sueldo a cargar en el empleado
 * \return   retorna la direccion del empleado si es que se creo o NULL..
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado;
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		empleado = employee_new();
		if(empleado != NULL)
		{
			employee_set(empleado, atoi(idStr), nombreStr, atoi(horasTrabajadasStr), atoi(sueldoStr));
		}
	}
	return empleado;
}
//*********************************************************************************************************************************************
/** \brief carga al empleado el id pasado por parametro.
 * \param   int id. ID a ser cargado en el empleado
 * \param   Employee* this. Direccion del empleado a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > -1)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el id del empleado pasado por parametro.
 * \param   int* id. ID a obtener.
 * \param   Employee* this. Direccion del empleado de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	//printf("id %d", *id);
	return retorno;
}
/** \brief carga al empleado el nombre pasado por parametro.
 * \param   char* nombre. Nombre a ser cargado en el empleado
 * \param   Employee* this. Direccion del empleado a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && strnlen(nombre, TAM_NOMBRE) > 0)
	{//if(utn_esAlfabetico(nombre, TAM_NOMBRE)==1)  ACEPTAR ESPACIOS??
		if(utn_esAlfabeticoEspacio(nombre, TAM_NOMBRE))
		{
			strncpy(this->nombre, nombre, TAM_NOMBRE);
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief obtiene el nombre del empleado pasado por parametro.
 * \param   char* nombre. nombre a obtener.
 * \param   Employee* this. Direccion del empleado de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre, this->nombre, TAM_NOMBRE);
	}
	return retorno;
}
/** \brief carga al empleado las horas trabajadas pasado por parametro.
 * \param   int id. Horas trabajadas a ser cargado en el empleado
 * \param   Employee* this. Direccion del empleado a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene las horas trabajadas del empleado pasado por parametro.
 * \param   int* horasTrabajadas. horas trabajadas a obtener.
 * \param   Employee* this. Direccion del empleado de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/** \brief carga al empleado el sueldo pasado por parametro.
 * \param   int sueldo. Sueldo a ser cargado en el empleado
 * \param   Employee* this. Direccion del empleado a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el sueldo del empleado pasado por parametro.
 * \param   int* sueldo. Sueldo a obtener.
 * \param   Employee* this. Direccion del empleado de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
//*********************************************************************************************************************************************
/** \brief compara los nombres de los empleados recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los nombres son iguales.
 * 					 ( 1 ) si nombre1 es mayor a nombre2.
 * 					 ( -1 ) si nombre2 es mayor a nombre1.
 * 					 (-2) error.
 */
int employee_compareBbyName(void* elemento1, void* elemento2)
{
	int comparacion = -2;
	int aux;
	Employee* empleado1;
	Employee* empleado2;
	char nombre1[TAM_NOMBRE];
	char nombre2[TAM_NOMBRE];
	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleado1 = (Employee*)elemento1;
		empleado2 = (Employee*)elemento2;
		employee_getNombre(empleado1, nombre1);
		employee_getNombre(empleado2, nombre2);
		aux = strncmp(nombre1, nombre2, TAM_NOMBRE);
		comparacion = 0;
		if(aux > 0)
		{
			comparacion = 1;
		}
		else
		{
			if(aux < 0)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}
/** \brief compara los id de los empleados recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los id's son iguales.
 * 					 ( 1 ) si id1 es mayor a id2.
 * 					 ( -1 ) si id2 es mayor a id1.
 * 					 (-2) error.
 */
int employee_compareBbyId(void* elemento1, void* elemento2)
{
	int comparacion = -2; //error
	Employee* empleado1;
	Employee* empleado2;
	int id1;
	int id2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleado1 = (Employee*)elemento1;
		empleado2 = (Employee*)elemento2;
		employee_getId(empleado1, &id1);
		employee_getId(empleado2, &id2);
		comparacion = 0;
		if(id1>id2)
		{
			comparacion = 1; // id 1 mayor
		}
		else
		{
			if(id2>id1)
			{
				comparacion = -1; //id2 mayor
			}
		}
	}
	return comparacion;
}
/** \brief compara las horas trabajadas de los empleados recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los horas son iguales.
 * 					 ( 1 ) si horas1 es mayor a horas2.
 * 					 ( -1 ) si horas2 es mayor a horas1.
 * 					 (-2) error.
 */
int employee_compareBbyHoras(void* elemento1, void* elemento2)
{
	int comparacion = -2; //error
	Employee* empleado1;
	Employee* empleado2;
	int horas1;
	int horas2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleado1 = (Employee*)elemento1;
		empleado2 = (Employee*)elemento2;
		employee_getHorasTrabajadas(empleado1, &horas1);
		employee_getHorasTrabajadas(empleado2, &horas2);
		comparacion = 0;
		if(horas1>horas2)
		{
			comparacion = 1; // horas 1 mayor
		}
		else
		{
			if(horas2>horas1)
			{
				comparacion = -1; //horas2 mayor
			}
		}
	}
	return comparacion;
}
/** \brief compara los sueldo de los elementos recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los sueldo son iguales.
 * 					 ( 1 ) si sueldo1 es mayor a sueldo2.
 * 					 ( -1 ) si sueldo2 es mayor a sueldo1.
 * 					 (-2) error.
 */
int employee_compareBbySueldo(void* elemento1, void* elemento2)
{
	int comparacion = -2; //error
	Employee* empleado1;
	Employee* empleado2;
	int sueldo1;
	int sueldo2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleado1 = (Employee*)elemento1;
		empleado2 = (Employee*)elemento2;
		employee_getSueldo(empleado1, &sueldo1);
		employee_getSueldo(empleado2, &sueldo2);
		comparacion = 0;
		if(sueldo1>sueldo2)
		{
			comparacion = 1; // sueldo 1 mayor
		}
		else
		{
			if(sueldo2>sueldo1)
			{
				comparacion = -1; //sueldo 2 mayor
			}
		}
	}
	return comparacion;
}
//*********************************************************************************************************************************************
/** \brief Muesta un empleado.
 * \param  Employee* empleado.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_mostrarUno(Employee* empleado)
{
	int retorno = -1;
	char nombre[TAM_NOMBRE];
	int id;
	int hs;
	int sueldo;
	if(!employee_getId(empleado, &id) &&
	   !employee_getNombre(empleado, nombre) &&
	   !employee_getHorasTrabajadas(empleado, &hs) &&
	   !employee_getSueldo(empleado, &sueldo))
	{
		printf("%10d %16s %15d %18d\n", id, nombre, hs, sueldo);
		retorno = 0;
	}
	return retorno;
}
/** \brief Carga al empleado con los datos recibidos.
 * \param  Employee* empleado. puntero al empleado a cargar.
 * \param int id. ID a cargar en el campo id del empleado.
 * \param char* nombre. nombre a cargar en el campo nombre del empleado.
 * \param int horasTrabajadas. horas trabajadas a cargar en el campo horasTrabajadas del empleado.
 * \param int sueldo. sueldo a cargar en el campo sueldo del empleado.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_set(Employee* empleado, int id, char* nombre, int horasTrabajadas, int sueldo)
{
	int retorno = -1;
	if(empleado != NULL && nombre != NULL && id > 0 && horasTrabajadas > 0 && sueldo > 0)
	{
		if(!employee_setNombre(empleado, nombre) &&
		   !employee_setId(empleado, id) &&
		   !employee_setHorasTrabajadas(empleado, horasTrabajadas) &&
		   !employee_setSueldo(empleado, sueldo))
		{
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Carga un empleado con los datos pedidos al usuario.
 * \param  Employee* empleado. puntero al empleado a cargar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int Employee_cargarDatos(Employee* empleado)
{
	int retorno = -1;
	char nombre[TAM_NOMBRE];
	int sueldo;
	int horasTrabajadas;
	int id;
	if(empleado != NULL)
	{

		employee_getId(empleado, &id);
		if(!utn_pedirAlfabeticoEspacio(nombre, TAM_NOMBRE, "Ingrese el nombre del empleado: ", "Error.\n", 2) &&
		!utn_pedirEntero(&horasTrabajadas, "Ingrese las horas trabajadas del empleado: ", "Error.\n", 0, 0, 2, 0) &&
		!utn_pedirEntero(&sueldo, "Ingrese el sueldo del empleado: ", "Error.\n", 0, 0, 2, 0))
		{
			employee_set(empleado, id, nombre, horasTrabajadas, sueldo);
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Edita nombre un empleado con los datos pedidos al usuario.
 * \param  Employee* empleado.puntero al empleado a editar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_editName(Employee* empleado)
{
	int retorno = -1;
	char nombre[TAM_NOMBRE];
	if (empleado != NULL &&
		!utn_pedirAlfabeticoEspacio(nombre, TAM_NOMBRE, "Ingrese el nombre: ", "Error.\n", 2) &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!employee_setNombre(empleado, nombre))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief Edita hs. trabajadas un empleado con los datos pedidos al usuario.
 * \param  Employee* empleado. puntero al empleado a editar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_editWorkingHours(Employee* empleado)
{
	int retorno = -1;
	int horas;
	if (empleado != NULL &&
	    !utn_pedirEntero(&horas, "Ingrese las horas trabajadas: ", "Error\n", 0, 0, 2, 0) &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!employee_setHorasTrabajadas(empleado, horas))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief Edita salario un empleado con los datos pedidos al usuario.
 * \param  Employee* empleado. puntero al empleado a editar
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_editSalary(Employee* empleado)
{
	int retorno = -1;
	int sueldo;
	if (empleado != NULL &&
	    !utn_pedirEntero(&sueldo, "Ingrese el sueldo: ", "Error\n", 0, 0, 2, 0) &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!employee_setSueldo(empleado, sueldo))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief pregunta si desea editar algun dato.
 * \param  Employee* empleado. puntero al empleado a mostrar
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_saveEdit(Employee* empleado)
{
	int retorno = -1;
	int respuesta;
	if (empleado != NULL)
	{
		puts("El empleado elegido se guardara con estos datos: ");
		puts("\n\tID\t   NOMBRE\t   HS. TRABAJADAS\t SUELDO");
		employee_mostrarUno(empleado);
		puts("\n");
		respuesta = utn_verificar("¿Desea cambiar algún dato? ", "Error, ingrese [s/n]\n", 2);
		if(!respuesta)
		{
			retorno = 1; // seguir editando
		}
		else
		{
			if(respuesta == 1)
			{
				retorno = 0; //se guardan los datos como estan.
			}
		}
	}
	return retorno;
}
/** \brief edita al empleado
 * \param  Employee* empleado. puntero al empleado a editar
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_editEmployee(Employee* empleado)
{
	int retorno = -1;
	int respuesta;
	int seguir;
	if(empleado != NULL)
	{
		do
		{//hacer get.
			puts("\nEmpleado seleccionado: ");
			puts("\n\tID\t   NOMBRE\t   HS. TRABAJADAS\t SUELDO");
			employee_mostrarUno(empleado);
			if(!menu_edit(&respuesta))
			{
				switch(respuesta)
				{
					case 1:
						if (!employee_editName(empleado))
						{
							retorno = 0;
						}
						break;
					case 2:
						if (!employee_editWorkingHours(empleado))
						{
							retorno = 0;
						}
						break;
					case 3:
						if (!employee_editSalary(empleado))
						{
							retorno = 0;
						}
						break;
					case 4:
						seguir = employee_saveEdit(empleado);
						if(seguir == 1)
						{
							respuesta = 1; //Seguir editando.
						}
						else
						{
							if(!seguir)
							{
								retorno = 0;
							}
						}
						break;
				}
			}
		}while(respuesta != 4);
	}
    return retorno;
}
/** \brief elimina al empleado.
 * \param  Employee* empleado. puntero al empleado a eliminar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int employee_delete(Employee* this)
{
	int retorno =-1;
	if(this != NULL)
	{
		free(this);
		this = NULL;
		retorno = 0;
	}
	return retorno;
}
