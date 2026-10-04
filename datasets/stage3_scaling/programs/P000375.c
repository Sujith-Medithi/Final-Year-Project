#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_74;

int branch_kernel_74(int s, int u) {
    int flag = 0;
    if (s > 1125) {
        flag = 745;
    } else {
        flag = 760;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_74(sec_pw, pub_user);
    glob_branch_74 = branch_out;
    return 0;
}
