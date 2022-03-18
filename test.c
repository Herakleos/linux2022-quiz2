#include <stdio.h>
#include <stdint.h>

#include <time.h>
#include <stdlib.h>

#include "average.h"
#include "min_max.h"

int main()
{
    srand((unsigned int) time(NULL));
    int a = rand() % 1000, b = rand() % 500;
    printf("--- Test case ---\na: %d, b: %d\n\n", a, b);

    puts("--- EXP 1 ~ 3 ---");
    printf("Average: %u\n", average(a, b));     // EXP1
    printf("Average: %u\n\n", average2(a, b));  // EXP2, EXP3

    puts("--- EXP 4 ~ 5 ---");
    printf("Min: %u\n", min(a, b));
    printf("Min2: %u\n", min2(a, b));
    printf("Max: %u\n\n", max(a, b));           // EXP4, EXP5

    return 0;
}