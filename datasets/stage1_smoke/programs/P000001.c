#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_zero_1 = 0;

int zero_kernel_1(int s, int p) {
    int dead = s * 0;
    return p * 2 + 1;
}

int main()
{
    int high_sec;
    int pub_val;
    int out;
    out = zero_kernel_1(high_sec, pub_val);
    glob_zero_1 = out;
    return 0;
}
