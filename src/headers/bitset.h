#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>
#include <stdlib.h>

typedef unsigned int Bitset;
typedef uint_fast32_t bitset_index;

Bitset *bitset_create_empty(bitset_index size);
Bitset *bitset_create_filled(bitset_index size, Bitset value);

void bitset_destroy(Bitset *bitset);

Bitset bitset_test(Bitset *bitset, bitset_index index);
void bitset_set(Bitset *bitset, bitset_index index);
void bitset_clear(Bitset *bitset, bitset_index index);

#endif // BITSET_H