#include <stdlib.h>
#include <stdio.h>

/** \brief Pide al usuario que ingrese un entero por consola
 *
 * \param mensaje[] char Recibe por parametro el texto que se le quiere mostrar al usuario
 * \return int Devuelve el entero ingresado por el usuario
 *
 */
int pedirEntero(char mensaje[])
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

/** \brief Pide al usuario que ingrese un numero que puede ser de punto flotante por consola
 *
 * \param mensaje[] char Recibe por parametro el texto que se le quiere mostrar al usuario en el mensaje
 * \return int Devuelve el punto floitante ingresado por el usuario
 *
 */
float pedirNumero(char mensaje[])
{
    float numeroIngresado;

    printf("%s", mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}

/** \brief Pide al usuario que ingrese una cadena de caracteres
 *
 * \param msj[] char Recibe por parametro el texto que se le quiere mostrar al usuario en el mensaje
 * \param cadena[] char Recibe el nombre del vector donde se va a almacenar el teto ingresado por consola
 * \param tamanio int Recibe el la longitud del vector
 * \return void
 *
 */
void obtenerCadena(char msj[], char cadena[], int tamanio)
{
    printf(msj);
    fflush(stdin);
    fgets(cadena,tamanio,stdin);
}


