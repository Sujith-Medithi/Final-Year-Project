#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_75;

int branch_kernel_75(int s, int u) {
    int flag = 0;
    if (s > 1140) {
        flag = 755;
    } else {
        flag = 770;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_75(sec_pw, pub_user);
    glob_branch_75 = branch_out;
    return 0;
}
