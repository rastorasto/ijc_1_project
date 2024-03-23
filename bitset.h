// bitset.h
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#ifndef BITSET_H
#define BITSET_H


#include "error.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define BITS_IN_ULONG (8 * sizeof(unsigned long))
typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;


#ifndef USE_INLINE

#define bitset_create(jmeno_pole, velikost) \
    static_assert(velikost > 0 , "bitset_create: Chybná velikosť. \n" ); \
    unsigned long jmeno_pole[(velikost / BITS_IN_ULONG) + ((velikost % BITS_IN_ULONG) ? 2 : 1)] = {0}; \
    jmeno_pole[0] = velikost;

#define bitset_alloc(jmeno_pole, velikost) \
    static_assert(velikost > 0 , "bitset_create: Chybná velikosť. \n" ); \
    unsigned long jmeno_pole = calloc((velikost / BITS_IN_ULONG) + ((velikost % BITS_IN_ULONG) ? 2 : 1), sizeof(bitset_index_t)); \
    if (jmeno_pole == NULL) { \
        error_exit("bitset_alloc: Chyba alokace paměti.\n"); \
    } \
    jmeno_pole[0] = velikost;

#define bitset_free(jmeno_pole) free(jmeno_pole)

#define bitset_size(jmeno_pole) (jmeno_pole[0])

#define bitset_fill(jmeno_pole, bool_vyraz) \
    for (bitset_index_t i = 1; i < (jmeno_pole[0] / BITS_IN_ULONG) + ((jmeno_pole[0] % BITS_IN_ULONG) ? 2 : 1); i++) { \
        jmeno_pole[i] = bool_vyraz ? ~0UL : 0UL; \
    }

#define bitset_setbit(jmeno_pole,index,vyraz) ((index) > jmeno_pole[0]) ?\
    error_exit("index %lu mimo rozsah 0..%lu", index, (jmeno_pole[0])), 0 :\
    ((vyraz) ?\
    (jmeno_pole[(index / BITS_IN_ULONG) + 1] |= (1UL << (index % BITS_IN_ULONG))) :\
    (jmeno_pole[(index / BITS_IN_ULONG) + 1] &= ~(1UL << (index % BITS_IN_ULONG))))

#define bitset_getbit(jmeno_pole, index) ((index > jmeno_pole[0] || index < 0) ? \
    error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)(index), (unsigned long)bitset_size(jmeno_pole) - 1), 0 : \
    ((jmeno_pole[(index / BITS_IN_ULONG) + 1] >> (index % BITS_IN_ULONG)) & 1))

#else
inline void bitset_create(bitset_t jmeno_pole[], unsigned long velikost) {
    static_assert(velikost > 0 , "bitset_create: Chybná velikosť. \n" ); \
    jmeno_pole[(velikost / (sizeof(bitset_index_t) * 8)) + ((velikost % (sizeof(bitset_index_t) * 8)) ? 2 : 1)] = 0;
    jmeno_pole[0] = velikost;
}

inline bitset_t bitset_alloc(unsigned long velikost) {
    static_assert(velikost > 0 , "bitset_create: Chybná velikosť. \n" ); \
    bitset_t jmeno_pole = calloc((velikost / (sizeof(bitset_index_t) * 8)) + ((velikost % (sizeof(bitset_index_t) * 8)) ? 2 : 1), sizeof(bitset_index_t));
    if (jmeno_pole == NULL) {
        error_exit("bitset_alloc: Chyba alokace paměti.\n");
    }
    jmeno_pole[0] = velikost;
    return jmeno_pole;
}

inline void bitset_free(bitset_t jmeno_pole) {
    free(jmeno_pole);
}

inline unsigned long bitset_size(bitset_t jmeno_pole) {
    return jmeno_pole[0];
}

inline void bitset_fill(bitset_t jmeno_pole, bool bool_vyraz) {
    for (bitset_index_t i = 1; i <= bitset_size(jmeno_pole); i++) {
        jmeno_pole[i] = bool_vyraz ? ~0UL : 0UL;
    }
}

inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, int vyraz) {
    if (index > bitset_size(jmeno_pole) || index < 0) {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
    }
    if (vyraz) {
        jmeno_pole[1 + index / bitset_size(jmeno_pole)] |= 1UL << (index % bitset_size(jmeno_pole));
    } else {
        jmeno_pole[1 + index / bitset_size(jmeno_pole)] &= ~(1UL << (index % bitset_size(jmeno_pole)));
    }
}

inline int bitset_getbit(bitset_t jmeno_pole, unsigned long index) {
    if (index > bitset_size(jmeno_pole) || index < 0) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
    }
    if (jmeno_pole[(1 + index) / bitset_size(jmeno_pole)] & (1UL << ((1 + index) % bitset_size(jmeno_pole)))) {
        return 1;
    } else {
        return 0;
    }
}
#endif 
#endif 
