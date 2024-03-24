// bitset.h
// Řešení IJC-DU1, příklad a), 21.3.2024
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.5.0
// Makra a inline funkcie pre pracu s bitovym polom 

#ifndef BITSET_H
#define BITSET_H


#include "error.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Number of bits in unsigned long
#define BITS_IN_ULONG (8 * sizeof(unsigned long))

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;


// Creates a bitset of size velikost
#define bitset_create(jmeno_pole, velikost) \
    static_assert(velikost > 0 , "bitset_create: Chybná velikost.\n" ); \
    unsigned long jmeno_pole[(velikost / BITS_IN_ULONG) + ((velikost % BITS_IN_ULONG) ? 2 : 1)] = {0}; \
    jmeno_pole[0] = velikost;

// Allocates memory for a bitset of size velikost
#define bitset_alloc(jmeno_pole, velikost) \
    static_assert(velikost > 0 , "bitset_alloc: Chybná velikost.\n" ); \
    unsigned long jmeno_pole = calloc((velikost / BITS_IN_ULONG) + ((velikost % BITS_IN_ULONG) ? 2 : 1), sizeof(bitset_index_t)); \
    if (jmeno_pole == NULL) { \
        error_exit("bitset_alloc: Chyba alokace paměti"); \
    } \
    jmeno_pole[0] = velikost;

#ifndef USE_INLINE

// Frees the memory allocated for the bitset
#define bitset_free(jmeno_pole) free(jmeno_pole)

// Returns the number of bits in bitset
#define bitset_size(jmeno_pole) (jmeno_pole[0])

// Fills the bitset with ones or zeros
#define bitset_fill(jmeno_pole, bool_vyraz) \
    for (bitset_index_t i = 1; i < (jmeno_pole[0] / BITS_IN_ULONG) + ((jmeno_pole[0] % BITS_IN_ULONG) ? 2 : 1); i++) { \
        jmeno_pole[i] = bool_vyraz ? ~0UL : 0UL; \
    }

// Sets the bit at index to either 1 or 0
#define bitset_setbit(jmeno_pole,index,vyraz) (index >= jmeno_pole[0]) ?\
    error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", index, (jmeno_pole[0])), 2 :\
    ((vyraz) ?\
    (jmeno_pole[(index / BITS_IN_ULONG) + 1] |= (1UL << (index % BITS_IN_ULONG))) :\
    (jmeno_pole[(index / BITS_IN_ULONG) + 1] &= ~(1UL << (index % BITS_IN_ULONG))))

// Returns the value of the bit at index
#define bitset_getbit(jmeno_pole, index) ((index > jmeno_pole[0]) ? \
    error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)(index), (unsigned long)bitset_size(jmeno_pole) - 1), 0 : \
    ((jmeno_pole[(index / BITS_IN_ULONG) + 1] >> (index % BITS_IN_ULONG)) & 1))

#else

// Frees the memory allocated for the bitset
inline void bitset_free(bitset_t jmeno_pole) {
    free(jmeno_pole);
}

// Returns the number of bits in bitset
inline unsigned long bitset_size(bitset_t jmeno_pole) {
    return jmeno_pole[0];
}

// Fills the bitset with ones or zeros
inline void bitset_fill(bitset_t jmeno_pole, bool bool_vyraz) {
    for (bitset_index_t i = 1; i <= bitset_size(jmeno_pole); i++) {
        jmeno_pole[i] = bool_vyraz ? ~0UL : 0UL;
    }
}

// Sets the bit at index to either 1 or 0
inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, int vyraz) {
    if (index > bitset_size(jmeno_pole) || index < 0) {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
    }
    if (vyraz) {
        jmeno_pole[1 + index / bitset_size(jmeno_pole)] |= 1UL << (index % bitset_size(jmeno_pole));
    } else {
        jmeno_pole[1 + index / bitset_size(jmeno_pole)] &= ~(1UL << (index % bitset_size(jmeno_pole)));
    }
}

// Returns the value of the bit at index
inline int bitset_getbit(bitset_t jmeno_pole, unsigned long index) {
    if (index > bitset_size(jmeno_pole) || index < 0) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1);
    }
    if (jmeno_pole[(1 + index) / bitset_size(jmeno_pole)] & (1UL << ((1 + index) % bitset_size(jmeno_pole)))) {
        return 1;
    } else {
        return 0;
    }
}
#endif 
#endif 
