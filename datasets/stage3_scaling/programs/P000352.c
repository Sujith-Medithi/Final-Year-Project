#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_51;

int branch_kernel_51(int s, int u) {
    int flag = 0;
    if (s > 780) {
        flag = 515;
    } else {
        flag = 530;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_51(sec_pw, pub_user);
    glob_branch_51 = branch_out;
    return 0;
}
