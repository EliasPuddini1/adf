#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_utils.h"

int main()
{
    char cadena[100]= "-01230$-01231$1A$012347$0xFFFF";
    //printf("respuesta %d",str_to_int("52322"));

    char * token = strtok(cadena, "$");
    int contador_numeros_decimales=0;
    int contador_numeros_octales=0;
    int contador_numeros_hexadecimales =0;

    while( token != NULL )
    {
        int respuesta_evaluar_decimal = evaluar_decimal(token);
        int respuesta_evaluar_octal = evaluar_octal(token);
        int respuesta_evaluar_hexadecimal = evaluar_hexadecimal(token);

        if(respuesta_evaluar_decimal)
        {
            contador_numeros_decimales++;
        }
        if(respuesta_evaluar_octal)
        {
            contador_numeros_octales++;
        }
        if(respuesta_evaluar_hexadecimal)
        {
            contador_numeros_hexadecimales++;
        }

        token = strtok(NULL, "$");

        printf("*************************************\n");
    }
    printf("palabras DECIMALES : %d , OCTALES: %d , HEXADECIMALES: %d", contador_numeros_decimales, contador_numeros_octales, contador_numeros_hexadecimales);


    return 0;
}

int evaluar_decimal(char *cadena)
{
    int respuesta_verifica_alfabeto_decimal = verifica_alfabeto_decimal(cadena);
    printf("verifica alfabeto decimal %s? %d\n",cadena,respuesta_verifica_alfabeto_decimal);
    int respuesta_es_palabra_decimal = 0;

    if(respuesta_verifica_alfabeto_decimal==1)
    {
        respuesta_es_palabra_decimal =es_palabra_decimal(cadena);
        printf("es palabra decimal %s? %d\n",cadena,respuesta_es_palabra_decimal);

    }
    else
    {
        printf("No se evalua la palabra %s porque no verifica alfabeto decimal\n", cadena);
    }
    return respuesta_es_palabra_decimal;
}

int verifica_alfabeto_decimal(char *s)
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
/******************* OCTAL ************************/
int evaluar_octal(char *cadena)
{
    int respuesta_verifica_alfabeto_octal = verifica_alfabeto_octal(cadena);
    printf("verifica alfabeto octal %s? %d\n",cadena,respuesta_verifica_alfabeto_octal);
    int respuesta_es_palabra_octal= 0;


    if(respuesta_verifica_alfabeto_octal==1)
    {
        respuesta_es_palabra_octal = es_palabra_octal(cadena);
        printf("es palabra octal %s? %d\n",cadena,respuesta_es_palabra_octal);

    }
    else
    {
        printf("No se evalua la palabra %s porque no verifica alfabeto octal\n", cadena);
    }
    return respuesta_es_palabra_octal;
}

int verifica_alfabeto_octal(char *s)
{
    unsigned int i;

    for(i=0; s[i]; i++)
    {
        if(!(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'))
        {
            return 0;
        }
    }

    return 1;
}

int es_palabra_octal(char *cadena)
{
    const int FINAL_STATE = 1;
    const int INVALID_STATE = 2;


    const int tt[3][8]=
    {
        {FINAL_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
        {FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE},
        {INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE}
    };

    int estado = 0;
    int i=0;
    int c= cadena[i];
    while(c!='\0')
    {
        estado=tt[estado][columna_octal(c)];
        c = cadena[++i];
    }

    if(estado == FINAL_STATE)
    {
        return 1;
    }
    return 0;
}

int columna_octal(int c)
{
    switch(c)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    }
}

/******************* HEXADECIMAL ************************/
int evaluar_hexadecimal(char *cadena)
{
    int respuesta_verifica_alfabeto_hexadecimal = verifica_alfabeto_hexadecimal(cadena);
    printf("verifica alfabeto hexadecimal %s? %d\n",cadena,respuesta_verifica_alfabeto_hexadecimal);
    int respuesta_es_palabra_hexadecimal= 0;

    if(respuesta_verifica_alfabeto_hexadecimal==1)
    {
        respuesta_es_palabra_hexadecimal = es_palabra_hexadecimal(cadena);
        printf("es palabra hexadecimal %s? %d\n",cadena,respuesta_es_palabra_hexadecimal);

    }
    else
    {
        printf("No se evalua la palabra %s porque no verifica alfabeto hexadecimal\n", cadena);
    }
    return respuesta_es_palabra_hexadecimal;
}

int verifica_alfabeto_hexadecimal(char *s)
{
    unsigned int i;

    for(i=0; s[i]; i++)
    {
        if(!(toupper(s[i])== 'A'||toupper(s[i])== 'B'||toupper(s[i])== 'C'||toupper(s[i])== 'D'||toupper(s[i])== 'E'||toupper(s[i])== 'F'||toupper(s[i])== 'X'||isdigit(s[i])))
        {
            return 0;
        }
    }

    return 1;
}

int es_palabra_hexadecimal(char *cadena)
{
    const int FINAL_STATE = 2;
    const int INVALID_STATE = 3;

    const int tt[4][24]=
    {
        {INVALID_STATE,INVALID_STATE,1,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
        {FINAL_STATE,FINAL_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
        {INVALID_STATE,INVALID_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE},
        {INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
    };

    int estado = 0;
    int i=0;
    int c= cadena[i];
    while(c!='\0')
    {
        estado=tt[estado][columna_hexadecimal(c)];
        c = cadena[++i];
    }

    if(estado == FINAL_STATE)
    {
        return 1;
    }
    return 0;
}

int columna_hexadecimal(int c)
{
    switch(c)
    {
    case 'x':
        return 0;
        break;
    case 'X':
        return 1;
        break;
    case '0':
        return 2;
        break;
    case '1':
        return 3;
        break;
    case '2':
        return 4;
        break;
    case '3':
        return 5;
        break;
    case '4':
        return 6;
        break;
    case '5':
        return 7;
        break;
    case '6':
        return 8;
        break;
    case '7':
        return 9;
        break;
    case '8':
        return 10;
        break;
    case '9':
        return 11;
        break;
    case 'a':
        return 12;
        break;
    case 'A':
        return 13;
        break;
    case 'b':
        return 14;
        break;
    case 'B':
        return 15;
        break;
    case 'c':
        return 16;
        break;
    case 'C':
        return 17;
        break;
    case 'd':
        return 18;
        break;
    case 'D':
        return 19;
        break;
    case 'e':
        return 20;
        break;
    case 'E':
        return 21;
        break;
    case 'f':
        return 22;
        break;
    case 'F':
        return 23;
        break;
    }
}
