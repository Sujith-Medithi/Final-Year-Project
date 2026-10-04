#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_19[3] = {1 + 19, 2, 4 + 19}; int glob_mix_19;

int hybrid_kernel_19(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_19[i]; }
        else { state -= 1; }
    }
    return state + 19;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_19(sec_param, pub_config);
    glob_mix_19 = mix_out;
    return 0;
}
