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
    //Employee* pEmployee;

    // CREAR LISTA
    employeeList = ll_newLinkedList();

/*
    //MOSTRAR
    len = ll_len(employeeList);
    for(i = 0; i < len; i++)
    {
        pEmployee = (Employee*)ll_get(employeeList, i);
        printf("%d)%s %d\n", i+1, pEmployee->name, pEmployee->hours);
    }
*/
    int option;
    do
    {
        if(getInt(&option, "Selecciona una opcion\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n 3. Alta de empleado \n 4. Modificar datos de empleado\n 5. Baja de empleado \n 6. Listar empleados\n 7. Ordenar empleados \n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n 10. Salir\n" ,
                  "Opcion invalida\n", 1, 10, 20) == 0)
        {
            switch(option)
            {
            case 1:
                controller_loadFromText("TP3Employees.csv", employeeList);
                break;
            case 2://MOD
                break;
            case 3:
                controller_addEmployee(employeeList);
                break;
            case 4:
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
    while(option!=10);
}
