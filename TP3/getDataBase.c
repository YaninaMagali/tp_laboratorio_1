#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validateDataBase.h"

int getString(char* pChar, int stringSize, char message[], char errorMessage[], int attempts)
 {
    char string;
    int result;

    result = -1;

     do
     {
        printf(message);
        fflush(stdin);
        fgets(&string, stringSize, stdin);
        if(validateIsAlpha(&string)!= 0)
        {
            remmplazarSaltoPorEspacio(&string);
            strncpy(pChar, &string, stringSize);
            result = 0;
            break;
        }
         printf(errorMessage);
         attempts--;
     }
     while(attempts > 0);

     return result;
 }

int getInt(int* pNumber, char message[], char errorMessage[], int min, int max, int attempts)
 {
     int number;

     do
     {
         printf(message);
         scanf("%d", &number);
         if(number >= min && number <= max)
         {
             *pNumber = number;
             break;
         }
         printf(errorMessage);
         attempts--;
     }
     while(attempts > 0);

     return number;
 }

int getFloat(float* pNumber, char message[], char errorMessage[], int min, int max, int attempts)
 {
     float number;

     do
     {
         printf(message);
         scanf("%f", &number);
         if(number >= min && number <= max)
         {
             *pNumber = number;
             break;
         }
         printf(errorMessage);
         attempts--;
     }
     while(attempts > 0);

     return number;
 }
