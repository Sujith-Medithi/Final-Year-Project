#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_98;

int branch_kernel_98(int s, int u) {
    int flag = 0;
    if (s > 1485) {
        flag = 985;
    } else {
        flag = 1000;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_98(sec_pw, pub_user);
    glob_branch_98 = branch_out;
    return 0;
}
