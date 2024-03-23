// eratosthenes.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "error.h"
#include "bitset.h"
#include <math.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t pole) {
    bitset_fill(pole, 1);
    bitset_setbit(pole, 0, 0);
    bitset_setbit(pole, 1, 0);
    bitset_index_t N = bitset_size(pole);
for(bitset_index_t i = 2; i < sqrt(N); i++)
    {
        if(!bitset_getbit(pole, i))
        {
            for(bitset_index_t j = 2 * i; j < N; j += i)
            {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}
