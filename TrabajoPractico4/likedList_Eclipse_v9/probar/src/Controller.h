
//******************************CARGAR DESDE LOS ARCHIVOS(TEXTO-BINARIO)******************************
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
//**********************************ALTA - MODIFICACION - BAJA(ABM)***********************************
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
//*****************************************LISTAR EMPLEADOS*******************************************
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
//*********************************GUARDAR EN ARCHIVOS (TEXTO-BINARIO)********************************
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
//****************************************************************************************************
int controller_buscarIdMaximo(LinkedList* pArrayListEmployee);
int controller_buscarPorId(LinkedList* pArrayListEmployee, int id);
int controller_mostrarTodos(LinkedList* pArrayListEmployee);
int controller_listaVacia(LinkedList* pArrayListEmployee);
//**************************************CONTROLAR ID***************************************************
int controller_saveLastID();
int controller_loadId();
int controller_saveID();

//*****************************************************************************************************
int controller_clonarParteDeLista(LinkedList* pArrayListEmployee);
