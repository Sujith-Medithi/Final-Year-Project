#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_66;

int branch_kernel_66(int s, int u) {
    int flag = 0;
    if (s > 1005) {
        flag = 665;
    } else {
        flag = 680;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_66(sec_pw, pub_user);
    glob_branch_66 = branch_out;
    return 0;
}
