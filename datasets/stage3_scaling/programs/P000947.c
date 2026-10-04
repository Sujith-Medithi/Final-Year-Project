#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_46[3] = {1 + 46, 2, 4 + 46}; int glob_mix_46;

int hybrid_kernel_46(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_46[i]; }
        else { state -= 1; }
    }
    return state + 46;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_46(sec_param, pub_config);
    glob_mix_46 = mix_out;
    return 0;
}
