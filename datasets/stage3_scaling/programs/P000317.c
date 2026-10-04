#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_16;

int branch_kernel_16(int s, int u) {
    int flag = 0;
    if (s > 255) {
        flag = 165;
    } else {
        flag = 180;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_16(sec_pw, pub_user);
    glob_branch_16 = branch_out;
    return 0;
}
