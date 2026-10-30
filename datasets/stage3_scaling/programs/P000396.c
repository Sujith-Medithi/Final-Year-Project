#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_95;

int branch_kernel_95(int s, int u) {
    int flag = 0;
    if (s > 1440) {
        flag = 955;
    } else {
        flag = 970;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_95(sec_pw, pub_user);
    glob_branch_95 = branch_out;
    return 0;
}
