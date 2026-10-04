#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_96;

int affine_kernel_96(int s, int sc) {
    return (((s * 195 + 673) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_96(sec_val, pub_scale);
    glob_arith_96 = arith_out;
    return 0;
}
