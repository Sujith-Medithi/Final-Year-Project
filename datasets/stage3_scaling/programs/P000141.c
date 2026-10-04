#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_40;

int direct_kernel_40(int h, int p) {
    int t1 = h + 200;
    return t1 - 200 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_40(key_in, pub_in);
    glob_direct_40 = res;
    return 0;
}
