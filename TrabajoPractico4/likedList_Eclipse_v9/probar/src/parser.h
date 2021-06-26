#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


#define TAM_PARSE 10

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeSaveAsText(LinkedList* pArrayListEmployee, FILE* pFile);

int parser_EmployeeSaveAsBinary(LinkedList* pArrayListEmployee, FILE* pFile);
