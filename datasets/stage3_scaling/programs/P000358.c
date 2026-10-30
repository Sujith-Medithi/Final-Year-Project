#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_57;

int branch_kernel_57(int s, int u) {
    int flag = 0;
    if (s > 870) {
        flag = 575;
    } else {
        flag = 590;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_57(sec_pw, pub_user);
    glob_branch_57 = branch_out;
    return 0;
}
