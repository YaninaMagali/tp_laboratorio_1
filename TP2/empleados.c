#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "pedirDatosBase.h"

empleadoEst ingresarEmpleado(empleadoEst empleadoData)
{
    printf("Ingresar nombre: ");
    fflush(stdin);
    scanf("%s",&empleadoData.nombre);
    fflush(stdin);
    printf("Ingresar apellido: ");
    scanf("%s", &empleadoData.apellido);
    printf("Ingresar salario: ");
    scanf("%f", &empleadoData.salario);
    printf("Ingresar sector: ");
    scanf("%d", &empleadoData.sector);

    return empleadoData;
}

void mostrarEmpleado(empleadoEst empleadoData)
{

    printf("%1d %4s %8s %11.2f %13d\n", empleadoData.id, empleadoData.nombre, empleadoData.apellido, empleadoData.salario, empleadoData.sector);
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

    idEmpleadoABorrar = pedirEntero("Ingresa el id del empleado que queres eliminar\n");

    for(i = 0; i < T; i++)
    {
        if(empleadoData[i].id == idEmpleadoABorrar && empleadoData[i].estaVacio == 0)
        {
            empleadoData[i].estaVacio = cambiarEstadoEstaVacio(empleadoData[i]);
            break;
        }
        else
        {
            printf("El id ingresado no existe\n");
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
