#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_49;

int branch_kernel_49(int s, int u) {
    int flag = 0;
    if (s > 750) {
        flag = 495;
    } else {
        flag = 510;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_49(sec_pw, pub_user);
    glob_branch_49 = branch_out;
    return 0;
}
