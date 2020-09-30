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
