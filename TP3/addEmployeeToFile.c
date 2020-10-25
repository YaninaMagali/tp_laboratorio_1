#include <stdio.h>
#include "employees.h"

void addEmployeeToFile(sEmployee* employee)
{
    FILE* pFile;

    pFile = fopen("TP3Employees.csv","w");
    if(!feof(pFile) && employee!= NULL)
    {
        fprintf(pFile, "%d, %s, %s, %.2f", employee->employeeId, employee->employeeName, employee->employeeSurname, employee->employeeSalary);
    }
    fclose(pFile);

}
