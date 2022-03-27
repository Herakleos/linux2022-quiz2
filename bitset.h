#ifndef BITSET_H
#define BITSET_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

size_t naive(uint64_t *bitmap, size_t bitmapsize, uint32_t *out);

// EXP6
size_t improved(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)

#endif  // BITSET_H