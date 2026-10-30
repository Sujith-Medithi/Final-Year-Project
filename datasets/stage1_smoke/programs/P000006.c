#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_bit_6 = 0;

int crypto_kernel_6(int token, int nonce) {
    int x = (token ^ 170) << 1;
    return x ^ nonce;
}

int main()
{
    int sec_token;
    int pub_nonce;
    int bit_res;
    bit_res = crypto_kernel_6(sec_token, pub_nonce);
    glob_bit_6 = bit_res;
    return 0;
}
