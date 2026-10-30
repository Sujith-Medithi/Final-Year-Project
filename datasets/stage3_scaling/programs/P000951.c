#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_50[3] = {1 + 50, 2, 4 + 50}; int glob_mix_50;

int hybrid_kernel_50(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_50[i]; }
        else { state -= 1; }
    }
    return state + 50;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_50(sec_param, pub_config);
    glob_mix_50 = mix_out;
    return 0;
}
