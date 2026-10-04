#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_39;

int branch_kernel_39(int s, int u) {
    int flag = 0;
    if (s > 600) {
        flag = 395;
    } else {
        flag = 410;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_39(sec_pw, pub_user);
    glob_branch_39 = branch_out;
    return 0;
}
