#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Estructura para la pila de operandos
typedef struct {
    int *items;
    int top;
    int size;
} OperandStack;

// Estructura para la pila de operadores
typedef struct {
    char *items;
    int top;
    int size;
} OperatorStack;

// Funciones para la pila de operandos
OperandStack *createOperandStack(int size) {
    OperandStack *stack = (OperandStack *)malloc(sizeof(OperandStack));
    stack->items = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void pushOperand(OperandStack *stack, int value) {
    if (stack->top < stack->size - 1) {
        stack->items[++stack->top] = value;
    } else {
        // Manejar error de desbordamiento de la pila (puedes implementar manejo de errores adecuado)
    }
}

int popOperand(OperandStack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        // Manejar error de desbordamiento de la pila (puedes implementar manejo de errores adecuado)
        return 0; // Valor predeterminado en caso de error
    }
}

// Funciones para la pila de operadores
OperatorStack *createOperatorStack(int size) {
    OperatorStack *stack = (OperatorStack *)malloc(sizeof(OperatorStack));
    stack->items = (char *)malloc(sizeof(char) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void pushOperator(OperatorStack *stack, char value) {
    if (stack->top < stack->size - 1) {
        stack->items[++stack->top] = value;
    } else {
        // Manejar error de desbordamiento de la pila (puedes implementar manejo de errores adecuado)
    }
}

char popOperator(OperatorStack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        // Manejar error de desbordamiento de la pila (puedes implementar manejo de errores adecuado)
        return '\0'; // Valor predeterminado en caso de error
    }
}

int evaluarExpresionRPN(const char *expresionRPN) {
    OperandStack *stack = createOperandStack(100);

    for (int i = 0; expresionRPN[i] != '\0'; i++) {
        char caracter = expresionRPN[i];

        if (isdigit(caracter) || (caracter == '-' && isdigit(expresionRPN[i + 1]))) {
            // Leer un n�mero
            int numero = strtol(&expresionRPN[i], NULL, 10);
            pushOperand(stack, numero);
            // Mover el �ndice 'i' al final del n�mero
            while (isdigit(expresionRPN[i]) || expresionRPN[i] == '-') {
                i++;
            }
            i--;
        } else if (caracter == '+') {
            int operand2 = popOperand(stack);
            int operand1 = popOperand(stack);
            pushOperand(stack, operand1 + operand2);
        } else if (caracter == '-') {
            int operand2 = popOperand(stack);
            int operand1 = popOperand(stack);
            pushOperand(stack, operand1 - operand2);
        } else if (caracter == '*') {
            int operand2 = popOperand(stack);
            int operand1 = popOperand(stack);
            pushOperand(stack, operand1 * operand2);
        } else if (caracter == '/') {
            int operand2 = popOperand(stack);
            int operand1 = popOperand(stack);
            if (operand2 != 0) {
                pushOperand(stack, operand1 / operand2);
            } else {
                printf("Error: Divisi�n por cero.\n");
                exit(1);
            }
        }
    }

    int resultado = popOperand(stack);

    // Liberar la memoria de la pila de operandos
    free(stack->items);
    free(stack);

    return resultado;
}

// Funci�n para determinar la prioridad de los operadores
int getPriority(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }
    return 0; // Operador no reconocido
}

// Funci�n para convertir expresi�n infija a posfija sin par�ntesis
void infixToPostfixNoParentheses(const char *expresionInfix, char *expresionPostfix) {
    int stack[100];
    int top = -1;
    int outputIndex = 0;

    for (int i = 0; expresionInfix[i] != '\0'; i++) {
        char caracter = expresionInfix[i];

        if (isdigit(caracter)) {
            // Si es un d�gito, agregarlo directamente a la salida
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

    printf("Ingrese una expresi�n aritm�tica en notaci�n infija sin par�ntesis: ");
    fgets(expresionInfix, sizeof(expresionInfix), stdin);
    expresionInfix[strlen(expresionInfix) - 1] = '\0'; // Eliminar el salto de l�nea al final

    infixToPostfixNoParentheses(expresionInfix, expresionPostfix);
    printf("Expresi�n en notaci�n posfija: %s\n", expresionPostfix);

    int resultado = evaluarExpresionRPN(expresionPostfix);
    printf("Resultado: %d\n", resultado);

    return 0;
}
