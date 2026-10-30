#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_part_6;

int partial_kernel_6(int s, int b) {
    return ((s >> 1) & 3) + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int part_out;
    part_out = partial_kernel_6(secret_k, pub_bias);
    glob_part_6 = part_out;
    return 0;
}
