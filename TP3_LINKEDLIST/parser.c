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
            printf("\nLOG DENTRO DEL READ!!!! %s %d %d\n",pEmployee->nombre,pEmployee->horasTrabajadas, pEmployee->sueldo);
        }
       }

    fclose(pFile);

    return result;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}

//LLAMAR DESDE CONTROLADOR
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

