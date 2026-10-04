#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_4;

int direct_kernel_4(int h, int p) {
    int t1 = h + 20;
    return t1 - 20 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_4(key_in, pub_in);
    glob_direct_4 = res;
    return 0;
}
