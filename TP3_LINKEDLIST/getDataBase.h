#ifndef GETDATABASE_H_INCLUDED
#define GETDATABASE_H_INCLUDED
int getString(char* pChar, int stringSize, char message[], char errorMessage[], int attempts);
int getInt(int* pNumber, char message[], char errorMessage[], int min, int max, int attempts);
<<<<<<< HEAD
int getNumber(char* pNumber, int pNumberSize, char message[], char errorMessage[], int attempts);
char remmplazarSaltoPorEspacio(char* string);
int getBase(char* string, int stringSize);
=======
int getFloat(float* pNumber, char message[], char errorMessage[], int min, int max, int attempts);
int validateIsAlpha(char* string);
int validateIsNumber(char string[]);
char remmplazarSaltoPorEspacio(char* string);
>>>>>>> 62c380ab7b047a4487f5fd1d6ed887ff99b870d6
#endif // GETDATABASE_H_INCLUDED
