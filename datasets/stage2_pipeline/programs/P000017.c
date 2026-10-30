#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_1;

int branch_kernel_1(int s, int u) {
    int flag = 0;
    if (s > 30) {
        flag = 15;
    } else {
        flag = 30;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_1(sec_pw, pub_user);
    glob_branch_1 = branch_out;
    return 0;
}
