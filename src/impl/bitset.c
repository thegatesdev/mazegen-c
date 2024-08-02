#include <stdlib.h>
#include "bitset.h"

// It is generally accepted that a byte occupies 8 bits.
#define BITS_BYTE 8
#define WORD_BITS (BITS_BYTE * sizeof(Bitset))

/**
 * Gets the word in Bitset* <B> where the bit index <i> resides.
 */
#define WORD_INDEX(B, i) (*(B + (i / WORD_BITS)))
/**
 * Creates a mask for a singe bit at index <i> in a bitset word.
 */
#define MASK(i) (1 << (i % WORD_BITS))

/**
 * Calculates the amount of words necessary to fit <count> bits.
 */
static inline size_t bitset_fit(bitset_index count)
{
    return count / WORD_BITS + (count % WORD_BITS != 0);
}

Bitset *bitset_create_empty(bitset_index size)
{
    Bitset *bitset = calloc(bitset_fit(size), sizeof *bitset);
    return bitset;
}

Bitset *bitset_create_filled(bitset_index size, Bitset value)
{
    size_t words = bitset_fit(size);
    Bitset *bitset = malloc(words * sizeof *bitset);
    for (size_t i = 0; i < words; i++)
    {
        *(bitset + i) = value;
    }
    return bitset;
}

inline void bitset_destroy(Bitset *bitset)
{
    free(bitset);
}

inline Bitset bitset_test(Bitset *bitset, bitset_index index)
{
    /*
    Example: bitset of lenght 3 with 4 bit words:
    0000 0100 0010
    - get word at index 5:
    0100
    - create mask with index 5:
    0100
    - compare:
    0100 & 0100 = 0100
    BIT IS SET

    - get word at index 9
    0010
    - create mask with index 9
    0100
    - compare:
    0010 & 0100 = 0000
    BIT IS CLEAR
    */
    return WORD_INDEX(bitset, index) & MASK(index);
}

inline void bitset_set(Bitset *bitset, bitset_index index)
{
    /*
    Same thing as bitset_test but set the bit.

    Word: 0110
    Mask: 0001

    0110 | 0001 = 0111
    BIT IS SET
    */
    WORD_INDEX(bitset, index) |= MASK(index);
}

inline void bitset_clear(Bitset *bitset, bitset_index index)
{
    /*
    Same thing as bitset_test but clear the bit.

    Word: 0111
    Mask: 0100
    Mask flipped = 1011

    0111 & 1011 = 0011
    BIT IS CLEARED
    */
    WORD_INDEX(bitset, index) &= ~MASK(index);
}
