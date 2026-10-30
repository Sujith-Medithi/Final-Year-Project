#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_5;

int affine_kernel_5(int s, int sc) {
    return (((s * 13 + 36) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_5(sec_val, pub_scale);
    glob_arith_5 = arith_out;
    return 0;
}
