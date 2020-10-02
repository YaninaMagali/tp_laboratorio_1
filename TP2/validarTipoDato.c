#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/** \brief valida que en la cadena ingresada este compuesta unicamente por letras
 *
 * \param cadena[] char - Recibe un array de char
 * \return int - Devuelve un 0 cuando encuentra un dato distinto de letra, y un 1 si es letra
 *
 */
int validarSiEsChar(char cadena[])
{
    int i;
    int esCaracter;
    int T;

    T = strlen(cadena)-1;

    for(i=0; i< T; i++)
    {
        if(isalpha(cadena[i])==0)
        {
            esCaracter = 0;
            break;
        }
        else
        {
            esCaracter = 1;
        }
    }
    return esCaracter;
}


/** \brief - Lee una cadena de caracteres. Si su contenido es numerico, devuelve 0, sino -1. Contempla numeros negativos y positivos
 *
 * \param string char* - Recibe direccion de memoria donde se va a almacenar la cadena
 * \param stringSize int - Recibe el tamanio de la cadena
 * \return int - Devuelve resultado de la operacion: o operacion exitosa, sino -1
 *
 */
int validateIsNumber(char* string, int stringSize)
{
    int result = 1; // TRUE
    int i;

    for(i = 0; i < stringSize && string[i] != '\0'; i++)
    {
        if(i == 0 && (string[0] == '+' || string[i] == '-'))
        {
            continue;//Vuelve al For
        }
        if(string[i] > 9 || string[i] < 0)
        {
          result = 0;
          break;
        }/*CONTINUE*/
    }/*BREAK*/
    return result;
}
