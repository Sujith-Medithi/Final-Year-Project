#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_62;

int branch_kernel_62(int s, int u) {
    int flag = 0;
    if (s > 945) {
        flag = 625;
    } else {
        flag = 640;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_62(sec_pw, pub_user);
    glob_branch_62 = branch_out;
    return 0;
}
