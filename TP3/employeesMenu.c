#include <stdio.h>
#include <stdlib.h>
#include "employees.h"
#include "employeeMenu.h"
#include "addEmployeeToFile.h"
#include "getDataBase.h"

void employeeMenu(void)
{
    printf("TP 3: ADMINISTRACION DE EMPLEADOS!\n");

    sEmployee employee;
    sEmployee* pEmployee;

    pEmployee = &employee;

    int option;
    do
    {
        if(getInt(&option, "Selecciona una opcion\n 1. ALTA\n 2. MODIFICAR\n 3. BAJA\n 4. MOSTRAR\n 5. SALIR\n", "Opcion invalida\n", 1, 5, 20) == 0)
        {
            switch(option)
            {
            case 1://ALTA
                addEmployee(pEmployee);
                addEmployeeToFile(&employee);
                break;
            case 2://MOD
                break;
            case 3://BAJA
                break;
            case 4://MOSTRAR
                getEmployeeFromFile();
                break;
            }//Fin switch
        }
    }
    while(option!=5);
}
