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
    bitset_create(pole, 1000);
    Eratosthenes(pole);

    int count=0;
    for (bitset_index_t i = 1000-1; i > 1 && count < 1000; --i) {
        if (bitset_getbit(pole, i)) {
            printf("%lu\n", i);
            ++count;
        }
    }
    // for(bitset_index_t i = 0; i < 10; i++){
    //         printf("%lu : %u\n",i, bitset_getbit(pole, i) ? 1 : 0);
    // }
    return 0;
}
