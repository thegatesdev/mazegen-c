#include "bitset.h"

bitset_t *bitset_create(bitset_size_t size){
    bitset_t *bitset = calloc(FitBits(size), sizeof *bitset);
    return bitset;
}

bitset_t *bitset_create_filled(bitset_size_t size, bitset_t value)
{
    bitset_t *bitset = malloc(FitBits(size) * sizeof *bitset);
    for (bitset_size_t i = 0; i < size; i++)
    {
        *(bitset + i) = value;
    }
    return bitset;
}
