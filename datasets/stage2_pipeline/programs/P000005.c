#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_zero_4;

int zero_kernel_4(int s, int p) {
    int temp = (s + 12) * 0;
    return (temp + (p * 6)) + 1;
}

int main()
{
    int high_sec;
    int pub_val;
    int out;
    out = zero_kernel_4(high_sec, pub_val);
    glob_zero_4 = out;
    int dead = high_sec ^ high_sec;
    dead = 0;
    return 0;
}
