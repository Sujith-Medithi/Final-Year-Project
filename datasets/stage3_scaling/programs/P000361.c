#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_60;

int branch_kernel_60(int s, int u) {
    int flag = 0;
    if (s > 915) {
        flag = 605;
    } else {
        flag = 620;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_60(sec_pw, pub_user);
    glob_branch_60 = branch_out;
    return 0;
}
