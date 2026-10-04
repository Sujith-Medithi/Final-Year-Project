#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_zero_2;

int zero_kernel_2(int s, int p) {
    int temp = (s + 6) * 0;
    return (temp + (p * 4)) + 1;
}

int main()
{
    int high_sec;
    int pub_val;
    int out;
    out = zero_kernel_2(high_sec, pub_val);
    glob_zero_2 = out;
    int dead = high_sec ^ high_sec;
    dead = 0;
    return 0;
}
