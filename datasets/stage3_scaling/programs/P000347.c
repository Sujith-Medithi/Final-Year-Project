#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_46;

int branch_kernel_46(int s, int u) {
    int flag = 0;
    if (s > 705) {
        flag = 465;
    } else {
        flag = 480;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_46(sec_pw, pub_user);
    glob_branch_46 = branch_out;
    return 0;
}
