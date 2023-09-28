#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <ctype.h>
#include "string_utils.h"
#include "evaluation_utils.h"
#include "menu.h"
#include "parser.h"

int main()
{
    char cadena[100] = "-01230$-01231$1A$012347$0xFFFF";
    char string[LEN] = "2+3*4/3-2";
    char stringA[LEN];
    char cadena_Archivo[40];
    char path[128];
    int opcion_Menu_Principal;
    int opcion_Menu_Secundario;
    int opcion_Menu_Parseado;
    Express e;

    do
    {
        mostrarMenuPrincipal(&opcion_Menu_Principal);

        switch (opcion_Menu_Principal)
        {
        case 1:
            mostrarMenuParseado(&opcion_Menu_Parseado);

            switch (opcion_Menu_Parseado)
            {
            case 1:
                printf("Ingrese un valor: ");
                scanf("%s",stringA);
                initializeExpress(&e, stringA);
                parse(&e);
                printf("El resultado es: %d\n", solve(&e));
                break;
            case 2:
                printf("Operacion de Ejemplo: %s\n",string);
                initializeExpress(&e, string);
                parse(&e);
                printf("El resultado es: %d\n", solve(&e));
                break;
            }
            break;
        case 2:
            mostrarMenuSecundario(&opcion_Menu_Secundario);

            switch (opcion_Menu_Secundario)
            {
            case 1:
                procesar_palabra(cadena);
                break;
            case 2:
                // Operaciones para obtener el Path
                getcwd(path, sizeof(path));
                char file_path[128];
                snprintf(file_path, sizeof(file_path), "%s/automata.txt", path);

                // Apertura del archivo
                FILE* automata = fopen(file_path, "r");
                if (automata == NULL)
                {
                    printf("archivo no encontrado\n");
                    printf("Muestra el path: %s\n", file_path);
                    exit(1);
                }
                else
                {
                    while (fgets(cadena_Archivo, sizeof(cadena_Archivo), automata) != NULL)
                    {
                        procesar_palabra(cadena_Archivo);
                        break;
                    }
                }
                break;
            }
            break;
        case 3:
            break;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
    }
    while (opcion_Menu_Principal != 3);

    return 0;
}
