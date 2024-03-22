// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"
#include <stdio.h>
#include "eratosthenes.h"
#include "error.h"

int main(main) {
    bitset_t pole;
    bitset_create(pole, 66000000UL);
    Eratosthenes(pole);
    unsigned long count = 0;
    for (bitset_index_t i = 0; i < sizeof(pole); i++) {
        printf("%lu\n", pole[i]);
    }
    return 0;
}
