#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_93;

int direct_kernel_93(int h, int p) {
    int t1 = h + 465;
    return t1 - 465 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_93(key_in, pub_in);
    glob_direct_93 = res;
    return 0;
}
