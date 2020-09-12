#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/** \brief Realiza la suma entre dos numeros
 *
 * \param primerOperando float Recibe el primer operando
 * \param segundoOperando float Recibe el segundo operando
 * \return float Devuelve el resultado de la operacion
 *
 */
float sumarNumeros(float primerOperando, float segundoOperando)
{
    float resultado;

    resultado = primerOperando + segundoOperando;

    return resultado;
}

/** \brief Realiza la division entre dos numeros
 *
 * \param primerOperando float Recibe el primer operando
 * \param segundoOperando float Recibe el segundo operando
 * \return float Devuelve el resultado de la operacion
 *
 */
float dividirNumeros(float primerOperando, float segundoOperando)
{
    float resultado;

    if(segundoOperando != 0){
        resultado = primerOperando / segundoOperando;
    }
    else{
        resultado = 0;
    }


    return resultado;
}


/** \brief Realiza la resta entre dos numeros
 *
 * \param primerOperando float Recibe el primer operando
 * \param segundoOperando float Recibe el segundo operando
 * \return float Devuelve el resultado de la operacion
 *
 */
float restarNumeros(float primerOperando, float segundoOperando)
{
    float resultado;

    resultado = primerOperando - segundoOperando;

    return resultado;
}

/** \brief Realiza la multiplicacion entre dos numeros
 *
 * \param primerOperando float Recibe el primer operando
 * \param segundoOperando float Recibe el segundo operando
 * \return float Devuelve el resultado de la operacion
 *
 */
float multiplicarNumeros(float primerOperando, float segundoOperando)
{
    float resultado;

    resultado = primerOperando * segundoOperando;

    return resultado;
}

/** \brief Calcula el factorial de un numero
 *
 * \param numeroACalcularFactor float Recibe el numero cuyo factorial se va a calcular
 * \return int Devuelve el fctorial del numero ingresado
 *
 */
int factorial(float numeroACalcularFactor)
{
    int factorial;
    float resto;

    resto = fmod(numeroACalcularFactor, 1);
    printf("resto %f", resto);

    if(numeroACalcularFactor==0)
    {
        factorial = 1;
    }
    else
    {
        if(resto==0)
        {
            for(factorial = numeroACalcularFactor; numeroACalcularFactor > 1 ; numeroACalcularFactor--)
            {
                factorial = factorial*(numeroACalcularFactor-1);
                printf("factorial es %d", factorial);
            }
        }
        else
        {
            factorial = 0;
        }
    }


    return factorial;

}
