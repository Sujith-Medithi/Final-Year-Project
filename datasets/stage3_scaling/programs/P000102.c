#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_1;

int direct_kernel_1(int h, int p) {
    int t1 = h + 5;
    return t1 - 5 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_1(key_in, pub_in);
    glob_direct_1 = res;
    return 0;
}
