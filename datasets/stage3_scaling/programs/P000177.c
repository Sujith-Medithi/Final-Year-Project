#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_76;

int direct_kernel_76(int h, int p) {
    int t1 = h + 380;
    return t1 - 380 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_76(key_in, pub_in);
    glob_direct_76 = res;
    return 0;
}
