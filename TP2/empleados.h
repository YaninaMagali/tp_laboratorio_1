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
void mostrarEmpleado(empleadoEst empleadoData[], int T);
void inicializarArrayComoVacio(empleadoEst empleadoData[], int T);
int cambiarEstadoEstaVacio(empleadoEst empleadoData);
int consultarEstadoEstaVacio(empleadoEst empleadoData);
int buscarPrimerEspacioVacioEnListado(empleadoEst empleadoData[], int T);
int generarId(int ultimoId);
void OrdenarEmpleadosPorNombre(empleadoEst empleadoData[], int T);
float sumarSalarios(empleadoEst empleadoData[], int T);
float calcularPromedioSalarios(float contadorEmpleados, float sumaSalarios);
int contarEmpleados(empleadoEst empleadoData[], int T);
int contarEmpleadosSuperanSueldoPromedio(empleadoEst empleadoData[], int T, float salarioPromedio);
void formatearNombrePropio(char cadena[]);

int buscarEmpleadoEnListaPorId(empleadoEst empleadoData[], int T, int idEmpleado);
int pedirIdUsuarioModificar(void);
void modificarEmpleado(empleadoEst empleadoData[], int idEmpleadoAModificar);
int buscarIndiceEnArray(empleadoEst empleadoData[], int T, int idEmpleadoAModificar);
void borrarEmpleado(empleadoEst empleadoData[], int indiceEnArrayEmpleadoAModificar);
#endif // EMPLEADOS_H_INCLUDED
