#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_50;

int direct_kernel_50(int h, int p) {
    int t1 = h + 250;
    return t1 - 250 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_50(key_in, pub_in);
    glob_direct_50 = res;
    return 0;
}
