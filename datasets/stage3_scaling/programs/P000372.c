#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_71;

int branch_kernel_71(int s, int u) {
    int flag = 0;
    if (s > 1080) {
        flag = 715;
    } else {
        flag = 730;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_71(sec_pw, pub_user);
    glob_branch_71 = branch_out;
    return 0;
}
