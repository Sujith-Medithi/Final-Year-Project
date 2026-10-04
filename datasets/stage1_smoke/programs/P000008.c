#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_loop_8 = 0;

int loop_kernel_8(int data, int seed) {
    int acc = seed;
    for (int i = 0; i < 4; i++) {
        acc += (data >> i) & 1;
    }
    return acc;
}

int main()
{
    int sec_data;
    int pub_seed;
    int sum;
    sum = loop_kernel_8(sec_data, pub_seed);
    glob_loop_8 = sum;
    return 0;
}
