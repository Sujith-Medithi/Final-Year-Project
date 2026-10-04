#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_21;

int direct_kernel_21(int h, int p) {
    int t1 = h + 105;
    return t1 - 105 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_21(key_in, pub_in);
    glob_direct_21 = res;
    return 0;
}
