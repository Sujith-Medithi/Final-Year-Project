#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_55;

int direct_kernel_55(int h, int p) {
    int t1 = h + 275;
    return t1 - 275 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_55(key_in, pub_in);
    glob_direct_55 = res;
    return 0;
}
