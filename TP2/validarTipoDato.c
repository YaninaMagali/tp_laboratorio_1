#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarSiEsDigitoPositivo(char cadena[])
{
    int i;
    int esDigito;

    i = 0;

    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            esDigito = 0;
            break;
        }
        else
        {
            esDigito = 1;
        }
    }
    return esDigito;
}

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
