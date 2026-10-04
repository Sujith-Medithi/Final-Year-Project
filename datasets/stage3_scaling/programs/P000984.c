#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_83[3] = {1 + 83, 2, 4 + 83}; int glob_mix_83;

int hybrid_kernel_83(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_83[i]; }
        else { state -= 1; }
    }
    return state + 83;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_83(sec_param, pub_config);
    glob_mix_83 = mix_out;
    return 0;
}
