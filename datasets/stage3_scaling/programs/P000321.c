#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_20;

int branch_kernel_20(int s, int u) {
    int flag = 0;
    if (s > 315) {
        flag = 205;
    } else {
        flag = 220;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_20(sec_pw, pub_user);
    glob_branch_20 = branch_out;
    return 0;
}
