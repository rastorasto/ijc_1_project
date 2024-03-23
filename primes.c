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
    const bitset_index_t size = 10000;
    bitset_create(pole, size);
    Eratosthenes(pole);

    int count=0;
    unsigned long sorted[10] = {0};
    for (bitset_index_t i = size-1; i > 1 && count < 10; --i) {
        if (bitset_getbit(pole, i)) {
            sorted[count++]=i;
            // printf("%lu\n", i);
            // ++count;
        }
    }
    for(bitset_index_t i = 0; i < 10; i++){
        printf("%lu\n",sorted[(10-i)-1]);
    }
    // for(bitset_index_t i = 0; i < 10; i++){
    //         printf("%lu : %u\n",i, bitset_getbit(pole, i) ? 1 : 0);
    // }
    return 0;
}
