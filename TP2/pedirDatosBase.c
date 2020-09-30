#include <stdio.h>
#include <stdlib.h>
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


/** \brief Pide al usuario que ingrese un numero por teclado
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
