#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_10[3] = {1, 2, 4}; int glob_mix_10 = 0;

int hybrid_kernel_10(int param, int config) {
    int state = config;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_10[i]; }
        else { state -= 1; }
    }
    return state;
}

int main()
{
    int sec_param;
    int pub_config;
    int final_st;
    final_st = hybrid_kernel_10(sec_param, pub_config);
    glob_mix_10 = final_st;
    return 0;
}
