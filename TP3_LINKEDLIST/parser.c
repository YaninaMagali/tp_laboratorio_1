#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, char* path)
{
    int result;
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];
    Employee employee;
    Employee* pEmployee;
    pEmployee = &employee;

    result = 0;

    if(path != NULL
       && pArrayListEmployee != NULL
       && pFile!= NULL)
       {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", nombreAux, horasTrabajadasAux, sueldoAux);
            pEmployee = employee_newParameters(nombreAux, horasTrabajadasAux, sueldoAux);
            ll_add(pArrayListEmployee, pEmployee);
            result = 1;
        }
       }
    fclose(pFile);

    return result;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, char* path)
{
    int result;
    Employee* pEmployee;

    result = 0;

    if(path != NULL
       && pArrayListEmployee != NULL
       && pFile!= NULL)
       {
           while(!feof(pFile))
           {
               fread(pEmployee, sizeof(Employee), 1, pFile);
               ll_add(pArrayListEmployee, pEmployee);
               result = 1;
           }
       }
    fclose(pFile);

    return result;
}


int addEmployeesToFile(LinkedList* pArrayListEmployee, char* path)
{
    FILE* pFile;
    int len;
    int i;
    Employee* pEmployee;
    char nombreAux[20];
    int horasAux;
    int sueldoAux;
    int result;

    result = 0;

    pFile = fopen(path,"w");
    len = ll_len(pArrayListEmployee);
    if(!feof(pFile) && pArrayListEmployee != NULL)
    {
        for(i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getNombre(pEmployee, nombreAux);
            employee_getHorasTrabajadas(pEmployee, &horasAux);
            employee_getSueldo(pEmployee, &sueldoAux);
            fprintf(pFile, "%s, %d, %d \n", nombreAux, horasAux, sueldoAux);
            result = 1;
        }
    }
    fclose(pFile);
    return result;
}


int addEmployeesToBinaryFile(FILE* pFile, LinkedList* pArrayListEmployee, char* path)
{
    int result;
    int len;
    int i;
    Employee* pEmployee;

    result = 0;

    if(pFile != NULL
       && pArrayListEmployee != NULL
       && path != NULL)
    {
        len = ll_len(pArrayListEmployee);
        //len = sizeof(pArrayListEmployee);
        printf("LEN %d :\n", len);
        while(!feof(pFile))
        {
            for(i = 0; i < len; i++)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(pEmployee, sizeof(Employee), 1, pFile);
            }
            //fwrite( a, sizeof(book), items, ptr);
            //fwrite(pArrayListEmployee, sizeof(Employee), len, pFile);
        }
    }
    fclose(pFile);

    return result;

}

