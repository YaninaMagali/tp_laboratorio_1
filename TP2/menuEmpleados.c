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
    int idEmpleadoABorrarModificar;
    int indiceEnArray;
    float sumaSalarios;
    int cantidadEmpleados;
    float promedioSalarios;
    int cantidadEmpleadosSuperanSueldoPromedio;

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
                printf("El usuario ingresado tiene ID %d\n", ultimoId);
            }
            break;
        case 2://MOD
            if(ultimoId == 0)
            {
                printf("No se cargaron empleados en el listado\n");
            }
            else
            {
                idEmpleadoABorrarModificar = pedirIdUsuarioModificar();
                indiceEnArray = buscarIndiceEnArrayPorIdEmpleado(empleadosListado, T, idEmpleadoABorrarModificar);
                if( indiceEnArray == -1)
                {
                    printf("No se encontro el empleado en el listado\n");
                }
                else
                {
                    modificarEmpleado(empleadosListado, indiceEnArray);
                }
            }
            break;
        case 3://BAJA
            if(ultimoId == 0)
            {
                printf("No se cargaron empleados en el listado\n");
            }
            else
            {
                idEmpleadoABorrarModificar = pedirIdUsuarioModificar();
                indiceEnArray = buscarIndiceEnArrayPorIdEmpleado(empleadosListado, T, idEmpleadoABorrarModificar);
                if(buscarIndiceEnArrayPorIdEmpleado(empleadosListado, T, idEmpleadoABorrarModificar) == -1)
                {
                    printf("No se encontro el empleado en el listado\n");
                }
                else
                {
                    borrarEmpleado(empleadosListado, indiceEnArray);
                }
            }
            break;
        case 4://MOSTRAR
            if(ultimoId == 0 || contarEmpleados(empleadosListado, T)==0)
            {
                printf("No hay empleados en el listado\n");
            }
            else
            {
                sumaSalarios = sumarSalarios(empleadosListado, T);
                cantidadEmpleados = contarEmpleados(empleadosListado, T);
                promedioSalarios = calcularPromedioSalarios(cantidadEmpleados, sumaSalarios);
                cantidadEmpleadosSuperanSueldoPromedio = contarEmpleadosSuperanSueldoPromedio(empleadosListado, T, promedioSalarios);
                OrdenarEmpleadosPorNombre(empleadosListado,T);
                mostrarEmpleado(empleadosListado, T);
                printf("La suma de los salarios es %.2f\n", sumaSalarios);
                printf("El promedio de los salarios es %.2f\n", promedioSalarios);
                printf("La cantidad de empleados que superan el sueldo promedio es %d\n", cantidadEmpleadosSuperanSueldoPromedio);


            }
            break;
        }//Fin switch
    }
    while(opcion!=0);
}
