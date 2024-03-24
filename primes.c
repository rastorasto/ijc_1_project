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
    // Start the clock
    clock_t start = clock();

    // Creates a bitset of size 666000000bits
    bitset_create(pole, 666000000);

    // Calls the function eratosthenes to find all the prime numbers in the bitset size
    Eratosthenes(pole);

    int count=0;
    unsigned long sorted[10] = {0};

    // Finds the last 10 prime numbers in the bitset    
    for (bitset_index_t i = 666000000-1; i > 1 && count < 10; --i) {
        if (bitset_getbit(pole, i)) {
            sorted[count++]=i;
        }
    }
    // Prints the last 10 prime numbers in ascending order
    for(bitset_index_t i = 0; i < 10; i++){
        printf("%lu\n",sorted[(10-i)-1]);
    }
    // Prints the time it took to find the prime numbers
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    return 0;
}
