#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_91;

int direct_kernel_91(int h, int p) {
    int t1 = h + 455;
    return t1 - 455 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_91(key_in, pub_in);
    glob_direct_91 = res;
    return 0;
}
