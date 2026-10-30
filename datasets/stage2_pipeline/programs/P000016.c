#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_0;

int branch_kernel_0(int s, int u) {
    int flag = 0;
    if (s > 15) {
        flag = 5;
    } else {
        flag = 20;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_0(sec_pw, pub_user);
    glob_branch_0 = branch_out;
    return 0;
}
