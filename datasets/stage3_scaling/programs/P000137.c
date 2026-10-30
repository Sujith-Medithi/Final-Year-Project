#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_36;

int direct_kernel_36(int h, int p) {
    int t1 = h + 180;
    return t1 - 180 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_36(key_in, pub_in);
    glob_direct_36 = res;
    return 0;
}
