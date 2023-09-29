#include <stdio.h>
void mostrarMenuPrincipal(int *opcion_Menu_Principal) {
    do {
        printf("1. Parsear operaciones matematicas.\n");
        printf("2. Evaluar una cadena en los sistemas numericos Decimales, Octales y Hexadecimal\n");
        printf("3. Salir.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", opcion_Menu_Principal);

        switch (*opcion_Menu_Principal) {
            case 1:
            case 2:
                return; // el programa main.c maneja las opciones.
            case 3:
                printf("Saliendo del programa.\n");
                return; // el Programa main.c maneja la salida del programa.
            default:
                printf("\nOpcion invalida\n");
                break;
        }
    } while (*opcion_Menu_Principal != 3);
}

void mostrarMenuSecundario(int *opcion_Menu_Secundario) {
    do {
        printf("1. Ingresar por consola.\n");
        printf("2. Ingresar por archivo.\n");
        printf("3. Volver al menu anterior.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", opcion_Menu_Secundario);
        //se maneja de igual forma que la pantalla principal
        switch (*opcion_Menu_Secundario) {
            case 1:
            case 2:
                return;
            case 3:
                printf("\nVolviendo al menu anterior.\n\n");
                return;
            default:
                printf("\nOpcion invalida\n");
                break;
        }
    } while (*opcion_Menu_Secundario != 3);
}

 void mostrarMenuParseado(int *opcion_Menu_Parseado){
    do{
        printf("1. Ingresar por consola.\n");
        printf("2. Ver un ejemplo.\n");
        printf("3. Volver al menu anterior.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", opcion_Menu_Parseado);
        //se maneja de igual forma que la pantalla principal
        switch (*opcion_Menu_Parseado) {
            case 1:
            case 2:
                return;
            case 3:
                printf("\nVolviendo al menu anterior.\n\n");
                return;
            default:
                printf("\nOpcion invalida\n");
                break;
        }
    } while (*opcion_Menu_Parseado != 3);
}
