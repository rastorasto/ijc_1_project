// eratosthenes.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"
#include <math.h>

void Eratosthenes(bitset_t *array) {
    bitset_index_t size = 666000000;
    bitset_alloc(array, size);
    bitset_fill(array, 1);

    for (bitset_index_t i = 2; i * i < size; i++) {
        if (bitset_getbit(array, i) == 1) {
            for (bitset_index_t j = i * i; j < size; j += i) {
                bitset_setbit(array, j, 0);
            }
        }
    }

    int count = 0;
    for (bitset_index_t i = size - 1; i >= 2; i--) {
        if (bitset_getbit(array, i) == 1) {
            printf("%lu\n", i);
            count++;
            if (count == 10) {
                break;
            }
        }
    }
}