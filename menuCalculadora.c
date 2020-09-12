#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "menuCalculadora.h"
#include "obtenerDatos.h"
#include "realizarOperaciones.h"
#include "mostrarDato.h"

/** \brief Muestra un menu y dispara las acciones de acuerdo a la opcion elegida por el usuario
 *
 * \param void No recibe parametros
 * \return void No devuelve datos
 *
 */
void menuCalculadora(void)
{
    int opcion;
    int primerOperandoIngresadoFlag;
    int segundoOperandoIngresadoFlag;
    float primerOperando;
    float segundoOperando;
    float resultadoSuma;
    float resultadoResta;
    float resultadoProducto;
    float resultadoDivision;
    int resultadoFactorialPrimerOperando;
    int resultadoFactorialSegundoOperando;

    char respuestaEditarPrimerOperando[2];
    char respuestaEditarSegundoOperando[2];
    int calculosHechosFlag;

    primerOperando = 0;
    segundoOperando = 0;
    primerOperandoIngresadoFlag = 0;
    segundoOperandoIngresadoFlag = 0;
    calculosHechosFlag = 0;



    do
    {
        printf("Elija una opcion: \n1.Ingresar primer operando A = %.2f \n2.Ingresar segundo operando. B = %.2f \n3.Calcular todas las operaciones\n4.Ver resultados\n5.Salir\n\n", primerOperando, segundoOperando);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                if(primerOperandoIngresadoFlag == 0){
                    primerOperando = pedirNumero("Ingresa el primer operando. ");
                    primerOperandoIngresadoFlag = 1;
                }
                else
                {
                    obtenerCadena("El primer operando ya fue ingresado. Si desea modificarlo ingrese: S\n", respuestaEditarPrimerOperando, 2);
                    //printf("rta es = %s: ", respuestaEditarPrimerOperando);
                    respuestaEditarPrimerOperando[0] = toupper(respuestaEditarPrimerOperando[0]);
                    if(respuestaEditarPrimerOperando[0]== 'S'){
                           primerOperando = pedirNumero("Estas editando el primer operando. Ingresa el valor: ");
                    }
                }
                break;
            case 2:
                if(segundoOperandoIngresadoFlag == 0){
                        segundoOperando = pedirNumero("Ingresa el segundo operando: ");
                        segundoOperandoIngresadoFlag = 1;
                }
                else{
                        obtenerCadena("El segundo operando ya fue ingresado. Si desea modificarlo ingrese: S \n", respuestaEditarSegundoOperando, 2);
                        respuestaEditarSegundoOperando[0] = toupper(respuestaEditarSegundoOperando[0]);
                        printf("rta es %s", respuestaEditarSegundoOperando);
                        if(respuestaEditarSegundoOperando[0]== 'S'){
                           segundoOperando = pedirNumero("Estas editando el segundo operando. Ingresa el valor: ");
                    }
                }
                break;
            case 3:
                if(primerOperandoIngresadoFlag == 0 || segundoOperandoIngresadoFlag == 0 )
                {
                    printf("Falta ingresar al menos uno de los operandos\n");
                }
                else{
                    calculosHechosFlag = 1;
                    resultadoSuma = sumarNumeros(primerOperando, segundoOperando);
                    resultadoDivision = dividirNumeros(primerOperando, segundoOperando);
                    resultadoResta = restarNumeros(primerOperando, segundoOperando);
                    resultadoProducto = multiplicarNumeros(primerOperando, segundoOperando);
                    resultadoFactorialPrimerOperando = factorial(primerOperando);
                    resultadoFactorialSegundoOperando = factorial(segundoOperando);
                    //factorial;
                    printf("Los calculos se realizaron correctamente. Si queres mostrar los resultados seleccina la opcion 4 del menu\n");
                }
                break;
            case 4:
                if(calculosHechosFlag == 0)
                {
                    printf("Todavia no se realizaron las operaciones. Para hacerlo, selecciona la opcion 3 del menu\n");
                }
                else
                {
                    mostrarResultadoOperaciones(primerOperando, '+', segundoOperando, resultadoSuma);
                    mostrarResultadoOperaciones(primerOperando, '/', segundoOperando, resultadoDivision);
                    mostrarResultadoOperaciones(primerOperando, '-', segundoOperando, resultadoResta);
                    mostrarResultadoOperaciones(primerOperando, '*', segundoOperando, resultadoProducto);
                    mostrarResultadoFactorial(primerOperando, '!', resultadoFactorialPrimerOperando);
                    mostrarResultadoFactorial(segundoOperando, '!', resultadoFactorialSegundoOperando);
                    }
                break;
        }
    }while(opcion != 5);


}





