#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_58[3] = {1 + 58, 2, 4 + 58}; int glob_mix_58;

int hybrid_kernel_58(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_58[i]; }
        else { state -= 1; }
    }
    return state + 58;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_58(sec_param, pub_config);
    glob_mix_58 = mix_out;
    return 0;
}
