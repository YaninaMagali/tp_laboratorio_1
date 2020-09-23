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
    int filaLibreEnListaEmpleados;
    int ultimoId;
    int i;

    ultimoId = 0;

    inicializarArrayComoVacio(empleadosListado, T);


    do
    {
        opcion = pedirEntero("Selecciona una opcion\n 1. ALTA\n 2. MODIFICAR\n 3. BAJA\n 4. INFORMAR\n 0. SALIR\n");

        switch(opcion)
        {
        case 1://ALTA
            filaLibreEnListaEmpleados = buscarPrimerEspacioVacioEnListado(empleadosListado, T);
            if(filaLibreEnListaEmpleados == -1 || filaLibreEnListaEmpleados == T)
            {
                printf("No hay mas lugar en el listado. Borra algun empleado para ingresar uno nuevo\n");
            }
            else
            {
                empleadosListado[filaLibreEnListaEmpleados] = ingresarEmpleado(empleadosListado[filaLibreEnListaEmpleados]);
                ultimoId = generarId(ultimoId);
                empleadosListado[filaLibreEnListaEmpleados].id = ultimoId;
                empleadosListado[filaLibreEnListaEmpleados].estaVacio = cambiarEstadoEstaVacio(empleadosListado[filaLibreEnListaEmpleados]);
            }
            break;
        case 2://MOD
            printf("Aca va la MOD\n");
            break;
        case 3://BAJA
            printf("Aca va el BAJA\n");
            if(ultimoId == 0)
            {
                printf("Todavia no se ingreso ningun empleado\n");
            }
            else
            {
                borrarEmpleado(empleadosListado, T);
            }

            break;
        case 4://MOSTRAR
            OrdenarEmpleadosPorNombre(empleadosListado,T);
            for(i=0; i<T; i++)
            {
                if(empleadosListado[i].estaVacio == 0)
                {
                    mostrarEmpleado(empleadosListado[i]);
                }
                else
                {
                    printf("No hay empleados para mostrar\n");
                    break;
                }
            }

            break;
        }
    }
    while(opcion!=0);
}
