#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_2;

int branch_kernel_2(int s, int u) {
    int flag = 0;
    if (s > 45) {
        flag = 25;
    } else {
        flag = 40;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_2(sec_pw, pub_user);
    glob_branch_2 = branch_out;
    return 0;
}
