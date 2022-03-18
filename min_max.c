#include <stdio.h>
#include <stdint.h>

/**
 * 
 * if diff >= 0:
 *      a + (diff & 0x00000000)
 *      a + 0 => a
 * else:
 *      a + (diff & 0xFFFFFFFF)
 *      a + diff => b
 *
 */
int32_t min(int32_t a, int32_t b)
{
    int32_t diff = b - a;
    return a + (diff & (diff >> 31));
}

/**
 *
 * if a < b:
 *      b ^ ((a ^ b) & 0xFFFFFFFF)
 *      b ^ (a ^ b) => a
 * else:
 *      b ^ ((a ^ b) & 0x00000000)
 *      b ^ 0x00000000 => b
 *
 */
uint32_t min2(uint32_t a, uint32_t b)
{
    return b ^ ((a ^ b) & -(a < b));
}

/**
 *
 * if a < b:
 *      a ^ ((a ^ b) & 0xFFFFFFFF)
 *      a ^ (a ^ b) => b
 * else:
 *      a ^ ((a ^ b) & 0x00000000)
 *      a ^ 0x00000000 => a
 *
 */
uint32_t max(uint32_t a, uint32_t b)
{
    return a ^ ((a ^ b) & -(a < b));
}