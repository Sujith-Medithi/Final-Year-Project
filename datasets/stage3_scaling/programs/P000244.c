#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_part_43;

int partial_kernel_43(int s, int b) {
    return ((s >> 2) & 15) + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int part_out;
    part_out = partial_kernel_43(secret_k, pub_bias);
    glob_part_43 = part_out;
    return 0;
}
