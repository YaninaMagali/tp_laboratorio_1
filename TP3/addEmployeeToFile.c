#include <stdio.h>
#include "employees.h"

void addEmployeeToFile(sEmployee* employee)
{
    FILE* pFile;

    pFile = fopen("TP3Employees.txt","w");
    if(!feof(pFile) && employee!= NULL)
    {
        fwrite(employee, sizeof(employee), 1, pFile);
    }
    fclose(pFile);

}
