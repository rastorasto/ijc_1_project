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
    bitset_create(pole, 500);
    Eratosthenes(pole);

    for(bitset_index_t i = 0; i < 500; i++){
        printf("%lu : %d\n",i,bitset_getbit(pole, i) ? 1 : 0);
    }
    return 0;
}
