#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getDataBase.h"
#include "employees.h"

void addEmployee(sEmployee* employee)
{
    //int result;
    //result = -1;

    employee->employeeId = 88;
    getString(employee->employeeName, 20, "Nombre del empleado:\n", "Error!\n", 2);
    getString(employee->employeeSurname, 20, "Apellido del empleado:\n", "Error!\n", 2);
    getFloat(&employee->employeeSalary, "Salario del empleado: \n", "Error!\n", 1, 999999, 3);
    //result = 0;

    //return result;
}


