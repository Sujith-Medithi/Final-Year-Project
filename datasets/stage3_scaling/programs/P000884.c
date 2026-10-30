#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_83[4] = {10 + 332, 25 + 83, 42, 99}; int glob_arr_83;

int table_kernel_83(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_83[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_83(sec_idx, pub_base);
    glob_arr_83 = arr_out;
    return 0;
}
