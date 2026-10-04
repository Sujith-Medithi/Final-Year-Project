#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_86;

int direct_kernel_86(int h, int p) {
    int t1 = h + 430;
    return t1 - 430 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_86(key_in, pub_in);
    glob_direct_86 = res;
    return 0;
}
