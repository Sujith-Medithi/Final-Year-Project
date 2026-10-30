#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_part_64;

int partial_kernel_64(int s, int b) {
    return ((s >> 2) & 31) + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int part_out;
    part_out = partial_kernel_64(secret_k, pub_bias);
    glob_part_64 = part_out;
    return 0;
}
