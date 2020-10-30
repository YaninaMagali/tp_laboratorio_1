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

/*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int option;
    char charAux;
    int intAux;
    result = 0;
    int len;

    pedir empleado por numero en la lista (i + 1)
    buscarlo en la lista (for + if). Si lo encuentro, lo guardo en pEmpleado
    Hago un set del campo que necesito cambiar

    len = ll_len(pArrayListEmployee);
    for(i = 0; i < len; i++)
    {

    }


    //MODIFICAR COMO PEDIR DATO
    //option = pedirEntero(" 1. Modificar el nombre \n 2. Modificar horas trabajadas\n 3. Modificar salario\n 4. CANCELAR \n Elegi una opcion: ");
    switch(option)
    {
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;

    default:
        printf("Opcion invalida\n");
        break;
    }


    return result;
}
*/

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int index;

    result = 0;

    index = 3;//preguntar al usuario que elemento de la lista quiere agregar

    if(pArrayListEmployee != NULL)
    {
        ll_remove(pArrayListEmployee, index-1);
        result = 1;
    }

    return result;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    char nombreAux[20];
    int horasAux;
    int sueldoAux;
    Employee* pEmployee;
    int result;
    int len;
    int i;

    result = 0;

    if(pArrayListEmployee != NULL)
    {
        result = 1;
        len = ll_len(pArrayListEmployee);
        for(i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            //printf("%d)%s %d %d\n", i+1, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getNombre(pEmployee, nombreAux);
            employee_getHorasTrabajadas(pEmployee, &horasAux);
            employee_getSueldo(pEmployee, &sueldoAux);
            printf("%s, %d, %d \n", nombreAux, horasAux, sueldoAux);
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

