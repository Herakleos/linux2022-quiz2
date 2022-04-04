#include <stdio.h>
#include <stdint.h>


/**
 *
 * (num & 1) is true: num is odd
 * ((a & 1) & (b & 1)) is true or not
 *
 */
uint32_t average(uint32_t a, uint32_t b)
{
    return (a >> 1) + (b >> 1) + (a & b & 1);
}

/**
 *
 * x + y = (x ^ y) + ((x & y) << 1)
 * (x + y) / 2 = (x + y) >> 1
 *             = ((x ^ y) + ((x & y) << 1)) >> 1
 *             = (x & y) + ((x ^ y) >> 1)
 *
 */
uint32_t average2(uint32_t a, uint32_t b)
{
    return (a & b) + ((a ^ b) >> 1);
}