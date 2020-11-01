#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "getDataBase.h"
#include "Controller.h"

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
    FILE* pFile;
    int result;

    result = 0;

    if(pArrayListEmployee != NULL
       && path != NULL)
    {
        pFile = fopen(path, "rb");
        if(parser_EmployeeFromBinary(pFile, pArrayListEmployee, path)== 1)
        {
            result = 1;
        }
    }

    return result;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    Employee employee;
    Employee* pEmployee;
    pEmployee = &employee;
    char id;
    char* pId;
    pId = &id;

    //char id[20];
    char name[50];
    char hours[50];
    char salary[50];
    result = 0;

    if(ll_isEmpty(pArrayListEmployee) == 1)
    {
        result = 0;
    }
    else
    {
        if(getLastId(pArrayListEmployee, pId)== 1)
        {
            printf("id %d\n",id);
            printf("&id %p\n",&id);
            printf("pid %p\n",pId);
            if(getString(name, 50, "Nombre:", "Error...", 3) == 1)
            {
                if(getNumber(hours, 50, "Horas trabajadas:", "Error...", 3) == 1)
                {
                    if(getNumber(salary, 50, "Salario:", "Error...", 3)== 1)
                    {
                        pEmployee = employee_newParameters(pId, name, hours, salary);
                        //pEmployee = employee_newParameters(*pId, name, hours, salary); // error compilacion
                        //pEmployee = employee_newParameters(&id, name, hours, salary); // 0
                        //pEmployee = employee_newParameters(id, name, hours, salary); // segm fault
                        ll_add(pArrayListEmployee, pEmployee);
                        result = 1;
                    }
                }
            }
        }
    }

    return result;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int iEmployee;
    int editOption;
    char nameAux[20];
    char hoursAux[20];
    char salaryAux[90];
    int i;
    int len;
    Employee employee;
    Employee* pEmployee;

    result = 0;
    pEmployee = &employee;

    if(getInt(&iEmployee, "Numero de orden del empleado a eliminar: ", "Error", 1, 99999, 3) == 1)
    {
        len = ll_len(pArrayListEmployee);
        for(i = 0; i < len; i++)
        {
            if(iEmployee - 1 == i)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                break;
            }
        }


        getInt(&editOption, " 1. Modificar el nombre \n 2. Modificar horas trabajadas\n 3. Modificar salario\n 4. CANCELAR \n Elegi una opcion: ", "Opcion invalida\n", 1, 4, 20);
        switch(editOption)
        {
        case 1:
            getString(nameAux, 20, "Nuevo nombre: ", "Error...\n", 3);
            if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1 )
            {
                employee_setNombre(pEmployee, nameAux);
                result = 1;
            }
            break;
        case 2:
            getString(hoursAux, 20, "Nuevo nombre: ", "Error...\n", 3);
            if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
            {
                employee_setSueldo(pEmployee, hoursAux);
                result = 1;
            }
            break;
        case 3:
            getString(salaryAux, 20, "Nuevo nombre: ", "Error...\n", 3);
            if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
            {
                employee_setSueldo(pEmployee, salaryAux);
                result = 1;
            }
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    }

    return result;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int index;

    result = 0;

    if(getInt(&index, "Numero de orden del usuario a eliminar", "Numero invalido", 1, 999999, 3) == 1)
    {
        if(pArrayListEmployee != NULL && index <= ll_len(pArrayListEmployee))
        {
            if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
            {
                ll_remove(pArrayListEmployee, index-1);
                result = 1;
            }
        }
    }

    return result;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int idAux;
    char nameAux[20];
    int hoursAux;
    int salaryAux;
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
            employee_getId(pEmployee, &idAux);
            employee_getNombre(pEmployee, nameAux);
            employee_getHorasTrabajadas(pEmployee, &hoursAux);
            employee_getSueldo(pEmployee, &salaryAux);
            printf("%d) %d, %s, %d, %d \n", i+1, idAux, nameAux, hoursAux, salaryAux);
        }
    }

    return result;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int sortOption;
    int result;
    result = 0;

    do
    {
            if(getInt(&sortOption, "\n 1. Ordenar por Id \n 2. Ordenar por nombre \n 3. Ordenar por horas \n 4. Ordenar por sueldo\n 5. Salir \n " ,"Opcion invalida\n", 1, 5, 20) == 1)
        {
            switch(sortOption)
            {
            case 1:
                ll_sort(pArrayListEmployee, employee_CompareById, 0);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_CompareByName, 0);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_CompareByHours, 0);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_CompareBySalary, 0);
                break;
            }
        }
    }
    while(sortOption!=5);

    return result;
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
    int result;
    FILE* pFile;
    result = 0;
    pFile = fopen(path, "wb");

    if(pArrayListEmployee != NULL
       && path != NULL)
    {
        addEmployeesToBinaryFile(pFile, pArrayListEmployee, path);
        result = 1;
    }

    return result;
}

/** \brief - Pide al usuario confirmacion para ejecutar una accion
 *
 * \param void - Recibe un puntero a char para cargar el mensaje que se le quiere mostrar al usuario
 * \return int - Si el usuario confirma, devuelve 1, sino un 0
 *
 */
int getUserAgreement(char* message)
{
    int result;
    char userAnswer;

    result = 0;

    printf(message);
    fflush(stdin);
    scanf("%c", &userAnswer);

    if(userAnswer == 's' || userAnswer == 'S')
    {
        result = 1;
    }

    return result;
}

int getLastId(LinkedList* pArrayListEmployee, char* id)
{
    int index;
    Employee* pEmployee;
    int result;
    int idAux;

    result = 0;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        index = (ll_len(pArrayListEmployee)-1);
        pEmployee = ll_get(pArrayListEmployee,index);
        employee_getId(pEmployee, &idAux);
        idAux = idAux +1;
        *id = idAux;
        result = 1;
    }

    return result;
}

