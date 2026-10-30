#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_28;

int affine_kernel_28(int s, int sc) {
    return (((s * 59 + 197) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_28(sec_val, pub_scale);
    glob_arith_28 = arith_out;
    return 0;
}
