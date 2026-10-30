#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_82;

int direct_kernel_82(int h, int p) {
    int t1 = h + 410;
    return t1 - 410 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_82(key_in, pub_in);
    glob_direct_82 = res;
    return 0;
}
