#include <stdio.h>
#include <stdint.h>

#include <time.h>
#include <stdlib.h>

#include "average.h"
#include "min_max.h"
#include "gcd.h"

int main()
{
    srand((unsigned int) time(NULL));
    int a = rand() % 1000, b = rand() % 500;
    printf("\tTest case\t\na: %d, b: %d\n\n", a, b);

    printf("Average: %u\n", average(a, b));             // EXP1
    printf("Average: %u\n\n", average2(a, b));          // EXP2, EXP3

    printf("Min: %u\tMin2: %u\n", min(a, b), min2(a, b));
    printf("Max: %u\n\n", max(a, b));                   // EXP4, EXP5

    // COND, RET
    printf("GCD: %lu\tGCD2: %lu\n\n", gcd64(a, b), gcd64_ctz(a, b));

    return 0;
}