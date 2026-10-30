#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_cancel_12 = 0;

int cancel_kernel_12(int pin, int mode) {
    int zero = pin ^ pin;
    return zero + mode * 5;
}

int main()
{
    int sec_pin;
    int pub_mode;
    int verified_zero;
    verified_zero = cancel_kernel_12(sec_pin, pub_mode);
    glob_cancel_12 = verified_zero;
    return 0;
}
