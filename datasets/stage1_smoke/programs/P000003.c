#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_partial_3 = 0;

int mask_kernel_3(int s, int b) {
    int masked = s & 15;
    return masked + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int partial_out;
    partial_out = mask_kernel_3(secret_k, pub_bias);
    glob_partial_3 = partial_out;
    return 0;
}
