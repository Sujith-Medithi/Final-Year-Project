#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_91;

int affine_kernel_91(int s, int sc) {
    return (((s * 185 + 638) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_91(sec_val, pub_scale);
    glob_arith_91 = arith_out;
    return 0;
}
