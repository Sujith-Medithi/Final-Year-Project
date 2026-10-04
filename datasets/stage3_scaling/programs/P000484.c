#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_83;

int affine_kernel_83(int s, int sc) {
    return (((s * 169 + 582) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_83(sec_val, pub_scale);
    glob_arith_83 = arith_out;
    return 0;
}
