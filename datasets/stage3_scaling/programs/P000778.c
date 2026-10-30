#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_loop_77;

int loop_kernel_77(int d, int seed) {
    int acc = seed;
    for (int i = 0; i < 3; i++) {
        acc += ((d >> i) & 1) + 77;
    }
    return acc;
}

int main()
{
    int sec_data;
    int pub_seed;
    int loop_out;
    loop_out = loop_kernel_77(sec_data, pub_seed);
    glob_loop_77 = loop_out;
    return 0;
}
