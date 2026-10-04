#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_99;

int branch_kernel_99(int s, int u) {
    int flag = 0;
    if (s > 1500) {
        flag = 995;
    } else {
        flag = 1010;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_99(sec_pw, pub_user);
    glob_branch_99 = branch_out;
    return 0;
}
