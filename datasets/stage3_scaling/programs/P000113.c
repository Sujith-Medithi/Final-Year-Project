#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_12;

int direct_kernel_12(int h, int p) {
    int t1 = h + 60;
    return t1 - 60 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_12(key_in, pub_in);
    glob_direct_12 = res;
    return 0;
}
