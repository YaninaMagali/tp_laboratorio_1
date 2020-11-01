#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "getData.h"

/** \brief valida que en la cadena ingresada este compuesta unicamente por letras
 * \param cadena[] char - Recibe un array de char
 * \return int - Devuelve un 0 cuando encuentra un dato distinto de letra, y un 1 si es letra
 *
 */
int validateIsAlpha(char* string)
{
    int i;
    int isAlpha;
    int T;

    T = strlen(string)-1;

    for(i=0; i< T; i++)
    {
        if(isalpha(string[i])==0)
        {
            isAlpha = 0;
            break;
        }
        else
        {
            isAlpha = 1;
        }
    }
    return isAlpha;
}

int validateIsNumber(char string[])
{
    int i;
    int isDigit;
    int T;

    T = strlen(string)-1;

    for(i=0; i< T; i++)
    {
        if(isdigit(string[i])==0)
        {
            isDigit = 0;
            break;
        }
        else
        {
            isDigit = 1;
        }
    }
    return isDigit;
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
