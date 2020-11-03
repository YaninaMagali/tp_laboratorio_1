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

    LinkedList* employeeList = NULL;

    int menuOption;
    int fileLoaded;

    employeeList = ll_newLinkedList();
    fileLoaded = 0;

    do
    {
            if(getInt(&menuOption, "\nSelecciona una opcion\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n 3. Alta de empleado \n 4. Modificar datos de empleado\n 5. Baja de empleado \n 6. Listar empleados\n 7. Ordenar empleados \n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n 10. Salir\n" ,"Opcion invalida\n", 1, 10, 20) == 1)
        {
            switch(menuOption)
            {
            case 1:
                if(controller_loadFromText("TP3Employees.csv", employeeList, fileLoaded) == 1)
                {
                    fileLoaded = 1;
                    printf("\nArchivo cargado\n");
                }
                else
                {
                    printf("\nNo se pudo cargar archivo\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary("BIN_DATA_TEST.bin", employeeList, fileLoaded) == 1)
                {
                    fileLoaded = 1;
                    printf("\nArchivo cargado\n");
                }
                else
                {
                    printf("\nNo se pudo cargar archivo\n");
                }
                fileLoaded = 1;
                break;
            case 3:
                if(controller_addEmployee(employeeList, fileLoaded) == 1)
                {
                    printf("\nCarga exitosa\n\n");
                }
                else
                {
                    printf("\nCarga no realizada. Intente cargando la lista en la opcion 1 del menu y vuelva a intentar\n");
                }
                break;
            case 4:
                if(controller_editEmployee(employeeList) == 1)
                {
                    printf("\nEdicion exitosa\n");
                }
                else
                {
                    printf("\nEdicion no realizada. Revise si el numero ingresado es correcto o si hay datos en la lista\n");
                }
                break;
            case 5:
                if(controller_removeEmployee(employeeList) == 0)
                {
                    printf("\nAccion no realizada. Revise si el numero ingresado es correcto o si hay datos en la lista\n");
                }
                else
                {
                    printf("\nLa accion se realizo exitosamente\n");
                }
                break;
            case 6:
                if(controller_ListEmployee(employeeList) == 0)
                {
                   printf("\nLa lista esta vacia\n");
                }
                break;
            case 7:
                if(controller_sortEmployee(employeeList)== 0)
                {
                    printf("La lista esta vacia\n");
                }
                break;
            case 8:
                if(controller_saveAsText("TP3Employees.csv", employeeList) == 1)
                {
                    printf("\nDatos guardados exitosamente\n");
                }
                else
                {
                    printf("\nNo se pudieron guardar los datos. Chequee si la lista no esta vacia\n");
                }
                break;
            case 9:
                if(controller_saveAsBinary("BIN_DATA_TEST.bin", employeeList) == 1)
                {
                    printf("\nDatos guardados exitosamente\n");
                }
                else
                {
                    printf("\nNo se pudieron guardar los datos. Chequee si la lista no esta vacia\n");
                }
                break;
            }
        }
    }
    while(menuOption!=10);
}
