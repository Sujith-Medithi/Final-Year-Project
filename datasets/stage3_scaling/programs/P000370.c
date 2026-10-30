#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_69;

int branch_kernel_69(int s, int u) {
    int flag = 0;
    if (s > 1050) {
        flag = 695;
    } else {
        flag = 710;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_69(sec_pw, pub_user);
    glob_branch_69 = branch_out;
    return 0;
}
