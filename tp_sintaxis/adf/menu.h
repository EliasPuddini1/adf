#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
#include "evaluation_utils.h"
#include "parser.h"


void mostrarMenuParseado(void);
void mostrarMenuSecundario(void);

char cadenaPrueba[100] = "-01230$-01231$1A$012347$0xFFFF";
    char string[40] = "2+3*4/3-2";
    char stringA[40];
void mostrarMenu() {
    int opcion_Menu_Principal;
    do {
        printf("1. Parsear operaciones matematicas.\n");
        printf("2. Evaluar una cadena en los sistemas numericos Decimales, Octales y Hexadecimal\n");
        printf("3. Salir.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion_Menu_Principal);

        switch (opcion_Menu_Principal) {
            case 1:
                mostrarMenuParseado();
                break;
            case 2:
                mostrarMenuSecundario();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("\nOpcion invalida\n");
                break;
        }
    } while (opcion_Menu_Principal != 3);
}

void mostrarMenuSecundario() {
    int opcion_Menu_Secundario;
    char* cadena;
    do {
        printf("1. Ingresar por consola.\n");
        printf("2. Ingresar por archivo.\n");
        printf("3. Volver al menu anterior.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion_Menu_Secundario);
        //se maneja de igual forma que la pantalla principal
        switch (opcion_Menu_Secundario) {
                    case 1:
                        cadena = obtenerDatosConsola();
                        procesar_palabra(cadena);
                        break;
                    case 2:
                        obtenerDatosArchivo();
                        procesar_palabra(cadena);
                        break;
            case 3:
                break;
            default:
                printf("\nOpcion invalida\n");
                break;
    }
    }while (opcion_Menu_Secundario != 3);

}

 void mostrarMenuParseado(){
    int opcion_Menu_Parseado;
    do{
        printf("1. Ingresar por consola.\n");
        printf("2. Ver un ejemplo.\n");
        printf("3. Volver al menu anterior.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion_Menu_Parseado);

            switch (opcion_Menu_Parseado) {
                    case 1:

                    break;
                    case 2:
                    printf("Operacion de Ejemplo: %s\n",string);

                    break;
            case 3:
                printf("\nVolviendo al menu anterior.\n\n");
                return;
            default:
                printf("\nOpcion invalida\n");
                break;
        }
    } while (opcion_Menu_Parseado != 3);
}

char obtenerDatosArchivo(){
    char cadena_Archivo[40];
    char archivoTxt[20] = "automata.txt";
    FILE* automata = fopen(archivoTxt, "r");
    if (automata == NULL) {
        printf("archivo no encontrado\n");
        exit(1);
    } else {
    fgets(cadena_Archivo, sizeof(cadena_Archivo), automata);
    return cadena_Archivo;
    }
}

char* obtenerDatosConsola (){
    char cadena_consola[100];
    printf("ingrese una cadena: ");
    scanf("%s",&cadena_consola);
    return cadena_consola;
}
