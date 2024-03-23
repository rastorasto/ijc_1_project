// bitset.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// Inline funkcie pre pracu s bitovym polom

#include "bitset.h"
#include "error.h"
#include <assert.h>

#ifdef USE_INLINE
extern inline void bitset_free(bitset_t jmeno_pole);
extern inline bitset_index_t bitset_size(bitset_t jmeno_pole);
extern inline void bitset_fill(bitset_t jmeno_pole, int bool_vyraz);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);
extern inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
#endif
