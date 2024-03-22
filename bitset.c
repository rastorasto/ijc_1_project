// bitset.c
// Řešení IJC-DU1, příklad a), 20.3.2111
// Autor: Rastislav Uhliar, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"

inline void bitset_create(unsigned long *jmeno_pole, unsigned long velikost){
    if(velikost == 0){
        error_exit("bitset_create: Velikost musí být větší než 0.\n");
    }
    memset(jmeno_pole, 0, (velikost / sizeof(jmeno_pole)) + ((velikost % sizeof(jmeno_pole)) ? 1 : 0));
}

inline void bitset_alloc(unsigned long *jmeno_pole, unsigned long velikost){
    if(velikost == 0){
        error_exit("bitset_alloc: Velikost musí být větší než 0.\n");
    }
    jmeno_pole = (unsigned long*)calloc((velikost / sizeof(jmeno_pole)) + ((velikost % sizeof(jmeno_pole)) ? 1 : 0), sizeof(bitset_index_t));
    if(jmeno_pole == NULL){
        error_exit("bitset_alloc: Chyba alokace paměti.\n");
    }
}

inline void bitset_free(unsigned long *jmeno_pole){
    free(jmeno_pole);
}

inline unsigned long bitset_size(unsigned long *jmeno_pole){
    return jmeno_pole[0];
}

inline void bitset_fill(unsigned long *jmeno_pole, bool bool_vyraz){
    for(unsigned long i = 0; i < bitset_size(jmeno_pole); i++){
        jmeno_pole[i] = bool_vyraz;
    }
}