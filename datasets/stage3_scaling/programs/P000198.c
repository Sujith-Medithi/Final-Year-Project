#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_97;

int direct_kernel_97(int h, int p) {
    int t1 = h + 485;
    return t1 - 485 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_97(key_in, pub_in);
    glob_direct_97 = res;
    return 0;
}
