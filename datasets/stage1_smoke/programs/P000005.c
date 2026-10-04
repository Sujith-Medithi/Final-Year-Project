#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_arith_5 = 0;

int affine_kernel_5(int s, int scale) {
    int temp = (s * 3 + 7) % 256;
    return temp * scale;
}

int main()
{
    int sec_val;
    int pub_scale;
    int val;
    val = affine_kernel_5(sec_val, pub_scale);
    glob_arith_5 = val;
    return 0;
}
