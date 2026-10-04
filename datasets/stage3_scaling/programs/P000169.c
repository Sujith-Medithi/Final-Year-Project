#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_68;

int direct_kernel_68(int h, int p) {
    int t1 = h + 340;
    return t1 - 340 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_68(key_in, pub_in);
    glob_direct_68 = res;
    return 0;
}
