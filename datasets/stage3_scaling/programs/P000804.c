#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_3[4] = {10 + 12, 25 + 3, 42, 99}; int glob_arr_3;

int table_kernel_3(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_3[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_3(sec_idx, pub_base);
    glob_arr_3 = arr_out;
    return 0;
}
