#include <stdio.h>
#include "bitset.h"

int main(int, char **)
{
    Bitset *bitset = bitset_create_filled(200, ~0);

    

    bitset_destroy(bitset);
    return 0;
}