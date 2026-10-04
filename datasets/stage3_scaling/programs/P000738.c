#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_loop_37;

int loop_kernel_37(int d, int seed) {
    int acc = seed;
    for (int i = 0; i < 3; i++) {
        acc += ((d >> i) & 1) + 37;
    }
    return acc;
}

int main()
{
    int sec_data;
    int pub_seed;
    int loop_out;
    loop_out = loop_kernel_37(sec_data, pub_seed);
    glob_loop_37 = loop_out;
    return 0;
}
