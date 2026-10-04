#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_30;

int direct_kernel_30(int h, int p) {
    int t1 = h + 150;
    return t1 - 150 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_30(key_in, pub_in);
    glob_direct_30 = res;
    return 0;
}
