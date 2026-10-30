#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_45;

int direct_kernel_45(int h, int p) {
    int t1 = h + 225;
    return t1 - 225 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_45(key_in, pub_in);
    glob_direct_45 = res;
    return 0;
}
