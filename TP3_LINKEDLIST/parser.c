#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];
    Employee employee;
    Employee* pEmployee;
    pEmployee = &employee;

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
    fclose(pFile);

    return result;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
    Employee* pEmployee;

    result = 0;

    if(pArrayListEmployee != NULL
       && pFile!= NULL)
       {
           while(!feof(pFile))
           {
               pEmployee = employee_new();
               //AGREGAR VALIDACION
               fread(pEmployee, sizeof(Employee), 1, pFile);
               ll_add(pArrayListEmployee, pEmployee);
               result = 1;
           }
       }
    fclose(pFile);

    return result;
}


int addEmployeesToFile(LinkedList* pArrayListEmployee, FILE* pFile)
{

    int len;
    int i;
    Employee* pEmployee;
    int idAux;
    char nombreAux[20];
    int horasAux;
    int sueldoAux;
    int result;

    result = 0;


    len = ll_len(pArrayListEmployee);
    if(!feof(pFile) && pArrayListEmployee != NULL)
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
    fclose(pFile);
    return result;
}


int addEmployeesToBinaryFile(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
    int len;
    int i;
    Employee* pEmployee;

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
    fclose(pFile);

    return result;

}

