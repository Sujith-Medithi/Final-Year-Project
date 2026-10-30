#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_53[4] = {10 + 212, 25 + 53, 42, 99}; int glob_arr_53;

int table_kernel_53(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_53[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_53(sec_idx, pub_base);
    glob_arr_53 = arr_out;
    return 0;
}
