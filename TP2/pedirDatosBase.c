#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pedirDatosBase.h"
#include "validarTipoDato.h"

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


float pedirNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    printf(mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}


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
