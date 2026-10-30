#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_bit_50;

int crypto_kernel_50(int tok, int n) {
    int x = (tok ^ 85) << 3;
    return x ^ n;
}

int main()
{
    int sec_token;
    int pub_nonce;
    int bit_out;
    bit_out = crypto_kernel_50(sec_token, pub_nonce);
    glob_bit_50 = bit_out;
    return 0;
}
