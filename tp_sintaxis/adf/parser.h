
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Longitud de las expresiones en caracteres
#define LEN 80

// Tamaño de la pila
#define MAX 40

// Definición de la estructura Stack
typedef struct {
    char st[MAX];
    int top;
} Stack;

// Función para inicializar la pila
void initialize(Stack *s) {
    s->top = 0;
}

// Función para insertar un carácter en la pila
void push(Stack *s, char var) {
    s->st[++(s->top)] = var;
}

// Función para obtener un carácter de la pila
char pop(Stack *s) {
    return s->st[(s->top)--];
}

// Función para obtener el valor en la parte superior de la pila
int gettop(Stack *s) {
    return s->top;
}

// Definición de la estructura Express
typedef struct {
    Stack s;
    char *pStr;
    int len;
} Express;

int precedence(char operator)
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char* infixToPostfix(char* infix)
{
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char stack[80];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        // If the scanned character is operand
        // add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // if the scanned character is '('
        // push it in the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }

        // if the scanned character is ')'
        // pop the stack and add it to the
        // output string until empty or '(' found
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }

        // If the scanned character is an operator
        // push it in the stack
        else if (isOperator(infix[i])) {
            while (top > -1
                   && precedence(stack[top])
                          >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    // Pop all remaining elements from the stack
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

// Función para inicializar una expresión
void initializeExpress(Express *e, char *ptr) {
    e->pStr = ptr;
    e->len = strlen(e->pStr);
    initialize(&(e->s));
}

// Función para analizar la expresión
void parse(Express *e) {
    char ch;
    char lastval;
    char lastop;

    for (int j = 0; j < e->len; j++) {
        ch = e->pStr[j];

        if (ch >= '0' && ch <= '9')
            push(&(e->s), ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (gettop(&(e->s)) == 1)
                push(&(e->s), ch);
            else {
                lastval = pop(&(e->s));
                lastop = pop(&(e->s));
                if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-')) {
                    push(&(e->s), lastop);
                    push(&(e->s), lastval);
                } else {
                    switch (lastop) {
                    case '+':
                        push(&(e->s), pop(&(e->s)) + lastval);
                        break;
                    case '-':
                        push(&(e->s), pop(&(e->s)) - lastval);
                        break;
                    case '*':
                        push(&(e->s), pop(&(e->s)) * lastval);
                        break;
                    case '/':
                        push(&(e->s), pop(&(e->s)) / lastval);
                        break;
                    default:
                        printf("\nOperador desconocido");
                        exit(1);
                    }
                }
                push(&(e->s), ch);
            }
        } else {
            printf("\nCarácter de entrada desconocido");
            exit(1);
        }
    }
}

// Función para resolver la expresión
int solve(Express *e) {
    char lastval;
    e->pStr = infixToPostfix(e->pStr);


    while (gettop(&(e->s)) > 1) {
        lastval = pop(&(e->s));
        switch (pop(&(e->s))) {
        case '+':
            push(&(e->s), pop(&(e->s)) + lastval);
            break;
        case '-':
            push(&(e->s), pop(&(e->s)) - lastval);
            break;
        case '*':
            push(&(e->s), pop(&(e->s)) * lastval);
            break;
        case '/':
            push(&(e->s), pop(&(e->s)) / lastval);
            break;
        default:
            printf("\nOperador desconocido");
            exit(1);
        }
    }
    return (int)(pop(&(e->s)));
}

void generaParser(Express e, char string[LEN]){
    initializeExpress(&e, string);
    parse(&e);
    printf("El resultado es: %d\n\n", solve(&e));
}

