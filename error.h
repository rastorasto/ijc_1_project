// error.h
// Řešení IJC-DU1, příklad a), 21.3.2024
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.5.0
// Hlavickovy subor pre error.c

#ifndef ERROR_H
#define ERROR_H

void warning(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif
