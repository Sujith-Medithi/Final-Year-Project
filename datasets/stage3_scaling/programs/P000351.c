#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_50;

int branch_kernel_50(int s, int u) {
    int flag = 0;
    if (s > 765) {
        flag = 505;
    } else {
        flag = 520;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_50(sec_pw, pub_user);
    glob_branch_50 = branch_out;
    return 0;
}
