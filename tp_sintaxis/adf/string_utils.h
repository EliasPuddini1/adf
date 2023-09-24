int str_to_int(const char *str) {
    int result = 0;
    int signo = 1;

    if (*str == '-') {
        signo = -1;
        str++;
    }

    while (*str != '\0') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return signo * result;
}

int isOperator(char *c){
return 0;}
