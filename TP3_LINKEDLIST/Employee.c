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

//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParameters(char* nombreStr, char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;

    pEmployee = employee_new();

    if(pEmployee != NULL)
    {//hacer anidads de if
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

    if(this!= NULL && id > 0)
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
