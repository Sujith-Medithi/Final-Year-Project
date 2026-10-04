#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_zero_20;

int zero_kernel_20(int s, int p) {
    int temp = (s + 60) * 0;
    return (temp + (p * 22)) + 1;
}

int main()
{
    int high_sec;
    int pub_val;
    int out;
    out = zero_kernel_20(high_sec, pub_val);
    glob_zero_20 = out;
    int dead = high_sec ^ high_sec;
    dead = 0;
    return 0;
}
