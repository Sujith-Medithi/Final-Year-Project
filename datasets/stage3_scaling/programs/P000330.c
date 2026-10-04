#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_29;

int branch_kernel_29(int s, int u) {
    int flag = 0;
    if (s > 450) {
        flag = 295;
    } else {
        flag = 310;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_29(sec_pw, pub_user);
    glob_branch_29 = branch_out;
    return 0;
}
