// error.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// Funkcie pre vypisovanie warning a error sprav

#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Prints a warning message
void warning(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

// Prints an error message and exits the program
void error_exit(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}
