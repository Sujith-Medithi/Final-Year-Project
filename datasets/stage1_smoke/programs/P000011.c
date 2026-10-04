#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_multi_11 = 0;

int multi_kernel_11(int k1, int k2, int nonce) {
    int comb = (k1 & 15) ^ (k2 & 15);
    return comb + nonce;
}

int main()
{
    int sec_key1;
    int sec_key2;
    int pub_nonce;
    int combo_out;
    combo_out = multi_kernel_11(sec_key1, sec_key2, pub_nonce);
    glob_multi_11 = combo_out;
    return 0;
}
