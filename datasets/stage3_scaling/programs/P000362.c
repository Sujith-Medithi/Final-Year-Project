#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_61;

int branch_kernel_61(int s, int u) {
    int flag = 0;
    if (s > 930) {
        flag = 615;
    } else {
        flag = 630;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_61(sec_pw, pub_user);
    glob_branch_61 = branch_out;
    return 0;
}
