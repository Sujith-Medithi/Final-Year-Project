#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_3;

int branch_kernel_3(int s, int u) {
    int flag = 0;
    if (s > 60) {
        flag = 35;
    } else {
        flag = 50;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_3(sec_pw, pub_user);
    glob_branch_3 = branch_out;
    return 0;
}
