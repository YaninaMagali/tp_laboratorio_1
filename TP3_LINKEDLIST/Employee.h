#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
<<<<<<< HEAD
Employee* employee_newParameters(char* idStr, char* nombreStr, char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this, char* id);
int employee_getId(Employee* this, int* id);
=======
//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParameters(char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);
>>>>>>> 62c380ab7b047a4487f5fd1d6ed887ff99b870d6

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this, char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);
<<<<<<< HEAD
int employee_CompareByHours(Employee* e1, Employee* e2);
int employee_CompareBySalary(Employee* e1, Employee* e2);
=======
>>>>>>> 62c380ab7b047a4487f5fd1d6ed887ff99b870d6

#endif // employee_H_INCLUDED
