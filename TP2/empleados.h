#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
 int id;
 char nombre[20];
 char apellido[20];
 float salario;
 int sector;
 int estaVacio;
}empleadoEst;

empleadoEst ingresarEmpleado(empleadoEst empleadoData);
void mostrarEmpleado(empleadoEst empleadoData);
void inicializarArrayComoVacio(empleadoEst empleadoData[], int T);
//void cambiarEstadoEstaVacio(empleadoEst empleadoData);
int cambiarEstadoEstaVacio(empleadoEst empleadoData);
int consultarEstadoEstaVacio(empleadoEst empleadoData);
#endif // EMPLEADOS_H_INCLUDED
