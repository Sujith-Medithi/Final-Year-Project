#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int g_sink = 0;

int security_kernel(int sec, int pub) {
    int mask = (sec ^ 0x3F) & 15;
    int acc = pub * 3;
    if (mask > 8) {
        acc += (mask * 2);
    } else {
        acc -= (mask + 1);
    }
    return acc;
}

int main()
{
    int secret_val;
    int public_val;
    __CPROVER_assume(public_val >= -1000 && public_val <= 1000);
    __CPROVER_assume(secret_val >= 0 && secret_val <= 255);
    int intermediate;
    intermediate = security_kernel(secret_val, public_val);
    int status = 0;
    status = status + 1;
    g_sink = intermediate + status;
    return 0;
}