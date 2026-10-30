#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_6[3] = {1 + 6, 2, 4 + 6}; int glob_mix_6;

int hybrid_kernel_6(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_6[i]; }
        else { state -= 1; }
    }
    return state + 6;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_6(sec_param, pub_config);
    glob_mix_6 = mix_out;
    return 0;
}
