#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int evaluarExpresionRPN(const char *expresionRPN) {
    int stack[100]; // Pila para almacenar operandos
    int top = -1;   // �ndice del elemento superior de la pila

    for (int i = 0; expresionRPN[i] != '\0'; i++) {
        char caracter = expresionRPN[i];

        if (isdigit(caracter) || (caracter == '-' && isdigit(expresionRPN[i + 1]))) {
            // Leer un n�mero
            int numero = strtol(&expresionRPN[i], NULL, 10);
            stack[++top] = numero;
            // Mover el �ndice 'i' al final del n�mero
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
                printf("Error: Divisi�n por cero.\n");
                exit(1);
            }
        }
    }

    return stack[top];
}


int main() {


    char expresionRPN[100];

    printf("Ingrese una expresi�n aritm�tica en RPN: ");
    fgets(expresionRPN, sizeof(expresionRPN), stdin);
    expresionRPN[strlen(expresionRPN) - 1] = '\0'; // Eliminar el salto de l�nea al final

    int resultado = evaluarExpresionRPN(expresionRPN);
    printf("Resultado: %d\n", resultado);

    return 0;
}
