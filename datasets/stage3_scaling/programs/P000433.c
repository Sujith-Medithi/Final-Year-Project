#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_32;

int affine_kernel_32(int s, int sc) {
    return (((s * 67 + 225) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_32(sec_val, pub_scale);
    glob_arith_32 = arith_out;
    return 0;
}
