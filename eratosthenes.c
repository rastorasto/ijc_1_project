// eratosthenes.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "error.h"
#include "bitset.h"
#include "eratosthenes.h"
#include <math.h>

void Eratosthenes(bitset_t pole) {
    bitset_fill(pole, 1);
    bitset_setbit(pole, 0, 0);
    bitset_setbit(pole, 1, 0);
    bitset_index_t index = 2;
    bitset_index_t N = bitset_size(pole);

    for (; index * index <= N; index++) {
        if (bitset_getbit(pole, index)) {
            bitset_index_t j;
            for (j = index * index; j < N; j += index) {
                bitset_setbit(pole, j, 0);
            }
        }
    }
}
