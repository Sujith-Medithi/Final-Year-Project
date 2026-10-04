#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_88[3] = {1 + 88, 2, 4 + 88}; int glob_mix_88;

int hybrid_kernel_88(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_88[i]; }
        else { state -= 1; }
    }
    return state + 88;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_88(sec_param, pub_config);
    glob_mix_88 = mix_out;
    return 0;
}
