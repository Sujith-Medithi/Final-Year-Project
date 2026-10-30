#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_89;

int affine_kernel_89(int s, int sc) {
    return (((s * 181 + 624) % 256) * sc);
}

int main()
{
    int sec_val;
    int pub_scale;
    int arith_out;
    arith_out = affine_kernel_89(sec_val, pub_scale);
    glob_arith_89 = arith_out;
    return 0;
}
