#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "getDataBase.h"

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*)malloc(sizeof(Employee));

    return pEmployee;
}

Employee* employee_newParameters(char* idStr, char* nombreStr, char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;

    pEmployee = employee_new();

    if(pEmployee != NULL)
    {//hacer anidads de if
        employee_setId(pEmployee, idStr);
        employee_setNombre(pEmployee, nombreStr);
        employee_setHorasTrabajadas(pEmployee, horasTrabajadasStr);
        employee_setSueldo(pEmployee, sueldoStr);
    }
    return pEmployee;
}

int employee_setId(Employee* this, char* id)
{
    int resultado;
    resultado = 0;

    if(this!= NULL)
    {

        this->id = atoi(id);
        resultado = 1;
    }
    return resultado;
}

int employee_getId(Employee* this, int* id)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && id != NULL)
    {
        *id = this->id;
        resultado = 1;
    }

    return resultado;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        resultado = 1;
    }
    return resultado;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        resultado = 1;
    }

    return resultado;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int resultado;
    resultado = 0;

    if(this!= NULL)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        resultado = 1;
        /*
        if(*horasTrabajadas > min && *horasTrabajadas < max)
        {

        }
        */

    }
    return resultado;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        resultado = 1;
    }

    return resultado;
}


int employee_setSueldo(Employee* this, char* sueldo)
{
    int resultado;
    resultado = 0;
    //VALIDACIONES
    if(this!= NULL && sueldo > 0)
    {
        this->sueldo = atoi(sueldo);
        resultado = 1;
    }
    return resultado;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        resultado = 1;
    }

    return resultado;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    /*
    int* pId1;
    int* pId2;
    */
    int id1;
    int* pId1;
    int id2;
    int* pId2;
    int result;
    pId1 = &id1;
    pId2 = &id2;

    result = 0;

    employee_getId(e1, pId1);
    employee_getId(e2, pId2);

    if( *pId1 > *pId2)
    {
        result = 1;
    }
    else
    {
        if(*pId1 < *pId2)
        {
            result = -1;
        }
    }
    return result;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    char nombreAux1[20];
    char nombreAux2[20];
    int result;

    result = 0;
    employee_getNombre(e1, nombreAux1);
    employee_getNombre(e2, nombreAux2);

    if(strcmp(nombreAux1, nombreAux2) > 0)
    {
        result = 1;
    }
    else
    {
        if(strcmp(nombreAux1, nombreAux2) < 0)
        {
            result = -1;
        }
    }
    return result;
}


int employee_CompareByHours(Employee* e1, Employee* e2)
{
    int hs1;
    int* pHs1;
    int hs2;
    int* pHs2;
    int result;
    pHs1 = &hs1;
    pHs2 = &hs2;

    result = 0;

    employee_getHorasTrabajadas(e1, pHs1);
    employee_getHorasTrabajadas(e2, pHs2);

    if( *pHs1 > *pHs2)
    {
        result = 1;
    }
    else
    {
        if(*pHs1 < *pHs2)
        {
            result = -1;
        }
    }
    return result;
}

int employee_CompareBySalary(Employee* e1, Employee* e2)
{
    int salary1;
    int* pSalary1;
    int salary2;
    int* pSalary2;
    int result;
    pSalary1 = &salary1;
    pSalary2 = &salary2;

    result = 0;

    employee_getSueldo(e1, pSalary1);
    employee_getSueldo(e2, pSalary2);

    if( *pSalary1 > *pSalary2)
    {
        result = 1;
    }
    else
    {
        if(*pSalary1 < *pSalary2)
        {
            result = -1;
        }
    }
    return result;
}
