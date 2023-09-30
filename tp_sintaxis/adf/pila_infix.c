#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_PILA 100 // Tamaño máximo de la pila
#define SIZE_STRING 50 // Longitud máxima de las cadenas

typedef struct {
    char expresion[SIZE_PILA][SIZE_STRING];
    int orden; 
} Operaciones;

// Función para inicializar una pila vacía
void initialize(Operaciones *operacion) {
    operacion->orden = -1; 
}

// Función para verificar si la pila está vacía
bool isEmpty(Operaciones *operacion) {
    return operacion->orden == -1;
}

bool isFull(Operaciones *operacion) {
    return operacion->orden == SIZE_PILA - 1;
}

void push(Operaciones *operacion, const char *value) {
    if (isFull(operacion)) {
    } else {
        operacion->orden++;
        strncpy(operacion->expresion[operacion->orden], value, SIZE_STRING);
        operacion->expresion[operacion->orden][SIZE_STRING - 1] = '\0'; 
    }
}

// Función para sacar una cadena de la pila (pop)
const char *pop(Operaciones *operacion) {
    if (isEmpty(operacion)) {
        return NULL; 
    } else {
        return operacion->expresion[operacion->orden--]; 
    }
}

int main() {
    Operaciones operacion;
    initialize(&operacion);
    //printf("ingrese una operacion a resolver:");
    // char input[100]; 
    // scanf("%s",input);
    const char input[] = "-21+5*4-15/5+4";
    int len = strlen(input);
    char currentPart[len]; // Almacenar la parte actual
    char signos[1]; //Almacenar signo
    int part = 1;
    int j = 0;

    for (int i = 0; i < len; i++) {
        char currentChar = input[i];
        signos[0] = input[i];
        if (currentChar == '+' || currentChar == '-') {
            currentPart[j] = '\0'; 
            signos[1] = '\0';
            push(&operacion, currentPart);
            push(&operacion, signos);
            part++;
            j = 0;
        } else {
            currentPart[j++] = currentChar;
        }
    }

    currentPart[j] = '\0'; 
    push(&operacion, currentPart);

    // Imprimimos los elementos de la pila en orden, que contendrán números y operadores
    while (!isEmpty(&operacion)) {
        printf("%s\n", pop(&operacion));
    }

    return 0;
}