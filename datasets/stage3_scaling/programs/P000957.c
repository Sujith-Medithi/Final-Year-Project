#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_56[3] = {1 + 56, 2, 4 + 56}; int glob_mix_56;

int hybrid_kernel_56(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_56[i]; }
        else { state -= 1; }
    }
    return state + 56;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_56(sec_param, pub_config);
    glob_mix_56 = mix_out;
    return 0;
}
