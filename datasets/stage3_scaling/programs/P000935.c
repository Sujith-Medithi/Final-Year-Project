#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_34[3] = {1 + 34, 2, 4 + 34}; int glob_mix_34;

int hybrid_kernel_34(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_34[i]; }
        else { state -= 1; }
    }
    return state + 34;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_34(sec_param, pub_config);
    glob_mix_34 = mix_out;
    return 0;
}
