#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_loop_38;

int loop_kernel_38(int d, int seed) {
    int acc = seed;
    for (int i = 0; i < 4; i++) {
        acc += ((d >> i) & 1) + 38;
    }
    return acc;
}

int main()
{
    int sec_data;
    int pub_seed;
    int loop_out;
    loop_out = loop_kernel_38(sec_data, pub_seed);
    glob_loop_38 = loop_out;
    return 0;
}
