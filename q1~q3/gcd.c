#include <stdio.h>
#include <stdint.h>

uint64_t gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v)
        return u | v;

    /**
     *
     * left shift counter
     * if x and y are both even
     * gcd(x, y) = 2 * gcd(x/2, y/2)
     *
     */
    int shift;
    for (shift = 0; !((u | v) & 1); shift++) {
        u /= 2, v /= 2;
    }
    /**
     *
     * Remove non common divisor
     * if x is even and y is odd
     * gcd(x, y) = gcd(x/2, y)
     *
     */
    while (!(u & 1))
        u /= 2;
    
    do {
        // Remove non common divisor
        while (!(v & 1))
            v /= 2;
        // Euclidean algorithm
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);

    // do left shift
    return u << shift;
}

uint64_t gcd64_ctz(uint64_t u, uint64_t v)
{
    if (!u || !v)
        return u | v;

    // find the min. zero number from tail
    int a = __builtin_ctz(u), b = __builtin_ctz(v);
    int shift = b ^ ((a ^ b) & -(a < b));
    u >>= shift, v >>= shift;

    // Remove non common divisor
    u >>= __builtin_ctz(u);
    do {
        // Remove non common divisor
        v >>= __builtin_ctz(v);
        // branchless Euclidean algorithm
        // v = abs(u - v)
        uint64_t mask = -(u < v);
        uint64_t t = ((u - v) ^ mask) - mask;
        // u = min(u, v)
        u = (v ^ ((u ^ v) & mask));
        v = t;
    } while (v);
    
    // do left shift
    return u << shift;
}