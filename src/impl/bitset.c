#include "bitset.h"

#define BITS_BYTE 8
#define WORD_BITS (BITS_BYTE * sizeof(Bitset))
#define WORD_INDEX(B, i) (*(B + (i / WORD_BITS)))
#define MASK(i) (1 << (i % WORD_BITS))

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
    return WORD_INDEX(bitset, index) & MASK(index);
}

inline void bitset_set(Bitset *bitset, bitset_index index)
{
    WORD_INDEX(bitset, index) |= MASK(index);
}

inline void bitset_clear(Bitset *bitset, bitset_index index)
{
    WORD_INDEX(bitset, index) &= ~MASK(index);
}
