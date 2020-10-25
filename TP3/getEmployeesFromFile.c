#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"

void getEmployeeFromFile()
{
    FILE* pFile;
    sEmployee employee;
    char id[10];
    char name[50];
    char surname[50];
    char salary[50];

    pFile = fopen("TP3Employees.csv","r");
    while(!feof(pFile))
    {
        printf("LOG DENTRO DEL WHILE DEL READ\n");
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, surname, salary);
        employee.employeeId = atoi(id);
        strcpy(employee.employeeName, name);
        strcpy(employee.employeeSurname, surname);
        employee.employeeSalary = atof(salary);

        fclose(pFile);
        printf("\nLOG!!!! %d%s%s%f\n", employee.employeeId, employee.employeeName,employee.employeeSurname, employee.employeeSalary);
        break;

    }
}
