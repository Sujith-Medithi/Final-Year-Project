#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_6;

int branch_kernel_6(int s, int u) {
    int flag = 0;
    if (s > 105) {
        flag = 65;
    } else {
        flag = 80;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_6(sec_pw, pub_user);
    glob_branch_6 = branch_out;
    return 0;
}
