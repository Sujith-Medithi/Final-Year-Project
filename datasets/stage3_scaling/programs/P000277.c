#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_part_76;

int partial_kernel_76(int s, int b) {
    return ((s >> 2) & 3) + b;
}

int main()
{
    int secret_k;
    int pub_bias;
    int part_out;
    part_out = partial_kernel_76(secret_k, pub_bias);
    glob_part_76 = part_out;
    return 0;
}
