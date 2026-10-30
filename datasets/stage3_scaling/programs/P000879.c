#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_78[4] = {10 + 312, 25 + 78, 42, 99}; int glob_arr_78;

int table_kernel_78(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_78[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_78(sec_idx, pub_base);
    glob_arr_78 = arr_out;
    return 0;
}
