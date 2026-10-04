#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_11;

int branch_kernel_11(int s, int u) {
    int flag = 0;
    if (s > 180) {
        flag = 115;
    } else {
        flag = 130;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_11(sec_pw, pub_user);
    glob_branch_11 = branch_out;
    return 0;
}
