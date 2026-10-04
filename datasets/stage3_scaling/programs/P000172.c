#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_71;

int direct_kernel_71(int h, int p) {
    int t1 = h + 355;
    return t1 - 355 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_71(key_in, pub_in);
    glob_direct_71 = res;
    return 0;
}
