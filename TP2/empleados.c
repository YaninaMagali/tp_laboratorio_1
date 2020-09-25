#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleados.h"
#include "pedirDatosBase.h"

empleadoEst ingresarEmpleado(empleadoEst empleadoData)
{
    obtenerCadena("Ingresa el nombre del empleado: ", "Error! Solo se pueden ingresar letras", empleadoData.nombre);

    obtenerCadena("Ingresa el apellido del empleado: ", "Error! Solo se pueden ingresar letras", empleadoData.apellido);

    printf("Ingresar salario: ");
    scanf("%f", &empleadoData.salario);
    while(empleadoData.salario < 1){
        printf("El salario debe ser un numero mayor a cero. Ingresar salario: ");
        scanf("%f", &empleadoData.salario);
    }

    printf("Ingresar sector: ");
    scanf("%d", &empleadoData.sector);

    return empleadoData;
}

void mostrarEmpleado(empleadoEst empleadoData[], int T)
{
    int i;
    for(i=0; i< T; i++)
    {
        if(empleadoData[i].estaVacio == 0)
        {
            printf("%1d %4s %8s %11.2f %13d\n", empleadoData[i].id, empleadoData[i].nombre, empleadoData[i].apellido, empleadoData[i].salario, empleadoData[i].sector);
        }

    }
}

void inicializarArrayComoVacio(empleadoEst empleadoData[], int T)
{
    int i;

    for(i = 0 ; i < T; i++)
    {
        empleadoData[i].estaVacio = 1;
    }
}

int cambiarEstadoEstaVacio(empleadoEst empleadoData)
{
    int estaVacioLocal;

    if(empleadoData.estaVacio == 0)
    {
        estaVacioLocal = 1;
    }
    else
    {
        estaVacioLocal = 0;
    }
    return estaVacioLocal;
}

int consultarEstadoEstaVacio(empleadoEst empleadoData)
{
    int estaVacio;

    if(empleadoData.estaVacio == 1)
    {
        empleadoData.estaVacio = 1;
    }
    else
    {
        empleadoData.estaVacio = 0;
    }
    return estaVacio;
}

int buscarPrimerEspacioVacioEnListado(empleadoEst empleadoData[], int T)
{
    int i;

    for(i = 0; i< T; i++)
    {
        if(empleadoData[i].estaVacio == 1 && i != T)
        {
            break;
        }
        if(i == T)
        {
            i = -1;
        }
    }
    return i;
}

void borrarEmpleado(empleadoEst empleadoData[], int T)
{
    int i;
    int idEmpleadoABorrar;

    idEmpleadoABorrar = pedirEntero("Ingresa el id del empleado que queres eliminar:");

    for(i = 0; i < T; i++)
    {
        if(empleadoData[i].id == idEmpleadoABorrar && empleadoData[i].estaVacio == 0)
        {
            empleadoData[i].estaVacio = cambiarEstadoEstaVacio(empleadoData[i]);
            break;
        }
        else
        {
            printf("No hay empleado con id %d\n", idEmpleadoABorrar);
            break;
        }
    }
}

int generarId(int ultimoId)
{
    int idActual;

    idActual = ultimoId + 1;

    return idActual;
}


void OrdenarEmpleadosPorNombre(empleadoEst empleadoData[], int T)
{
    int i;
    int j;
    empleadoEst aux;

    for(i = 0; i < T; i++)
    {
        for(j = i+1; j < T; j++)
        {
            if(strcmp(empleadoData[i].nombre, empleadoData[j].nombre)>0)//criterio de ordenamiento
            {
                aux = empleadoData[i];
                empleadoData[i] = empleadoData[j];
                empleadoData[j] = aux;
            }
        }
    }
}

void modificarEmpleado(empleadoEst empleadoData[], int T)
{
    int i;
    int idEmpleadoAModificar;
    int opcionDatoAModificar;

    idEmpleadoAModificar = pedirEntero("Ingresa el id del empleado que queres modificar: ");

    for(i = 0; i < T; i++)
    {
        if(empleadoData[i].id == idEmpleadoAModificar && empleadoData[i].estaVacio == 0)
        {

            opcionDatoAModificar = pedirEntero(" 1. Modificar el nombre \n 2. Modificar apellido\n 3. Modificar salario\n 4. Modificar sector 5. CANCELAR \n Elegi una opcion:");

            switch(opcionDatoAModificar)
            {
            case 1:
                obtenerCadena("Ingresa el nombre del empleado: ", "Error! Solo se pueden ingresar letras. Ingresa el nombre nuevamente: ", empleadoData[i].nombre);
                printf("El nombre fue modificado exitosamente\n");
                break;
            case 2:
                obtenerCadena("Ingresa el apellido del empleado: ", "Error! Solo se pueden ingresar letras. Ingresa el apellido nuevamente: ", empleadoData[i].apellido);
                printf("El apellido fue modificado exitosamente\n");
                break;
            case 3:
                printf("cambiar sueldo\n");
                break;
            case 4:
                printf("Cambiar sector\n");
                break;
            case 5:
                menuEmpleados();
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
        }

    }
}



