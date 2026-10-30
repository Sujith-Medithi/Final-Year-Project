#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_89;

int branch_kernel_89(int s, int u) {
    int flag = 0;
    if (s > 1350) {
        flag = 895;
    } else {
        flag = 910;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_89(sec_pw, pub_user);
    glob_branch_89 = branch_out;
    return 0;
}
