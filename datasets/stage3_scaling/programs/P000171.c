#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_70;

int direct_kernel_70(int h, int p) {
    int t1 = h + 350;
    return t1 - 350 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_70(key_in, pub_in);
    glob_direct_70 = res;
    return 0;
}
