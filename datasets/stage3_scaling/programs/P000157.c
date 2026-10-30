#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_56;

int direct_kernel_56(int h, int p) {
    int t1 = h + 280;
    return t1 - 280 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_56(key_in, pub_in);
    glob_direct_56 = res;
    return 0;
}
