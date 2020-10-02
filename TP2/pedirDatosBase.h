#ifndef PEDIRDATOSBASE_H_INCLUDED
#define PEDIRDATOSBASE_H_INCLUDED

int pedirEntero(char mensaje[]);
void obtenerCadena(char msj[], char mensajeError[], char cadena[], int TAMANIO_CADENA);
float pedirNumeroFlotante(char mensaje[]);
char remmplazarSaltoPorEspacio(char string[]);
int confirmarAccionUsuario(void);

int getCharBase(char* cadena, int TAMANIO_CADENA);
int getNumberBase(int* numero);
int pedirNumero(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
#endif // PEDIRDATOSBASE_H_INCLUDED
