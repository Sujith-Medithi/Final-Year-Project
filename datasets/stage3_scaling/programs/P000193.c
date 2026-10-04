#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_92;

int direct_kernel_92(int h, int p) {
    int t1 = h + 460;
    return t1 - 460 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_92(key_in, pub_in);
    glob_direct_92 = res;
    return 0;
}
