#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_36[3] = {1 + 36, 2, 4 + 36}; int glob_mix_36;

int hybrid_kernel_36(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_36[i]; }
        else { state -= 1; }
    }
    return state + 36;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_36(sec_param, pub_config);
    glob_mix_36 = mix_out;
    return 0;
}
