#include <stdlib.h>
#include <stdio.h>

/** \brief Muestra por pantalla el resultado de la operacion
 *
 * \param operandoUno float Recibe el primer operando
 * \param signo char Recibe el signo que representa la operacion /, *, + y -
 * \param operandoDos float Recibe el segundo operando
 * \param resultado float Recibe el resultado de la operacion
 * \return void
 *
 */
void mostrarResultadoOperaciones(float operandoUno, char signo, float operandoDos, float resultado)
{
    if(operandoDos == 0 && signo == '/')
    {
        printf("No se puede dividir por 0\n");
    }

    else
    {
        printf("El resultado de %.2f %c %.2f es igual a %.2f\n", operandoUno, signo, operandoDos, resultado);
    }

}


/** \brief Muestra por pantalla el resultado de la operacion factorial
 *
 * \param operandoUno float Recibe el operando
 * \param signo char Recibe el signo de la operacion: '!'
 * \param resultado int Recibe el resultado de la operacion
 * \return void
 *
 */
void mostrarResultadoFactorial(float operandoUno, char signo, int resultado)
{
    if(resultado == 0 && signo == '!')
    {
        printf("No se puede calcular el factorial del numero racional %.2f\n", operandoUno);
    }
    else
    {
        printf("El resultado de %c%.2f es %d\n", signo, operandoUno, resultado);
    }
}

