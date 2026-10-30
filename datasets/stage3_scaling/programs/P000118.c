#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_17;

int direct_kernel_17(int h, int p) {
    int t1 = h + 85;
    return t1 - 85 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_17(key_in, pub_in);
    glob_direct_17 = res;
    return 0;
}
