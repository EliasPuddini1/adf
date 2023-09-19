#include <stdlib.h>

int str_to_int(char* cadena)
{
    return (int)strtol(cadena,NULL, 10);
}
