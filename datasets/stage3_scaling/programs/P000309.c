#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_8;

int branch_kernel_8(int s, int u) {
    int flag = 0;
    if (s > 135) {
        flag = 85;
    } else {
        flag = 100;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_8(sec_pw, pub_user);
    glob_branch_8 = branch_out;
    return 0;
}
