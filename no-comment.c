// no-comment.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// Program that removes comments from file or stdin

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

int main(int argc, char *argv[]){
    int stav = 0;
    int c;
    FILE *file;

    // Open specified file from arguments or use stdin
    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            error_exit("Error opening file\n");
        }
    } else {
        file = stdin;
    }
    // Read every character from file or stdin
     while ((c = fgetc(file)) != EOF) {
        switch(stav) {
            case 0: // Normal state
                if (c == '/')  stav = 1;
                else if (c == '"') { stav = 4; putchar(c); }
                else if (c == '\'') { stav = 7; putchar(c); }
                else putchar(c);
                break;
            case 1: // Possible comment
                if (c == '*')  stav = 2;
                else if (c == '/') stav = 6;
                else { stav = 0; putchar('/'); putchar(c); }
                break;
            case 2: // Comment
                if (c == '*') stav = 3;
                break;
            case 3: // End of comment
                if (c == '/') { stav = 0; putchar(' '); }
                break;
            case 4: // Double quotes string
                if (c == '\\') stav = 5;
                else if (c == '"') stav = 0;
                putchar(c);
                break;
            case 5: // Escape character in double quotes string
                stav = 4;
                putchar(c);
                break;
            case 6: // Single line comment
                if (c == '\n') { stav = 0; putchar(c); }
                putchar(' ');
                break;
            case 7: // Single quotes string
                if (c == '\\') stav = 8;
                else if (c == '\'') stav = 0;
                putchar(c);
                break;
            case 8: // Escape character single quotes string
                stav = 7;
                putchar(c);
                break;
        }
    }
    // Close file
    fclose(file);
    if(stav!=0) error_exit("Error: Comment not closed\n");
    return 0;
}
