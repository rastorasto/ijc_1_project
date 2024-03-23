// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"
#include <stdio.h>
#include "eratosthenes.h"
#include "error.h"

int main(void) {
    bitset_alloc(pole, 10000);
    Eratosthenes(pole);

    int count=0;
    for (bitset_index_t i = 10000 - 1; i > 1 && count < 10; --i) {
        if (bitset_getbit(pole, i)) {
            printf("%lu\n", i);
            ++count;
        }
    }
    bitset_free(pole);
    return 0;
}
