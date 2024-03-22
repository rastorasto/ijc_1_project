// bitset.h
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#ifndef BITSET_H
#define BITSET_H

#include "error.h"
#include <stdlib.h>

typedef unsigned long bitset_t;
typedef unsigned long bitset_index_t;

#ifndef USE_INLINE

#define bitset_create(jmeno_pole, velikost) \
    static_assert(velikost <= 0, "Size must be greater than 0."); \
    bitset_t jmeno_pole[(velikost / (sizeof(bitset_index_t) * 8)) + ((velikost % (sizeof(bitset_index_t) * 8)) ? 1 : 0)] = {0}

#define bitset_alloc(jmeno_pole, velikost) \
    static_assert(velikost <= 0, "Size must be greater than 0."); \
    bitset_t *jmeno_pole = calloc((velikost / (sizeof(bitset_index_t) * 8)) + ((velikost % (sizeof(bitset_index_t) * 8)) ? 1 : 0), sizeof(bitset_index_t)); \
    if (jmeno_pole == NULL) { \
        error_exit("bitset_alloc: Chyba alokace paměti.\n"); \
    }

#define bitset_free(jmeno_pole) free(jmeno_pole)

#define bitset_size(jmeno_pole) (jmeno_pole[0])

#define bitset_fill(jmeno_pole, bool_vyraz) \
    for (bitset_index_t i = 0; i < bitset_size(jmeno_pole); i++) { \
        jmeno_pole[i] = bool_vyraz; \
    }

#define bitset_setbit(jmeno_pole, index, vyraz) \
    if (index >= bitset_size(jmeno_pole) || index < 0) { \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1); \
    } \
    if (vyraz) { \
        jmeno_pole[index / bitset_size(jmeno_pole)] |= 1UL << (index % bitset_size(jmeno_pole)); \
    } else { \
        jmeno_pole[index / bitset_size(jmeno_pole)] &= ~(1UL << (index % bitset_size(jmeno_pole))); \
    }

#define bitset_getbit(jmeno_pole, index) \
    if (index >= bitset_size(jmeno_pole) || index < 0) { \
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole) - 1) : \
    } else if (jmeno_pole[index / bitset_size(jmeno_pole)] & (1UL << (index % bitset_size(jmeno_pole)))) {\
        return 1; \
    } else { \
        return 0; \
    }
#else
inline void bitset_create(unsigned long *jmeno_pole, unsigned long velikost);
inline void bitset_alloc(unsigned long *jmeno_pole, unsigned long velikost);
inline void bitset_free(unsigned long *jmeno_pole);
inline unsigned long bitset_size(unsigned long *jmeno_pole);
inline void bitset_fill(unsigned long *jmeno_pole, int bool_vyraz);
inline void bitset_setbit(unsigned long *jmeno_pole, unsigned long index, int vyraz);
inline int bitset_getbit(unsigned long *jmeno_pole, unsigned long index);


#endif 
#endif 