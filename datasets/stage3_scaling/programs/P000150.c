#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_49;

int direct_kernel_49(int h, int p) {
    int t1 = h + 245;
    return t1 - 245 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_49(key_in, pub_in);
    glob_direct_49 = res;
    return 0;
}
