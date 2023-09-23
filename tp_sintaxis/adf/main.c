#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_utils.h"

int main()
{
    char cadena[20]= "-01230$-01231$1A";
    //printf("respuesta %d",stringToInt("52322"));

    char * token = strtok(cadena, "$");

    while( token != NULL )
    {
        int respuesta_evaluar_decimal = evaluar_decimal(token);
        token = strtok(NULL, "$");
    }
    return 0;
}

int evaluar_decimal(char *cadena)
{
    int respuesta_verifica_decimal = verifica_decimal(cadena);
    printf("verifica alfabeto decimal %s? %d\n",cadena,respuesta_verifica_decimal);

    if(respuesta_verifica_decimal==1)
    {
        printf("es palabra decimal %s? %d\n",cadena,es_palabra_decimal(cadena));

    }
    else
    {
        printf("No se evalua la palabra %s porque no verifica alfabeto\n", cadena);
    }
}

int verifica_decimal(char *s)
{
    unsigned int i;

    for(i=0; s[i]; i++)
    {
        if(!(s[i]=='+'|| s[i]=='-'||isdigit(s[i])))
        {
            return 0;
        }
    }

    return 1;
}

int es_palabra_decimal(char *cadena)
{
    const int FINAL_STATE = 2;
    const int INVALID_STATE = 3;


    const int tt[4][3]=
    {
        {FINAL_STATE,1,1},
        {FINAL_STATE,INVALID_STATE,INVALID_STATE},
        {FINAL_STATE,INVALID_STATE,INVALID_STATE},
        {INVALID_STATE,INVALID_STATE,INVALID_STATE}
    };

    int estado = 0;
    int i=0;
    int c= cadena[i];
    while(c!='\0')
    {
        estado=tt[estado][columna_decimal(c)];
        c = cadena[++i];
    }

    if(estado == FINAL_STATE)
    {
        return 1;
    }
    return 0;
}

int columna_decimal(int c)
{
    switch(c)
    {
    case '+':
        return 1;
    case '-':
        return 2;
    default:
        return 0;
    }
}
