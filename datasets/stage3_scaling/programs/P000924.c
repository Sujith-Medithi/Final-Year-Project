#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_23[3] = {1 + 23, 2, 4 + 23}; int glob_mix_23;

int hybrid_kernel_23(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_23[i]; }
        else { state -= 1; }
    }
    return state + 23;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_23(sec_param, pub_config);
    glob_mix_23 = mix_out;
    return 0;
}
