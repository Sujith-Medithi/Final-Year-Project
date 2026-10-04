#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_part_44;

int partial_kernel_44(int s, int b) {
    return ((s >> 3) & 31) + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int part_out;
    part_out = partial_kernel_44(secret_k, pub_bias);
    glob_part_44 = part_out;
    return 0;
}
