#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_99;

int direct_kernel_99(int h, int p) {
    int t1 = h + 495;
    return t1 - 495 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_99(key_in, pub_in);
    glob_direct_99 = res;
    return 0;
}
