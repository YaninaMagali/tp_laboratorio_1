#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

empleadoEst ingresarEmpleado(empleadoEst empleadoData)
//void ingresarEmpleado(empleadoEst empleadoData)
{
    //empleadoEst empleadoData;

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
    //empleadoData.estaVacio = consultarEstadoEstaVacio(empleadoData);

    return empleadoData;
}

void mostrarEmpleado(empleadoEst empleadoData)
{

    printf("%4s %8s %11.2f %13d\n", empleadoData.nombre, empleadoData.apellido, empleadoData.salario, empleadoData.sector);
}

void inicializarArrayComoVacio(empleadoEst empleadoData[], int T)
{
    int i;

    for(i = 0 ; i < T; i++)
    {
        empleadoData[i].estaVacio = 1;
    }
}


//void cambiarEstadoEstaVacio(empleadoEst empleadoData)
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
