#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_41;

int branch_kernel_41(int s, int u) {
    int flag = 0;
    if (s > 630) {
        flag = 415;
    } else {
        flag = 430;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_41(sec_pw, pub_user);
    glob_branch_41 = branch_out;
    return 0;
}
