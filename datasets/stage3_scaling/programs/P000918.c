#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_17[3] = {1 + 17, 2, 4 + 17}; int glob_mix_17;

int hybrid_kernel_17(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_17[i]; }
        else { state -= 1; }
    }
    return state + 17;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_17(sec_param, pub_config);
    glob_mix_17 = mix_out;
    return 0;
}
