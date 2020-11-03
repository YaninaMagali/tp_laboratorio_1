#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "getDataBase.h"
#include "Controller.h"

/** \brief Abre un archivo de texto, lo lee y luego lo cierra
 *
 * \param path char* Recibe el path del archivo
 * \param pArrayListEmployee LinkedList* Recibe una lista donde se guardan los datos leidos
 * \param fileLoaded int Flag que indica si el archivo ya fue abierto previamente
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int fileLoaded)
{
    FILE* pFile;
    int result;

    result = 0;
    pFile = fopen(path,"r");

    if(fileLoaded == 0
       && path != NULL
       && pArrayListEmployee != NULL
       && parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
       {
           result = 1;
       }
    fclose(pFile);
    return result;
}

/** \brief Abre un archivo binario, lo lee y luego lo cierra
 *
 * \param path char* Recibe el path del archivo
 * \param pArrayListEmployee LinkedList* Recibe una lista donde se guardan los datos leidos
 * \param fileLoaded int Flag que indica si el archivo ya fue abierto previamente
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int fileLoaded)
{
    FILE* pFile = NULL;
    int result;

    result = 0;

    if(fileLoaded == 0
       && pArrayListEmployee != NULL
       && path != NULL)
    {
        pFile = fopen(path, "rb");
        if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)== 1)
        {
            result = 1;
        }
    }

    return result;
}


/** \brief Pide al usuario datos del nuevo empleado y si son validos lo agrega a la lista
 *
 * \param pArrayListEmployee LinkedList* Recibe la lista a la que se agrega el empleado
 * \param fileLoaded int Recibe un flag que indica si cargo el archivo al menos una vez
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int fileLoaded)
{
    int result;
    Employee employee;
    Employee* pEmployee;
    char id;
    char* pId;
    char name[50];
    char hours[50];
    char salary[50];

    result = 0;
    pEmployee = &employee;
    pId = &id;

    if(fileLoaded == 1
       && pArrayListEmployee != NULL)
    {
        //if(getNewId(pArrayListEmployee, pId) == 1)
        if(controller_setNewId(pId) == 1)
        {
            controller_saveNewId(pId);
            if(getString(name, 50, "Nombre:", "Error...", 3) == 1)
            {
                if(getNumber(hours, 50, "Horas trabajadas:", "Error...", 3) == 1)
                {
                    if(getNumber(salary, 50, "Salario:", "Error...", 3)== 1)
                    {
                        pEmployee = employee_newParameters(pId, name, hours, salary);
                        ll_add(pArrayListEmployee, pEmployee);
                        result = 1;
                    }
                }
            }
    }

    }

    return result;
}


/** \brief Pide al usuario el empleado a modificar. Si lo encuentra le muestra un submenu para que elija que dato modificar.
 *  Una vez ingresado el nuevo valor, se le muestra al usuario una pregunta de confirmacion. Si la respuesta es S, realiza el cambio, sino cancela.
 *
 * \param pArrayListEmployee LinkedList* Recibe la lista donde va a buscar el empleado a modificar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int iEmployee;
    int editOption;
    char nameAux[20];
    char hoursAux[20];
    char salaryAux[90];
    int i;
    int len;
    Employee* pEmployee = NULL;

    result = 0;

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(getInt(&iEmployee, "Numero de orden del empleado a modificar: ", "Error", 1, 99999, 3) == 1)
        {
            len = ll_len(pArrayListEmployee);
            if(iEmployee <= len)
            {
                for(i = 0; i < len; i++)
                {
                    if(iEmployee - 1 == i)
                    {
                        pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                        break;
                    }
                }

                do
                {
                    getInt(&editOption, " 1. Modificar el nombre \n 2. Modificar horas trabajadas\n 3. Modificar salario\n 4. CANCELAR \n Elegi una opcion: ", "Opcion invalida\n", 1, 4, 20);
                    switch(editOption)
                    {
                    case 1:
                        getString(nameAux, 20, "Nuevo nombre: ", "Error...\n", 3);
                        if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1 )
                        {
                            employee_setNombre(pEmployee, nameAux);
                            result = 1;
                        }
                        break;
                    case 2:
                        getNumber(hoursAux, 20, "Nueva cantidad de horas: ", "Error...\n", 3);
                        if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
                        {
                            employee_setHorasTrabajadas(pEmployee, hoursAux);
                            result = 1;
                        }
                        break;
                    case 3:
                        getNumber(salaryAux, 20, "Nuevo salario: ", "Error...\n", 3);
                        if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
                        {
                            employee_setSueldo(pEmployee, salaryAux);
                            result = 1;
                        }
                        break;
                    }
                }
                while(editOption!=4);
            }
        }
    }


    return result;
}


/** \brief Pide al usuario el empleado a eliminar. Si lo se le muestra al usuario una pregunta de confirmacion. Si la
 *   respuesta es S, elimina, sino cancela.
 *
 * \param pArrayListEmployee LinkedList* Recibe la lista donde busca el empleado a eliminar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    int index;

    result = 0;

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(getInt(&index, "Numero de orden del usuario a eliminar: ", "Numero invalido\n", 1, 999999, 3) == 1)
        {
            if(pArrayListEmployee != NULL && index <= ll_len(pArrayListEmployee))
            {
                if(getUserAgreement("Para continuar ingresar S, para cancelar presionar cualquier tecla \n") == 1)
                {
                    ll_remove(pArrayListEmployee, index-1);
                    result = 1;
                }
            }
        }
    }

    return result;
}


/** \brief Muestra la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList* Recibe el listado que va a mostrar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int idAux;
    char nameAux[20];
    int hoursAux;
    int salaryAux;
    Employee* pEmployee = NULL;
    int result;
    int len;
    int i;

    result = 0;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            printf("Orden |  Id  |  Nombre   |   Horas   |   Salario\n");
            for(i = 0; i < len; i++)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(pEmployee, &idAux);
                employee_getNombre(pEmployee, nameAux);
                employee_getHorasTrabajadas(pEmployee, &hoursAux);
                employee_getSueldo(pEmployee, &salaryAux);
                printf("%1d) %5d, %11s, %12d, %13d $ \n", i+1, idAux, nameAux, hoursAux, salaryAux);
                result = 1;
            }
        }

    }

    return result;
}


/** \brief Recibe una lista de empleados. Si no esta vacia le da la opcion de ordenarlos por cada uno de sus campos de forma ascendente
 *
 * \param pArrayListEmployee LinkedList* Recibe la lista de empleados a ordenar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int sortOption;
    int result;
    result = 0;

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        do
        {
                if(getInt(&sortOption, "\n 1. Ordenar por Id \n 2. Ordenar por nombre \n 3. Ordenar por horas \n 4. Ordenar por sueldo\n 5. Salir \n " ,"Opcion invalida\n", 1, 5, 20) == 1)
            {
                switch(sortOption)
                {
                case 1:
                    ll_sort(pArrayListEmployee, employee_CompareById, 1);
                    result = 1;
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, employee_CompareByName, 1);
                    result = 1;
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, employee_CompareByHours, 1);
                    result = 1;
                    break;
                case 4:
                    ll_sort(pArrayListEmployee, employee_CompareBySalary, 1);
                    result = 1;
                    break;
                }
            }
        }
        while(sortOption!=5);
    }
    else
    {
        result = 0;
    }

    return result;
}


/** \brief Abre un archivo de texto, guarda el listado y lo cierra
 *
 * \param path char* Recibe el path del archivo
 * \param pArrayListEmployee LinkedList* Recibe el listado a guardar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    result = 0;
    FILE* pFile = NULL;

    if(path != NULL
       && pArrayListEmployee != NULL)
    {
        if(ll_isEmpty(pArrayListEmployee) == 0)
        {
            if(getUserAgreement("Para guardar ingresar S, sino cualquier tecla\n") == 1)
            {
                pFile = fopen(path,"w");
                if(addEmployeesToFile(pArrayListEmployee, pFile)==1)
                {
                    result = 1;
                }
            }
        }
    }
    fclose(pFile);
    return result;
}

/** \brief Abre un archivo binario, guarda el listado y lo cierra
 *
 * \param path char* Recibe el path del archivo
 * \param pArrayListEmployee LinkedList* Recibe el listado a guardar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    FILE* pFile = NULL;
    result = 0;

    if(pArrayListEmployee != NULL
       && path != NULL)
    {
        if(ll_isEmpty(pArrayListEmployee) == 0)
        {
            if(getUserAgreement("Para guardar ingresar S, sino cualquier tecla\n") == 1)
            {
                pFile = fopen(path, "wb");
                addEmployeesToBinaryFile(pFile, pArrayListEmployee);
                result = 1;
            }
        }
    }
    fclose(pFile);
    return result;
}

/** \brief - Pide al usuario confirmacion para ejecutar una accion
 *
 * \param void - Recibe un puntero a char para cargar el mensaje que se le quiere mostrar al usuario
 * \return int - Si el usuario confirma, devuelve 1, sino un 0
 *
 */
int getUserAgreement(char* message)
{
    int result;
    char userAnswer;

    result = 0;

    printf(message);
    fflush(stdin);
    scanf("%c", &userAnswer);

    if(userAnswer == 's' || userAnswer == 'S')
    {
        result = 1;
    }

    return result;
}

/** \brief Genera un id para un nuevo empleado obteniendo el ultimo de un txt y le suma 1
 *
 * \param id char* Recibe donde va a asignar el nuevo id
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int controller_setNewId(char* id)
{
    int result;
    int idAux;
    result = 0;

    if(id != NULL)
    {
        controller_loadLastId(id);
        idAux = atoi(id) + 1;
        //Pasar a otra funcion
        int length = snprintf( NULL, 0, "%d", idAux);
        char* str = (char*)malloc( length + 1 );
        snprintf( str, length + 1, "%d", idAux);
        strcpy(id, str);
        free(str);
        result = 1;
    }
    return result;
}

/** \brief Carga el ultimo id guardado en el txt
 *
 * \param id char* Recibe donde va a cargar el ultimo id
 * \return int Devuelve 1 si se pudo cargar, sino 0
 *
 */
int controller_loadLastId(char* id)
{
    int result;
    FILE* pFile;
    result = 0;

    if(id != NULL)
    {
        pFile = fopen("lastId.txt", "r");
        fgets(id, sizeof(int), pFile);
        fclose(pFile);
        result = 1;
    }
    return result;
}

/** \brief Guarda el ultimo idEmpleado en un txt
 *
 * \param id char* Recibe el id a guardar
 * \return int Devuelve 1 si se pudo guardar, sino 0
 *
 */
int controller_saveNewId(char* id)
{
    int result;
    FILE* pFile;
    int newId;
    result = 0;

    if(id != NULL)
    {
        newId = atoi(id);
        pFile = fopen("lastId.txt", "w");
        fprintf(pFile, "%d\n", newId );
        fclose(pFile);
        result = 1;
    }
    return result;
}

