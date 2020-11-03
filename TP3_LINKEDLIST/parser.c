#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga el listado desde un archivo de texto
 *
 * \param pFile FILE* Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* Recibe la lista donde se van a cargar los datos del archivo
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];
    Employee* pEmployee = NULL;

    result = 0;

    if(pArrayListEmployee != NULL
       && pFile!= NULL)
       {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            pEmployee = employee_newParameters(idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            ll_add(pArrayListEmployee, pEmployee);
            result = 1;
        }
       }

    return result;

}

/** \brief Carga el listado desde un archivo de binario
 *
 * \param pFile FILE* Recibe el archivo ya abierto,
 * \param pArrayListEmployee LinkedList* Recibe la lista donde se van a cargar los datos del archivo
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
    Employee* pEmployee = NULL;

    result = 0;

    if(pArrayListEmployee != NULL
       && pFile!= NULL)
       {
           while(!feof(pFile))
           {
               pEmployee = employee_new();
               fread(pEmployee, sizeof(Employee), 1, pFile);
               ll_add(pArrayListEmployee, pEmployee);
               result = 1;
           }
       }
    fclose(pFile);

    return result;
}


/** \brief Guarda los empleados en un archivo de texto
 *
 * \param pArrayListEmployee LinkedList* Recibe listado que va a guardar
 * \param pFile FILE* Recibe el archivo ya abierto, donde lo va a guardar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int addEmployeesToFile(LinkedList* pArrayListEmployee, FILE* pFile)
{
    int len;
    int i;
    Employee* pEmployee = NULL;
    int idAux;
    char nombreAux[20];
    int horasAux;
    int sueldoAux;
    int result;

    result = 0;

    len = ll_len(pArrayListEmployee);
    if(!feof(pFile) && pArrayListEmployee != NULL && pFile != NULL)
    {
        for(i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &idAux);
            employee_getNombre(pEmployee, nombreAux);
            employee_getHorasTrabajadas(pEmployee, &horasAux);
            employee_getSueldo(pEmployee, &sueldoAux);
            fprintf(pFile, "%d, %s, %d, %d \n", idAux, nombreAux, horasAux, sueldoAux);
            result = 1;
        }
    }

    return result;
}

/** \brief Guarda los empleados en un archivo de binario
 *
 * \param pArrayListEmployee LinkedList* Recibe listado que va a guardar
 * \param pFile FILE* Recibe el archivo ya abierto, donde lo va a guardar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int addEmployeesToBinaryFile(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
    int len;
    int i;
    Employee* pEmployee = NULL;

    result = 0;

    if(pFile != NULL
       && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmployee, sizeof(Employee), 1, pFile);
        }
    }

    return result;

}

