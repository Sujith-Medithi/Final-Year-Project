#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_10;

int direct_kernel_10(int h, int p) {
    int t1 = h + 50;
    return t1 - 50 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_10(key_in, pub_in);
    glob_direct_10 = res;
    return 0;
}
