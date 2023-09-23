#include <stdlib.h>

/*int str_to_int(char* cadena)
{
    return (int)strtol(cadena,NULL, 10);
}*/

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
