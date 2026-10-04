#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_43[3] = {1 + 43, 2, 4 + 43}; int glob_mix_43;

int hybrid_kernel_43(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_43[i]; }
        else { state -= 1; }
    }
    return state + 43;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_43(sec_param, pub_config);
    glob_mix_43 = mix_out;
    return 0;
}
