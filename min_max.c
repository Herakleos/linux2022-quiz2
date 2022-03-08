#include <stdio.h>
#include <stdint.h>

int32_t min(int32_t a, int32_t b)
{
    int32_t diff = a - b;
    return b + (diff & (diff >> 31));
}

uint32_t max(uint32_t a, uint32_t b)
{
    // to do
    return 0;
}