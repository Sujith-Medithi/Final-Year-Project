#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_22;

int branch_kernel_22(int s, int u) {
    int flag = 0;
    if (s > 345) {
        flag = 225;
    } else {
        flag = 240;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_22(sec_pw, pub_user);
    glob_branch_22 = branch_out;
    return 0;
}
