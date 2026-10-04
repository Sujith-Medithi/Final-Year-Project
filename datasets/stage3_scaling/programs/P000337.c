#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_36;

int branch_kernel_36(int s, int u) {
    int flag = 0;
    if (s > 555) {
        flag = 365;
    } else {
        flag = 380;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_36(sec_pw, pub_user);
    glob_branch_36 = branch_out;
    return 0;
}
