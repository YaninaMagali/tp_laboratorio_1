#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno;
    retorno = 0;
    pFile = fopen(path,"r");

    if(path != NULL
       && pArrayListEmployee != NULL
       && parser_EmployeeFromText(pFile, pArrayListEmployee, path) == 1)
       {
           retorno = 1;
       }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
//int controller_addEmployee(LinkedList* pArrayListEmployee, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee employee;
    Employee* pEmployee;
    pEmployee = &employee;

    //AGREGAR VALIDACIONES
    pEmployee = employee_newParameters("Juan", "40", "54321");
    ll_add(pArrayListEmployee, pEmployee);

    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int len;
    int i;
    Employee* pEmployee;

    result = 0;

    if(pArrayListEmployee != NULL)
    {
        result = 1;
        len = ll_len(pArrayListEmployee);
        for(i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            printf("%d)%s %d %d\n", i+1, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);
        }
    }

    return result;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    result = 0;

    if(addEmployeesToFile(pArrayListEmployee, path)==1)
    {
        result = 1;
    }
    return result;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

