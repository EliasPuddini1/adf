#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int evaluarExpresionRPN(const char *expresionRPN) {
    int stack[100]; // Pila para almacenar operandos
    int top = -1;   // Índice del elemento superior de la pila


    for (int i = 0; expresionRPN[i] != '\0'; i++) {
        char caracter = expresionRPN[i];

        if (isdigit(caracter) || (caracter == '-' && isdigit(expresionRPN[i + 1]))) {
            // Leer un número
            int numero = strtol(&expresionRPN[i], NULL, 10);
            stack[++top] = numero;
            // Mover el índice 'i' al final del número
            while (isdigit(expresionRPN[i]) || expresionRPN[i] == '-') {
                i++;
            }
            i--;
        } else if (caracter == '+') {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            stack[++top] = operand1 + operand2;
        } else if (caracter == '-') {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            stack[++top] = operand1 - operand2;
        } else if (caracter == '*') {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            stack[++top] = operand1 * operand2;
        } else if (caracter == '/') {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            if (operand2 != 0) {
                stack[++top] = operand1 / operand2;
            } else {
                printf("Error: División por cero.\n");
                exit(1);
            }
        }
    }

    return stack[top];
}

// Función para determinar la prioridad de los operadores
int getPriority(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }
    return 0; // Operador no reconocido
}

// Función para convertir expresión infija a posfija sin paréntesis
void infixToPostfixNoParentheses(const char *expresionInfix, char *expresionPostfix) {
    int stack[100];
    int top = -1;
    int outputIndex = 0;

    for (int i = 0; expresionInfix[i] != '\0'; i++) {
        char caracter = expresionInfix[i];

        if (isdigit(caracter)) {
            // Si es un dígito, agregarlo directamente a la salida
            while (isdigit(expresionInfix[i])) {
                expresionPostfix[outputIndex++] = expresionInfix[i++];
            }
            expresionPostfix[outputIndex++] = ' '; // Separador
            i--; // Retroceder un paso para compensar el incremento en el bucle for
        } else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {
            // Si es un operador, desapilar operadores de mayor o igual prioridad y agregarlos a la salida
            while (top >= 0 && getPriority(stack[top]) >= getPriority(caracter)) {
                expresionPostfix[outputIndex++] = stack[top--];
                expresionPostfix[outputIndex++] = ' '; // Separador
            }
            stack[++top] = caracter; // Apilar el operador actual
        }
    }

    // Desapilar cualquier operador restante en la pila
    while (top >= 0) {
        expresionPostfix[outputIndex++] = stack[top--];
        expresionPostfix[outputIndex++] = ' '; // Separador
    }

    expresionPostfix[outputIndex] = '\0'; // Terminar la cadena
}

int main() {

    char expresionInfix[100];
    char expresionPostfix[100];

    printf("Ingrese una expresión aritmética en notación infija sin paréntesis: ");
    fgets(expresionInfix, sizeof(expresionInfix), stdin);
    expresionInfix[strlen(expresionInfix) - 1] = '\0'; // Eliminar el salto de línea al final

    infixToPostfixNoParentheses(expresionInfix, expresionPostfix);
    printf("Expresión en notación posfija: %s\n", expresionPostfix);

    int resultado = evaluarExpresionRPN(expresionPostfix);
    printf("Resultado: %d\n", resultado);

    return 0;
}
