#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_94;

int direct_kernel_94(int h, int p) {
    int t1 = h + 470;
    return t1 - 470 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_94(key_in, pub_in);
    glob_direct_94 = res;
    return 0;
}
