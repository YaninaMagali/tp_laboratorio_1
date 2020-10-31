#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "EmployeesMenu.h"
#include "getDataBase.h"
#include "parser.h"

void employeeMenu(void)
{
    printf("TP 3: ADMINISTRACION DE EMPLEADOS!\n");

    LinkedList* employeeList;
    int menuOption;

    employeeList = ll_newLinkedList();


    do
    {
        if(getInt(&menuOption, "Selecciona una opcion\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n 3. Alta de empleado \n 4. Modificar datos de empleado\n 5. Baja de empleado \n 6. Listar empleados\n 7. Ordenar empleados \n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n 10. Salir\n" ,
                  "Opcion invalida\n", 1, 10, 20) == 0)
        {
            switch(menuOption)
            {
            case 1:
                controller_loadFromText("TP3Employees.csv", employeeList);
                break;
            case 2:
                break;
            case 3:
                controller_addEmployee(employeeList);
                break;
            case 4:
                controller_editEmployee(employeeList);
                break;
            case 5:
                controller_removeEmployee(employeeList);
                break;
            case 6:
                controller_ListEmployee(employeeList);
                break;
            case 7:
                break;
            case 8:
                controller_saveAsText("TP3Employees.csv", employeeList);
                break;
            case 9:
                break;
            }
        }
    }
    while(menuOption!=10);
}
