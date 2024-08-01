#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>
#include <stdlib.h>

typedef uint32_t bitset_t;
typedef uint32_t bitset_size_t;

#define SetBit(A,k)         ( A[(k)/32] |= (1 << ((k)%32)) )
#define ClearBit(A,k)       ( A[(k)/32] &= ~(1 << ((k)%32)) )
#define TestBit(A,k)        ( A[(k)/32] & (1 << ((k)%32)) )
#define FitBits(k)          ( k/32 + (k % 32 != 0) )

bitset_t *bitset_create(bitset_size_t size);

bitset_t *bitset_create_filled(bitset_size_t size, bitset_t value);

#endif // BITSET_H