#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validarSiEsDigito(int digito)
{
    int esDigito;

    if(digito != 0)
    {
        esDigito = 1;

    }
    else
    {
        esDigito = 0;
    }
    return esDigito;

}

int validarSiEsChar(char cadena[])
{
    int i;
    int esAlpha;
    int T;

    T = strlen(cadena)-1;

    for(i=0; i< T; i++)
    {
        if(isalpha(cadena[i])==0)
        {
            esAlpha = 0;
            break;
        }
        else
        {
            esAlpha = 1;
        }
    }
    return esAlpha;
}
