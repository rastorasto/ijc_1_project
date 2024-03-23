// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// Program ktory vypise posledny 10 prvocisel z rozsahu

#include "bitset.h"
#include <stdio.h>
#include "eratosthenes.h"
#include "error.h"
#include <time.h>

int main(void) {
    clock_t start = clock();

    bitset_create(pole, 666000000);
    Eratosthenes(pole);

    int count=0;
    unsigned long sorted[10] = {0};
    
    for (bitset_index_t i = 666000000-1; i > 1 && count < 10; --i) {
        if (bitset_getbit(pole, i)) {
            sorted[count++]=i;
        }
    }

    for(bitset_index_t i = 0; i < 10; i++){
        printf("%lu\n",sorted[(10-i)-1]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    return 0;
}
