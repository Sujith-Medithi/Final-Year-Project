#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_87;

int direct_kernel_87(int h, int p) {
    int t1 = h + 435;
    return t1 - 435 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_87(key_in, pub_in);
    glob_direct_87 = res;
    return 0;
}
