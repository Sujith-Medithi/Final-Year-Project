#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_bit_93;

int crypto_kernel_93(int tok, int n) {
    int x = (tok ^ 240) << 1;
    return x ^ n;
}

int main()
{
    int sec_token;
    int pub_nonce;
    int bit_out;
    bit_out = crypto_kernel_93(sec_token, pub_nonce);
    glob_bit_93 = bit_out;
    return 0;
}
