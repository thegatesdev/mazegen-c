#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>

/**
 * A word in a set of bits.
 */
typedef unsigned int Bitset;
/**
 * An index into a set of bits.
 */
typedef uint_fast32_t bitset_index;

/**
 * Allocates a new bitset that fits at least <size> bits.
 * All the bits are initially cleared.
 *
 * @return a pointer to the first word in the bitset
 */
Bitset *bitset_create_empty(bitset_index size);

/**
 * Allocates a new bitset that fits at least <size> bits.
 * Each word in the bitset is assigned the value <word>.
 *
 * @return a pointer to the first word in the bitset
 */
Bitset *bitset_create_filled(bitset_index size, Bitset word);

/**
 * Free the memory used by the given <bitset>.
 */
void bitset_destroy(Bitset *bitset);

/**
 * Test the value in <bitset> at the given index.
 *
 * @return a value above zero if the bit at <index> was set
 */
Bitset bitset_test(Bitset *bitset, bitset_index index);

/**
 * Set the value in <bitset> at the given index.
 */
void bitset_set(Bitset *bitset, bitset_index index);

/**
 * Clear the value in <bitset> at the given index.
 */
void bitset_clear(Bitset *bitset, bitset_index index);

#endif // BITSET_H