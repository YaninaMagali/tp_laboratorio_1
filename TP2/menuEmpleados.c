#include <stdio.h>
#include <stdlib.h>
#include "menuEmpleados.h"
#include "pedirDatosBase.h"
#include "empleados.h"
#include "menuEmpleados.h"
#define T 3


void menuEmpleados(void)
{
    int opcion;
    empleadoEst empleadosListado[T];//MODIFICAR TAMANIO ARRAY
    int filaEnListaEmpleados;
    int i;

    filaEnListaEmpleados = 0;

    inicializarArrayComoVacio(empleadosListado, T);
    printf("Fin del setting\n");


    do
    {
        opcion = pedirEntero("Selecciona una opcion\n 1. ALTA\n 2. MODIFICAR\n 3. BAJA\n 4. INFORMAR\n 0. SALIR\n");

        switch(opcion)
        {
        case 1:
            printf("Aca va el ALTA\n");
            printf("Estadp esta vacio ANTES del igresar dato %d\n", empleadosListado[filaEnListaEmpleados].estaVacio);
            empleadosListado[filaEnListaEmpleados] = ingresarEmpleado(empleadosListado[filaEnListaEmpleados]);
            printf("Estadp esta vacio ANTES del cambio %d\n", empleadosListado[filaEnListaEmpleados].estaVacio);

            empleadosListado[filaEnListaEmpleados].estaVacio = cambiarEstadoEstaVacio(empleadosListado[filaEnListaEmpleados]);
            printf("Estadp esta vacio DESPx del cambio %d\n", empleadosListado[filaEnListaEmpleados].estaVacio);
            filaEnListaEmpleados++;

            break;
        case 2:
            printf("Aca va la MOD\n");
            break;
        case 3:
            printf("Aca va el BAJA\n");
            break;
        case 4:
            printf("Aca va el LISTADO\n");

            for(i=0; i<T; i++)
            {
                //mostrarEmpleado(empleadosListado[i]);
                //printf("A ver si entra al for...\n");
                printf("Estadp de esta vacio PRE IF es%d...\n", empleadosListado[i].estaVacio);
                if(empleadosListado[i].estaVacio == 0)
                {
                    printf("A ver si entra al for...\n");
                    mostrarEmpleado(empleadosListado[i]);
                }

            }

            break;
        }
    }
    while(opcion!=0);
}
