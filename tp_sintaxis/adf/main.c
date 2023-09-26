#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_utils.h"
#include "evaluation_utils.h"

int main()
{
    char cadena[100]= "-01230$-01231$1A$012347$0xFFFF";
    //printf("respuesta %d",str_to_int("52322"));

    char * token = strtok(cadena, "$");
    int contador_numeros_decimales=0;
    int contador_numeros_octales=0;
    int contador_numeros_hexadecimales =0;

    //mostrar_menu(parsear operacion matematica / evaluar cadena en distintos sistemas numericos)
    //dentro del menu : 1 - ingresar por consola 2- ingresar archivo
    //Nueva linea

    //evaluar cadenas
    while( token != NULL )
    {
        if(evaluar_decimal(token))
        {
            contador_numeros_decimales++;
        }
        else if(evaluar_octal(token))
        {
            contador_numeros_octales++;
        }
        else if(evaluar_hexadecimal(token))
        {
            contador_numeros_hexadecimales++;
        }

        token = strtok(NULL, "$");

        printf("*************************************\n");
    }
    printf("palabras DECIMALES : %d , OCTALES: %d , HEXADECIMALES: %d", contador_numeros_decimales, contador_numeros_octales, contador_numeros_hexadecimales);


    return 0;
}

