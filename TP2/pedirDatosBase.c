#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pedirDatosBase.h"
#include "validarTipoDato.h"

/** \brief Pide al usuario que ingrese un numero por teclado
 *
 * \param mensaje[] char - Recibe el mensaje para mostrar al usuario
 * \return int - Devuelve el numero ingresado por el usuario
 *
 */
 int pedirEntero(char mensaje[])
 {
     int entero;

     printf(mensaje);
     scanf("%d", &entero);
     while(isdigit(entero)==1)
     {
        printf(mensaje);
        scanf("%d", &entero);
     }

     return entero;
 }


/** \brief Pide al usuario que ingrese texto por teclado
 *
 * \param msj[] char - Recibe el mensaje para mostrar al usuario
 * \param mensajeError[] char - Recibe el mensaje de error para mostrar al usuario
 * \param cadena[] char - Recibe la posicion de la cadena donde se va a almacenar el texto ingresado por teclado
 * \param TAMANIO_CADENA int - Recibe el tamanio de la cadena
 * \return void - No devuelve nada
 *
 */
void obtenerCadena(char msj[], char mensajeError[], char cadena[], int TAMANIO_CADENA)
{
    printf(msj);
    fflush(stdin);
    fgets(cadena, TAMANIO_CADENA, stdin);
    //while(validarSiEsChar(cadena)== 0)
    while(validarSiEsChar(cadena)== 0)
    {
        printf(mensajeError);
        fflush(stdin);
        fgets(cadena, TAMANIO_CADENA, stdin);
    }
}


/** \brief - Pide al usuario que ingrese un numero por teclado
 *
 * \param mensaje[] char - Recibe el mensaje para mostrar al usuario
 * \return float - Devuelve el numero ingresado por teclado
 *
 */
float pedirNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    printf(mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}


/** \brief - Reemplaza saltos de linea por espacios
 *
 * \param string[] char - Recibe una cadena de caracteres
 * \return char - Devuelve la cadena con espacios en lugar de saltos
 *
 */
char remmplazarSaltoPorEspacio(char string[])
{
    int i;
    for(i=0;string[i] != '\0';i++)
    {
        if(string[i] == '\n')
        {
            string[i] = '\0';
        }
    }
    return string[i];
}


/** \brief - Pide al usuario confirmacion para ejecutar una accion
 *
 * \param void - No recibe nada
 * \return int - Si el usuario confirma, devuelve 1, sino un 0
 *
 */
int confirmarAccionUsuario(void)
{
    int continuar;
    char respuesta;

    printf("Para continuar ingresar S, para cancelar presionar cualquier tecla \n");
    fflush(stdin);
    scanf("%c", &respuesta);

    if(respuesta == 's' || respuesta == 'S')
    {
        continuar = 1;
    }
    else
    {
        continuar = 0;
    }
    return continuar;
}

/** \brief - Pide al usuario ingresar una cadena de caracteres. Valida que la direccion de memoria sea valida y si encuenta un salto de linea lo reemplaza por un espacio
 *
 * \param cadena char* - Recibe lugar donde se va a guardar el numero ingresado
 * \param TAMANIO_CADENA int - Recibe tamanio de la cadena
 * \return int - - Devuelve resultado de la operacion: o operacion exitosa, sino -1
 *
 */
int getCharBase(char* cadena, int TAMANIO_CADENA)
{
    int retorno;
    char bufferString[2000];

    retorno = -1;

    if(cadena != NULL && TAMANIO_CADENA > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString) <= TAMANIO_CADENA)
            {
                strncpy(cadena, bufferString, TAMANIO_CADENA);
                retorno = 0;
            }
        }
    }
    return retorno;
}


/** \brief - Lee una cadena de caracteres. Si su contenido es numerico, lo convierte a tipo int y lo guarda en un espacio de memoria recibido por parametro
 *
 * \param numero int* - Recibe lugar donde se va a guardar el numero ingresado
 * \return int - Devuelve resultado de la operacion: o operacion exitosa, sino -1
 *
 */
int getNumberBase(int* numero)
{
    int retorno = -1;
    char bufferString[50];

    if(numero != NULL && getCharBase(bufferString, sizeof(bufferString)) == 0 && validateIsNumber(bufferString, sizeof(bufferString)) == 0)//&& falta un if q vaidar si es numero
    {
       retorno = 0;
       *numero = atoi(bufferString);
    }
    return retorno;
}


/** \brief - Pide al usuario ingresar numero por teclado
 *
 * \param numero int* - Recibe lugar donde se va a guardar el numero ingresado
 * \param mensaje[] char - Recibe mensaje a mostrar al usuario
 * \param mensajeError[] char - Recibe mensaje de error a mostrar al usuario
 * \param minimo int - Recibe el valor minimo que puede ingresar
 * \param maximo int - Recibe el valor maximo que puede ingresar
 * \param reintentos int - Recibe la cantidad de veces que puede equivocarse
 * \return int - Devuelve resultado de la operacion: o operacion exitosa, sino -1
 *
 */
int pedirNumero(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;

    do
    {
        printf("%s", mensaje);
        if(getNumberBase(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
        {
            retorno = 0;
            *numero = bufferInt;
            break;
        }
        printf("%s", mensajeError);
        reintentos --;
    }
    while(reintentos >= 0);

    return retorno;
}
