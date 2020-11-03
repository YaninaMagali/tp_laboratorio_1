#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "getDataBase.h"

/** \brief Crea y devuelve un puntero de tipo Employee en una direccion de memoria del heap
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* pEmployee  = NULL;

    pEmployee = (Employee*)malloc(sizeof(Employee));

    return pEmployee;
}


/** \brief Devuelve un puntero empleado con datos cargados
 *
 * \param idStr char* Recibe Id empleado
 * \param nombreStr char* Recibe nombre del empleado
 * \param horasTrabajadasStr char* Recibe horas trabajadas por empleado
 * \param sueldoStr char* Recibe sueldo del empleado
 * \return Employee*
 *
 */
Employee* employee_newParameters(char* idStr, char* nombreStr, char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee = NULL;

    pEmployee = employee_new();

    if(pEmployee != NULL)
    {
        if(employee_setId(pEmployee, idStr) == 1)
        {
            if(employee_setNombre(pEmployee, nombreStr) == 1)
            {
                if(employee_setHorasTrabajadas(pEmployee, horasTrabajadasStr) == 1)
                {
                    employee_setSueldo(pEmployee, sueldoStr);
                }
            }
        }
    }
    return pEmployee;
}

/** \brief Asigna un valor al campo id del empleado
 *
 * \param this Employee* Recibe un puntero de tipo empleado
 * \param id char* Recibe un puntero de tipo char
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief Obtiene el id de un usuario
 *
 * \param this Employee* Recibe un puntero de tipo Employee
 * \param id int* Recibe un puntero de tipo int donde se asigna el id obtenido
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief Asigna el nombre al campo nombre de la estructura empleado
 *
 * \param this Employee* Recibe el puntero a empleado para asignar el nombre
 * \param nombre char* Recibe puntero a char que obtiene el nombre a asignar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief
 *
 * \param this Employee* Recibe un puntero a empleado, del que va a obtener el nombre
 * \param nombre char* Recibe un puntero a char, donde se almacena el nombre obtenido
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief Asigna horas trabajadas para un empleado
 *
 * \param this Employee* Recibe un puntero a empleado donde se van a asignar las horas
 * \param horasTrabajadas char* Recibe un puntero a char, que contienen las horas que se van a asignar al empleado
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief
 *
 * \param this Employee* Recibe puntero a empleado de donde obtiene las horas trabajadas
 * \param horasTrabajadas int* Recibe un puntero a int, donde se va a almacenar el nuevo dato
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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


/** \brief Asigna el sueldo a un empleado
 *
 * \param this Employee* Recibe el sueldo que se le va a asignar
 * \param sueldo char* Recibe el nuevo valor a asignar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee* Recibe empleado del que obtiene el sueldo
 * \param sueldo int* Recibe donde se va a asignar el dato obtenido
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
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

/** \brief Compara dos empleados por id.
 *
 * \param e1 Employee* Recibe empleado 1
 * \param e2 Employee* Recibe empelado 2
 * \return int Si el id del primero es mayor al segundo, devuelve 1, si es al reves, devuelve -1, si son iguales devuelve 0
 *
 */
int employee_CompareById(Employee* e1, Employee* e2)
{
    int id1;
    int* pId1;
    pId1 = &id1;
    int id2;
    int* pId2;
    pId2 = &id2;
    int result;

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

/** \brief Compara dos empleados por nombre.
 *
 * \param e1 Employee* Recibe empleado 1
 * \param e2 Employee* Recibe empelado 2
 * \return int Si el id del primero es mayor al segundo, devuelve 1, si es al reves, devuelve -1, si son iguales devuelve 0
 *
 */
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


/** \brief Compara dos empleados por horas.
 *
 * \param e1 Employee* Recibe empleado 1
 * \param e2 Employee* Recibe empelado 2
 * \return int Si el id del primero es mayor al segundo, devuelve 1, si es al reves, devuelve -1, si son iguales devuelve 0
 *
 */
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

/** \brief Compara dos empleados por sueldo.
 *
 * \param e1 Employee* Recibe empleado 1
 * \param e2 Employee* Recibe empelado 2
 * \return int Si el id del primero es mayor al segundo, devuelve 1, si es al reves, devuelve -1, si son iguales devuelve 0
 *
 */
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
