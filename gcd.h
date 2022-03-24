#ifndef GCD_H
#define GCD_H

#include <stdio.h>
#include <stdint.h>

// COND, RET
uint64_t gcd64(uint64_t u, uint64_t v);

uint64_t gcd64_ctz(uint64_t u, uint64_t v);

#endif  // GCD_H