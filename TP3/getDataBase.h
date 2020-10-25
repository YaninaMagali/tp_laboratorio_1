#ifndef GETDATABASE_H_INCLUDED
#define GETDATABASE_H_INCLUDED
int getString(char* pChar, int stringSize, char message[], char errorMessage[], int attempts);
int getInt(int* pNumber, char message[], char errorMessage[], int min, int max, int attempts);
int getFloat(float* pNumber, char message[], char errorMessage[], int min, int max, int attempts);
#endif // GETDATABASE_H_INCLUDED
