#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define TAM_NOMBRE 128
#define TAM_OTROS 30
typedef struct
{
    int id;
    char nombre[TAM_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//crear funciones de ordenamiento aca

int employee_compareBbyName(void* elemento1, void* elemento2);
int employee_compareBbyId(void* elemento1, void* elemento2);

#endif // employee_H_INCLUDED
