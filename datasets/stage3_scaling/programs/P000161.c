#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_60;

int direct_kernel_60(int h, int p) {
    int t1 = h + 300;
    return t1 - 300 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_60(key_in, pub_in);
    glob_direct_60 = res;
    return 0;
}
