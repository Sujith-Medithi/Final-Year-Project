#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_34;

int affine_kernel_34(int s, int sc) {
    return (((s * 71 + 239) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_34(sec_val, pub_scale);
    glob_arith_34 = arith_out;
    return 0;
}
