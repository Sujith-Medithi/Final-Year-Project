#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_21;

int branch_kernel_21(int s, int u) {
    int flag = 0;
    if (s > 330) {
        flag = 215;
    } else {
        flag = 230;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_21(sec_pw, pub_user);
    glob_branch_21 = branch_out;
    return 0;
}
