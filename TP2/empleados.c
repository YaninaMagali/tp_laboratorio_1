#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "pedirDatosBase.h"
#include "menuEmpleados.h"
#define TAMANIO_CADENA 50

/** \brief - Pide al usuario el ingreso de los datos de un empleado
 *
 * \param empleadoData empleadoEst - Recibe un tipo empleadoEst donde se van a guardar los datos ingresados
 * \return empleadoEst - Devuelve la informacion ingresada por teclado
 *
 */
empleadoEst ingresarEmpleado(empleadoEst empleadoData)
{
    obtenerCadena("Ingresa el nombre del empleado: ", "Error! Solo se pueden ingresar letras. Ingresar nombre nuevamente: ", empleadoData.nombre, TAMANIO_CADENA);
    remmplazarSaltoPorEspacio(empleadoData.nombre);
    formatearNombrePropio(empleadoData.nombre);

    obtenerCadena("Ingresa el apellido del empleado: ", "Error! Solo se pueden ingresar letras: ", empleadoData.apellido, TAMANIO_CADENA);
    remmplazarSaltoPorEspacio(empleadoData.apellido);
    formatearNombrePropio(empleadoData.apellido);

    empleadoData.salario = pedirNumeroFlotante("Ingresar salario: ");
    while(empleadoData.salario < 1){
        empleadoData.salario = pedirNumeroFlotante("El salario debe ser mayor a 0. Ingresar salario nuevamente: ");
    }

    empleadoData.sector = pedirEntero("Ingresar sector: ");

    return empleadoData;
}


/** \brief - Recorre un listado de empleados y si no estan dados de baja los muestra
 *
 * \param empleadoData[] empleadoEst - Recibe el listado
 * \param T int - Recibe el tamanio del listado
 * \return void - No devuelve nada
 *
 */
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


/** \brief - Recorre un listado de empleados, y los inicializa como vacio
 *
 * \param empleadoData[] empleadoEst- Recibe el listado
 * \param T int  Recibe el tamanio del listado
 * \return void - No devuelve nada
 *
 */
void inicializarArrayComoVacio(empleadoEst empleadoData[], int T)
{
    int i;

    for(i = 0 ; i < T; i++)
    {
        empleadoData[i].estaVacio = 1;
    }
}


/** \brief - Cambia el valor de estaVacio del empleado. Si esta vacio es 1, lo cambia a 0 y viceversa.
 *
 * \param empleadoData empleadoEst - Recibe un empleado del listado de empleados.
 * \return int - Devuelve el nuevo valor de estaVacio
 *
 */
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


/** \brief - Chequea el estado estaVacio del empleado recibido
 *
 * \param empleadoData empleadoEst - Recibe una fila del listado de empleados.
 * \return int - Devuelve el valor estaVacio actual del empleado
 *
 */
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


/** \brief Devuelve la posicion dentro del array cuyo valor estaVacio es 1
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado de empleados
 * \param T int - Recibe el tamanio del array
 * \return int - Devuelve el indice del primer valor vacio que encuentra
 *
 */
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


/** \brief - Realiza una baja logica al cambiar el estaVacio 0 por estaVacio 1
 *
 * \param empleadoData[] empleadoEst - Recibe el array lista de empleados
 * \param indiceEnArrayEmpleadoAModificar int - Recibe el indice del listado del registro a eliminar
 * \return void - No devuelve nada
 *
 */
void borrarEmpleado(empleadoEst empleadoData[], int indiceEnArrayEmpleadoAModificar)
{

    if(confirmarAccionUsuario()== 1)
    {
        empleadoData[indiceEnArrayEmpleadoAModificar].estaVacio = cambiarEstadoEstaVacio(empleadoData[indiceEnArrayEmpleadoAModificar]);
        printf("El empleado fue dado de baja exitosamente\n");
    }
    else
    {
       printf("Se cancelo la operacion");
    }


}


/** \brief - Genera ids de forma incremental
 *
 * \param ultimoId int - Recibe el ultimo id generado
 * \return int - Devuelve el siguiente id
 *
 */
int generarId(int ultimoId)
{
    int idActual;

    idActual = ultimoId + 1;

    return idActual;
}


/** \brief - Ordena el listado por nombre y sector
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado de empleados
 * \param T int - Recibe el tamanio del array
 * \return void - No devuelve nada
 *
 */
void OrdenarEmpleadosPorNombre(empleadoEst empleadoData[], int T)
{
    int i;
    int j;
    empleadoEst aux;

    for(i = 0; i < T; i++)
    {
        for(j = i+1; j < T; j++)
        {
            if(strcmp(empleadoData[i].apellido, empleadoData[j].apellido)>0)//criterio de ordenamiento
            {
                aux = empleadoData[i];
                empleadoData[i] = empleadoData[j];
                empleadoData[j] = aux;
            }
            if(strcmp(empleadoData[i].apellido, empleadoData[j].apellido)==0)
            {
                if(empleadoData[i].sector > empleadoData[j].sector)
                {
                    aux = empleadoData[i];
                    empleadoData[i] = empleadoData[j];
                    empleadoData[j] = aux;
                }
            }
        }
    }
}


/** \brief - Busca un empleado que no este dado de baja en el listado por id
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado de empleados
 * \param T int - Recibe el tamanio del array
 * \param idEmpleado int - Recibe el id del empleado que se quiere buscar
 * \return int - Si encuentra el id en el listado devuelve 1, sino 0.
 *
 */
int buscarEmpleadoEnListaPorId(empleadoEst empleadoData[], int T, int idEmpleado)
{
    int i;
    int resultadoBusqueda;

    for(i = 0; i < T; i++)
    {
        if(empleadoData[i].id == idEmpleado && empleadoData[i].estaVacio == 0)
        {
            resultadoBusqueda = 1;
        }
        else
        {
            resultadoBusqueda = 0;
        }
    }
    return resultadoBusqueda;
}


/** \brief - Pide al usuario que ingerse por teclado el id del empleado que quiere modificar o borrar
 *
 * \param void - No recibe parametros
 * \return int - Devuelve el id del empleado ingresado por teclado
 *
 */
int pedirIdUsuarioModificar(void)
{
    int idEmpleadoAModificar;

    idEmpleadoAModificar = pedirEntero("Ingresa el id del empleado que queres modificar o eliminar: ");

    return idEmpleadoAModificar;
}


/** \brief - Busca el indice del array donde esta almacenado el id empleado
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado de empleados
 * \param T int - Recibe el tamanio del array
 * \param idEmpleadoAModificar int - Recibe el id cuya posicion en el listado se quiere obtener
 * \return int - Devuelve la posicion del empleado en el array. Si no lo encuentra o esta dado de baja devuelve -1
 *
 */
int buscarIndiceEnArrayPorIdEmpleado(empleadoEst empleadoData[], int T, int idEmpleadoAModificar)
{
    int i;
    int indice;

    for(i = 0; i < T; i++)
    {
        if(empleadoData[i].id == idEmpleadoAModificar && empleadoData[i].estaVacio == 0)
        {
            indice = i;
            break;
        }
        else
        {
            indice = -1;
        }
    }
    return indice;
}


/** \brief - Permite al usuario modificar uno de los datos del empleado
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado empleados
 * \param indiceEnArrayEmpleadoAModificar int - Recibe la posicion dentro del array del empleado que se quiere modificar
 * \return void - No devuelve nada
 *
 */
void modificarEmpleado(empleadoEst empleadoData[], int indiceEnArrayEmpleadoAModificar)
{
    int opcionDatoAModificar;
    char aux[TAMANIO_CADENA];
    int intAux;
    float floatAux;

    opcionDatoAModificar = pedirEntero(" 1. Modificar el nombre \n 2. Modificar apellido\n 3. Modificar salario\n 4. Modificar sector\n 5. CANCELAR \n Elegi una opcion: ");

    switch(opcionDatoAModificar)
    {
    case 1:
        obtenerCadena("Ingresa el nombre del empleado: ", "Error! Solo se pueden ingresar letras. Ingresar nombre nuevamente: ", aux, TAMANIO_CADENA);
        if(confirmarAccionUsuario()== 1)
        {
            strcpy(empleadoData[indiceEnArrayEmpleadoAModificar].nombre, aux);
            remmplazarSaltoPorEspacio(empleadoData[indiceEnArrayEmpleadoAModificar].nombre);
            formatearNombrePropio(empleadoData[indiceEnArrayEmpleadoAModificar].nombre);
            printf("El nombre fue modificado exitosamente\n");
        }
        break;
    case 2:
        obtenerCadena("Ingresa el apellido del empleado: ", "Error! Solo se pueden ingresar letras. Ingresar apellido nuevamente: ", aux, TAMANIO_CADENA);
        if(confirmarAccionUsuario()== 1)
        {
            strcpy(empleadoData[indiceEnArrayEmpleadoAModificar].apellido, aux);
            remmplazarSaltoPorEspacio(empleadoData[indiceEnArrayEmpleadoAModificar].apellido);
            formatearNombrePropio(empleadoData[indiceEnArrayEmpleadoAModificar].apellido);
            printf("El apellido fue modificado exitosamente\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }
        break;
    case 3:
        floatAux = pedirNumeroFlotante("Ingresar salario: ");
        while(empleadoData[indiceEnArrayEmpleadoAModificar].salario < 1){
            floatAux = pedirNumeroFlotante("El salario debe ser mayor a 0. Ingresar salario nuevamente: ");
        }
        if(confirmarAccionUsuario()== 1)
        {
            empleadoData[indiceEnArrayEmpleadoAModificar].salario = floatAux;
            printf("El salario fue modificado exitosamente\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }
        break;
    case 4:
        intAux = pedirEntero("Ingresar sector: ");
        if(confirmarAccionUsuario()== 1)
        {
            empleadoData[indiceEnArrayEmpleadoAModificar].sector = intAux;
            printf("El sector fue modificado exitosamente\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }
        break;
    case 5:
        menuEmpleados();
        break;
    default:
        printf("Opcion invalida\n");
        break;
    }
}


/** \brief - Suma los salarios de todos los empleados del listado. No tiene en cuenta aquellos dados de baja logicamente
 *
 * \param empleadoData[] empleadoEst - Recibe el listado de los empleados
 * \param T int - Recibe el tamanio del listado
 * \return float - Devuelve la suma de los salarios
 *
 */
float sumarSalarios(empleadoEst empleadoData[], int T)
{
    int i;
    float sumaSalarios;

    sumaSalarios = 0;

    for(i=0; i<T;i++)
    {
        if(empleadoData[i].estaVacio == 0)
        {
            sumaSalarios = sumaSalarios + empleadoData[i].salario;
        }
    }
    return sumaSalarios;
}


/** \brief - Calcula el promedio de los salarios de todos los empleados del listado. No tiene en cuenta aquellos dados de baja logicamente
 *
 * \param contadorEmpleados float - Recibe la cantidad de empleados sin tener en cuenta los dados de baja
 * \param sumaSalarios float - Recibe la suma de los salarios sin tener en cuenta los dados de baja
 * \return float - Devuelve el promedio
 *
 */
float calcularPromedioSalarios(float contadorEmpleados, float sumaSalarios)
{
    float promedioSalarios;

    promedioSalarios = 0;

    promedioSalarios = sumaSalarios / contadorEmpleados;

    return promedioSalarios;
}


/** \brief - Cuenta la cantidad de empleados del listado sin tener en cuenta los dados de baja
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado de empleados
 * \param T int - Recibe el tamanio del array
 * \return int - Devuelve la cantidad de empleados
 *
 */
int contarEmpleados(empleadoEst empleadoData[], int T)
{
    int i;
    int cantidadEmpleados;

    cantidadEmpleados = 0;

    for(i=0; i<T;i++)
    {
        if(empleadoData[i].estaVacio==0)
        {
            cantidadEmpleados++;
        }
    }
    return cantidadEmpleados;
}


/** \brief - Cuenta la cantidad de empleados que superan el sueldo promedio
 *
 * \param empleadoData[] empleadoEst - Recibe el array listado de empleados
 * \param T int -  Recibe el tamanio del array listado de empleados
 * \param salarioPromedio float - Recibe el salario  promedio
 * \return int - Devuelve la cantidad de empleados que superan el sueldo promedio
 *
 */
int contarEmpleadosSuperanSueldoPromedio(empleadoEst empleadoData[], int T, float salarioPromedio)
{
    int i;
    int contador;

    contador = 0;

    for(i=0; i<T;i++)
    {
        if(empleadoData[i].estaVacio==0 && empleadoData[i].salario >= salarioPromedio)
        {
            contador++;
        }
    }

    return contador;

}


/** \brief - Pone en mayuscula la primer letra de la cadena de caracteres
 *
 * \param cadena[] char - Recibe una cadena
 * \return void - No devuelve nada
 *
 */
void formatearNombrePropio(char cadena[])
{
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
}//
