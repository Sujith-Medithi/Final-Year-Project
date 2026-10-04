#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_81;

int branch_kernel_81(int s, int u) {
    int flag = 0;
    if (s > 1230) {
        flag = 815;
    } else {
        flag = 830;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_81(sec_pw, pub_user);
    glob_branch_81 = branch_out;
    return 0;
}
