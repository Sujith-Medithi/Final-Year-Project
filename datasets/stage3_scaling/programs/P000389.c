#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_88;

int branch_kernel_88(int s, int u) {
    int flag = 0;
    if (s > 1335) {
        flag = 885;
    } else {
        flag = 900;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_88(sec_pw, pub_user);
    glob_branch_88 = branch_out;
    return 0;
}
