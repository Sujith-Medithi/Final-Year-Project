#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_28;

int branch_kernel_28(int s, int u) {
    int flag = 0;
    if (s > 435) {
        flag = 285;
    } else {
        flag = 300;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_28(sec_pw, pub_user);
    glob_branch_28 = branch_out;
    return 0;
}
