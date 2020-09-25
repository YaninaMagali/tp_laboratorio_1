#include <stdio.h>
#include <stdlib.h>
#include "pedirDatosBase.h"

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
    while(isalpha(cadena[0])==0){
        printf("Error! Solo se pueden ingresar letras. Ingresa el nombre nuevamente: ");
        fflush(stdin);
        gets(cadena);
    }
}

