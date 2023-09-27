#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Longitud de las expresiones en caracteres
#define LEN 80

// Tama�o de la pila
#define MAX 40

// Definici�n de la estructura Stack
typedef struct {
    char st[MAX];
    int top;
} Stack;

// Funci�n para inicializar la pila
void initialize(Stack *s) {
    s->top = 0;
}

// Funci�n para insertar un car�cter en la pila
void push(Stack *s, char var) {
    s->st[++(s->top)] = var;
}

// Funci�n para obtener un car�cter de la pila
char pop(Stack *s) {
    return s->st[(s->top)--];
}

// Funci�n para obtener el valor en la parte superior de la pila
int gettop(Stack *s) {
    return s->top;
}

// Definici�n de la estructura Express
typedef struct {
    Stack s;
    char *pStr;
    int len;
} Express;

// Funci�n para inicializar una expresi�n
void initializeExpress(Express *e, char *ptr) {
    e->pStr = ptr;
    e->len = strlen(e->pStr);
    initialize(&(e->s));
}

// Funci�n para analizar la expresi�n
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
            printf("\nCar�cter de entrada desconocido");
            exit(1);
        }
    }
}

// Funci�n para resolver la expresi�n
int solve(Express *e) {
    char lastval;
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

// Funci�n principal
int main() {
    char string[LEN] = "2+3*4/3-2";

    Express e;
    initializeExpress(&e, string);

    parse(&e);

    printf("%d\n", solve(&e));

    return 0;
}
