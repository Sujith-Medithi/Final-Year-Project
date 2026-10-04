#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_70[3] = {1 + 70, 2, 4 + 70}; int glob_mix_70;

int hybrid_kernel_70(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_70[i]; }
        else { state -= 1; }
    }
    return state + 70;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_70(sec_param, pub_config);
    glob_mix_70 = mix_out;
    return 0;
}
