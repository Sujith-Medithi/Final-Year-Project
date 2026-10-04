#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_19;

int branch_kernel_19(int s, int u) {
    int flag = 0;
    if (s > 300) {
        flag = 195;
    } else {
        flag = 210;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_19(sec_pw, pub_user);
    glob_branch_19 = branch_out;
    return 0;
}
