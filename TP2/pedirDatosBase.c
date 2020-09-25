#include <stdio.h>
#include <stdlib.h>
#include "pedirDatosBase.h"
#include "validarTipoDato.h"

int pedirEntero(char mensaje[])
 {
     int entero;

     printf(mensaje);
     scanf("%d", &entero);

     return entero;
 }

void obtenerCadena(char msj[], char mensajeError[], char cadena[])
{
    printf(msj);
    fflush(stdin);
    gets(cadena);
    while(validarSiEsChar(cadena)==0)
    {
        printf(mensajeError);
        fflush(stdin);
        gets(cadena);
    }
}

float pedirNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    printf("%s", mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}

