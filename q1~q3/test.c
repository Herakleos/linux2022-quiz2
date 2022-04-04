#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#include "test.h"
#include "average.h"
#include "min_max.h"
#include "gcd.h"

int main(void)
{
    srand((unsigned int) time(NULL));
    int a = rand() % 1000, b = rand() % 1000;
    printf("\tTest case\t\na: %d, b: %d\n\n", a, b);

    // EXP1, EXP2, EXP3
    if (average(a, b) == average2(a, b))
        printf("Average: %u\n", average(a, b));
    else
        puts("AVG Failed!");

    if (min(a, b) == min2(a, b))
        printf("Min: %u\t", min(a, b));
    else
        puts("MIN Failed!");
    // EXP4, EXP5
    printf("Max: %u\n", max(a, b));

    // COND, RET
    printf("GCD: %lu\t", gcd64_ctz(a, b));
    if (gcd64(a, b) == gcd64_ctz(a, b))
        puts("->\tPassed!");
    else
        puts("->\tFailed!");

    return 0;
}