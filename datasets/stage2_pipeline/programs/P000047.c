#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_1[3] = {1 + 1, 2, 4 + 1}; int glob_mix_1;

int hybrid_kernel_1(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_1[i]; }
        else { state -= 1; }
    }
    return state + 1;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_1(sec_param, pub_config);
    glob_mix_1 = mix_out;
    return 0;
}
