#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_bit_46;

int crypto_kernel_46(int tok, int n) {
    int x = (tok ^ 170) << 2;
    return x ^ n;
}

int main()
{
    int sec_token;
    int pub_nonce;
    int bit_out;
    bit_out = crypto_kernel_46(sec_token, pub_nonce);
    glob_bit_46 = bit_out;
    return 0;
}
