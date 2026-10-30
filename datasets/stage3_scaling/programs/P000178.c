#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_77;

int direct_kernel_77(int h, int p) {
    int t1 = h + 385;
    return t1 - 385 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_77(key_in, pub_in);
    glob_direct_77 = res;
    return 0;
}
