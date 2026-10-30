#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_46;

int direct_kernel_46(int h, int p) {
    int t1 = h + 230;
    return t1 - 230 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_46(key_in, pub_in);
    glob_direct_46 = res;
    return 0;
}
