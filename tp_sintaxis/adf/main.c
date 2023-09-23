#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_utils.h"

int main()
{
    char s[20]= "-01230";
    //printf("respuesta %d",stringToInt("52322"));
    printf("verifica alfabeto decimal? %d\n",verifica_decimal(s));

    printf("es palabra decimal? %d\n",es_palabra_decimal(s));

    return 0;
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

    const int tt[4][3]=
    {
        {2,1,1},
        {2,3,3},
        {2,3,3},
        {3,3,3}
    };

    int estado = 0;
    int i=0;
    int c= cadena[i];
    while(c!='\0')
    {
        estado=tt[estado][columna(c)];
        c = cadena[++i];
    }

    if(estado == 2)
    {
        return 1;
    }
    return 0;
}

int columna(int c)
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
