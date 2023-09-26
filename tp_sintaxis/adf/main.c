#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <ctype.h>
#include "string_utils.h"
#include "evaluation_utils.h"

int main()
{
    char cadena[100]= "-01230$-01231$1A$012347$0xFFFF";
    //printf("respuesta %d",str_to_int("52322"));

    char * token = strtok(cadena, "$");
    char cadena_Archivo[40];
	char path[128];
    int contador_numeros_decimales=0;
    int contador_numeros_octales=0;
    int contador_numeros_hexadecimales =0;

    //mostrar_menu(parsear operacion matematica / evaluar cadena en distintos sistemas numericos)
    //dentro del menu : 1 - ingresar por consola 2- ingresar archivo
    int opcion_Menu_Principal;
    int opcion_Menu_Secundario;
    menu_0:
    do{
        printf("1. Parsear operaciones matematicas.\n");
        printf("2. Evaluar una cadena en los sistemas numericos Decimales, Octales y Hexadecimal\n");
        printf("3. Salir.\n\n\n");
        //Verifica la opcion que ingreso el usuario
        scanf("%d", &opcion_Menu_Principal);
        switch (opcion_Menu_Principal)
        {
        case 1:
            goto menu_1;
            break;
        case 2:
            goto menu_1;
            break;
        case 3:
            goto fin_Programa;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
        
    }while(opcion_Menu_Principal != 3);
    menu_1:
    do{
        //Se procede a mostrar el menu
        printf("1. Ingresar por consola.\n");
        printf("2. Ingresar por archivo.\n");
        printf("3. Volver al menu anterior.\n\n\n");
        printf("Seleccione una opcion: ");
        //Verifica la opcion que ingreso el usuario
        scanf("%d", &opcion_Menu_Secundario);
        //
        switch (opcion_Menu_Secundario) {
            case 1:
            printf("\nUsted ingreso opcion 1.\n");
            goto evalua_Cadena;
            break;
            case 2:
            printf("\nUsted ingreso opcion 2.\n");
            goto evalua_archivo;
            break;
            case 3:
            printf("\nSaliendo del menu.\n");
            goto menu_0;
            break;
            default:
            printf("\nOpcion invalida\n");
        }
    } while (opcion_Menu_Secundario != 3);

    //evaluar cadenas
    evalua_Cadena:
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

    evalua_archivo:
    
    // Operaciones para obtener el Path
    getcwd(path,sizeof(path));
    char file_path[128];
    snprintf(file_path, sizeof(file_path), "%s/automata.txt", path);

    // Apertura del archivo
    FILE* automata = fopen(file_path,"r");
    if (automata == NULL){
        // Si no puedo abrir el archivo retorno error
        printf("archivo no encontrado\n");
        printf("Muestra el path: %s\n",file_path);
		exit(1);
    }else{
        while (fgets(cadena_Archivo,sizeof(cadena_Archivo),automata) != NULL){
            printf("La cadena es: %s\n",cadena_Archivo);
        }
        goto fin_Programa;
    }

    return 0;
    fin_Programa:
    return 0;
}



