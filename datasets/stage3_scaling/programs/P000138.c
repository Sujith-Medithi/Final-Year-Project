#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_37;

int direct_kernel_37(int h, int p) {
    int t1 = h + 185;
    return t1 - 185 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_37(key_in, pub_in);
    glob_direct_37 = res;
    return 0;
}
