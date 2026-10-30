#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_part_66;

int partial_kernel_66(int s, int b) {
    return ((s >> 1) & 3) + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int part_out;
    part_out = partial_kernel_66(secret_k, pub_bias);
    glob_part_66 = part_out;
    return 0;
}
