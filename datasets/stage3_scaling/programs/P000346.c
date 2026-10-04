#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_45;

int branch_kernel_45(int s, int u) {
    int flag = 0;
    if (s > 690) {
        flag = 455;
    } else {
        flag = 470;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_45(sec_pw, pub_user);
    glob_branch_45 = branch_out;
    return 0;
}
