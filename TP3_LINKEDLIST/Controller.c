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
//int controller_addEmployee(LinkedList* pArrayListEmployee, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee employee;
    Employee* pEmployee;
    pEmployee = &employee;

    char* name;
    char hours[50];
    char salary[50];

    //AGREGAR VALIDACIONES
    getString(name, 50, "Nombre:", "Error...", 3);
    getNumber(hours, 50, "Horas trabajadas:", "Error...", 3);
    getNumber(salary, 50, "Salario:", "Error...", 3);
    pEmployee = employee_newParameters(name, hours, salary);
    ll_add(pArrayListEmployee, pEmployee);

    return 1;
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
    iEmployee = 3;// PEDIR EL DATO AL USUARIO

    len = ll_len(pArrayListEmployee);
    for(i = 0; i < len; i++)
    {
        if(iEmployee - 1 == i)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            break;
        }
    }

    //MODIFICAR COMO PEDIR DATO
    getInt(&editOption, " 1. Modificar el nombre \n 2. Modificar horas trabajadas\n 3. Modificar salario\n 4. CANCELAR \n Elegi una opcion: ", "Opcion invalida\n", 1, 4, 20);
    switch(editOption)
    {
    case 1:
        //PEDIR NUEVO NOMBRE
        strcpy(nameAux, "Ariel");
        if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1 )
        {
            employee_setNombre(pEmployee, nameAux);
            result = 1;
        }
        break;
    case 2:
        //PEDIR NUEVAS HORAS
        strcpy(hoursAux, "98");
        if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
        {
            employee_setSueldo(pEmployee, hoursAux);
            result = 1;
        }
        break;
    case 3:
        //PEDIR NUEVO SALARIO
        strcpy(salaryAux, "1500");
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

    return result;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int index;

    result = 0;

    index = 3;//preguntar al usuario que elemento de la lista quiere agregar

    if(pArrayListEmployee != NULL)
    {
        if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
        {
            ll_remove(pArrayListEmployee, index-1);
            result = 1;
        }
    }

    return result;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
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
            employee_getNombre(pEmployee, nameAux);
            employee_getHorasTrabajadas(pEmployee, &hoursAux);
            employee_getSueldo(pEmployee, &salaryAux);
            printf("%d) %s, %d, %d \n", i+1, nameAux, hoursAux, salaryAux);
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
