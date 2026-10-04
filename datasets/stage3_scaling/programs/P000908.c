#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_7[3] = {1 + 7, 2, 4 + 7}; int glob_mix_7;

int hybrid_kernel_7(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_7[i]; }
        else { state -= 1; }
    }
    return state + 7;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_7(sec_param, pub_config);
    glob_mix_7 = mix_out;
    return 0;
}
