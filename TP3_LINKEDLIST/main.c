#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "EmployeesMenu.h"
#include "getDataBase.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{

    employeeMenu();

    /*
    char string[50];
    getNumber(string, 50, "Dato numerico:", "Error...", 3);

    int num;
    int* pInt;
    pInt = &num;
    char name[22];
    printf("HOLA \n");
    getBase(name, size);
    getInt(pInt, "numero: ", "Error numero\n", 1, 500, 12);
    getString(name, 22, "Dato: ", "Error main\n", 2);
    printf("printf %s\n ", name);
    printf("printf %d ", num);
    */
    return 0;
    }
