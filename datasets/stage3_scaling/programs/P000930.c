#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_29[3] = {1 + 29, 2, 4 + 29}; int glob_mix_29;

int hybrid_kernel_29(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_29[i]; }
        else { state -= 1; }
    }
    return state + 29;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_29(sec_param, pub_config);
    glob_mix_29 = mix_out;
    return 0;
}
