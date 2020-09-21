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
