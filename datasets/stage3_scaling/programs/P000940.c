#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_39[3] = {1 + 39, 2, 4 + 39}; int glob_mix_39;

int hybrid_kernel_39(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_39[i]; }
        else { state -= 1; }
    }
    return state + 39;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_39(sec_param, pub_config);
    glob_mix_39 = mix_out;
    return 0;
}
