//permite cargar desde texto
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

//permite cargar desde un archivo binario
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

//crear un empleado
int controller_addEmployee(LinkedList* pArrayListEmployee);

//editar un empleado
int controller_editEmployee(LinkedList* pArrayListEmployee);


//editar un empleado
int controller_removeEmployee(LinkedList* pArrayListEmployee);

//listar un empleado
int controller_ListEmployee(LinkedList* pArrayListEmployee);

//ordenar un empleado
int controller_sortEmployee(LinkedList* pArrayListEmployee);

//salvar texto
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

//salvar binario
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//------------------------------------------------------------------------------------------------
int controller_menu(int* opcion);
int controller_buscarIdMaximo(LinkedList* pArrayListEmployee);
int controller_buscarPorId(LinkedList* pArrayListEmployee, int id);
